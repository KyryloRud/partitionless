// Copyright (c) 2024 Kyrylo Rud
// All rights reserved.
//
// Licensed under the Partitionless License (Version 1.0).
// See the LICENSE file in the project root or contact Kyrylo Rud
// at <krud.official@gmail.com> for details.

#include <iostream>
#include <partitionless.hpp>

int main() {
  std::cout << "partitionless cli" << std::endl;

  try {
    auto token = partitionless::authorize("partitionless-cli");

    auto tp = std::chrono::system_clock::to_time_t(token.timestamp);

    std::cout << "version:   " << token.version << std::endl;
    std::cout << "client id: " << token.client_id << std::endl;
    std::cout << "key:       " << token.key << std::endl;
    std::cout << "timestamp: " << std::ctime(&tp);
    std::cout << "signature: " << token.signature << std::endl;
  } catch (const std::runtime_error &ex) {
    std::cout << "error: " << ex.what() << std::endl;
    return 1;
  }

  return 0;
}
