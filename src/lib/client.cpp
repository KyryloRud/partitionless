// Copyright (c) 2024 Kyrylo Rud
// All rights reserved.
//
// Licensed under the Partitionless License (Version 1.0).
// See the LICENSE file in the project root or contact Kyrylo Rud
// at <krud.official@gmail.com> for details.

#include "client.hpp"

#include "partitionless.grpc.pb.h"
#include <grpcpp/grpcpp.h>

namespace partitionless {
client::client(std::string address) : m_address(std::move(address)) {}

partitionless::authorization_token client::authorize(std::string_view client_id) {
  auto channel = grpc::CreateChannel("localhost:3535", grpc::InsecureChannelCredentials());
  auto stub = partitionless::rpc::public_gateway::NewStub(channel);
  partitionless::rpc::register_request request;
  request.set_client_id(std::string{client_id});
  partitionless::rpc::authorization_token reply;
  grpc::ClientContext context;
  grpc::Status status = stub->authorize(&context, request, &reply);

  if (status.ok() == false) {
    throw std::runtime_error("cannot execute request");
  }

  return partitionless::authorization_token{
      .version = reply.version(),
      .client_id = reply.client_id(),
      .key = reply.key(),
      .timestamp = std::chrono::time_point<std::chrono::system_clock>(std::chrono::seconds(reply.timestamp())),
      .signature = reply.signature()};
}
} // namespace partitionless