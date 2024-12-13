// Copyright (c) 2024 Kyrylo Rud
// All rights reserved.
//
// Licensed under the Partitionless License (Version 1.0).
// See the LICENSE file in the project root or contact Kyrylo Rud
// at <krud.official@gmail.com> for details.

#include "server.hpp"

#include <boost/asio/post.hpp>
#include <boost/asio/signal_set.hpp>
#include <boost/asio/thread_pool.hpp>
#include <iostream>
#include <memory>

int main() {
  std::cout << "partitionlessd" << std::endl;

  auto server_ptr = std::make_shared<partitionless::server>("localhost:3535");
  auto thread_pool = boost::asio::thread_pool{3};
  auto &thread_pool_ctx = thread_pool.get_executor().context();
  auto signals = boost::asio::signal_set(thread_pool_ctx, SIGINT, SIGTERM);

  signals.async_wait([&thread_pool, &thread_pool_ctx, server_ptr](const auto &error_code, auto signal_number) {
    if (error_code != boost::system::errc::success) {
      return;
    }

    boost::asio::post(thread_pool, [&thread_pool_ctx, server_ptr, signal_number]() {
      if (signal_number == SIGINT) {
        server_ptr->pause();
      }

      server_ptr->halt();

      thread_pool_ctx.stop();
    });
  });

  boost::asio::post(thread_pool, [server_ptr]() { server_ptr->run(); });

  thread_pool.attach();
  thread_pool.join();

  return 0;
}