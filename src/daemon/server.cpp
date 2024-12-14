// Copyright (c) 2024 Kyrylo Rud
// All rights reserved.
//
// Licensed under the Partitionless License (Version 1.0).
// See the LICENSE file in the project root or contact Kyrylo Rud
// at <krud.official@gmail.com> for details.

#include "server.hpp"

#include <chrono>
#include <iostream>

namespace partitionless {
server::server(std::string address) : m_server(nullptr), m_address(std::move(address)) {}

void server::run() {
  grpc::ServerBuilder builder;
  builder.AddListeningPort(m_address, grpc::InsecureServerCredentials());
  builder.RegisterService(this);

  m_server = std::unique_ptr<grpc::Server>(builder.BuildAndStart());

  std::cout << "server listening on " << m_address << std::endl;
  m_server->Wait();
  std::cout << "server is no longer listening" << std::endl;
}

void server::pause() { std::cout << "server is not processing new events anymore" << std::endl; }

void server::halt() { m_server->Shutdown(); }

grpc::Status server::Authorize(grpc::ServerContext * /*context*/,
                               const partitionless::rpc::AuthorizationRequest *request,
                               partitionless::rpc::AuthorizationToken *response) {
  std::cout << "processing authorization..." << std::endl;
  response->set_version(1);
  response->set_client_id(request->client_id());
  response->set_key("secret-key");
  response->set_timestamp(
      std::chrono::duration_cast<std::chrono::seconds>(std::chrono::system_clock::now().time_since_epoch()).count());
  response->set_signature("signature");

  return grpc::Status::OK;
}
} // namespace partitionless
