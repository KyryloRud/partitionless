// Copyright (c) 2024 Kyrylo Rud
// All rights reserved.
//
// Licensed under the Partitionless License (Version 1.0).
// See the LICENSE file in the project root or contact Kyrylo Rud
// at <krud.official@gmail.com> for details.

#pragma once

#include "partitionless.grpc.pb.h"
#include <grpcpp/grpcpp.h>

namespace partitionless {
class server : public partitionless::rpc::public_gateway::Service {
public:
  server(std::string address);
  void run();

private:
  grpc::Status authorize(grpc::ServerContext *context, const partitionless::rpc::register_request *request,
                         partitionless::rpc::authorization_token *response);

private:
  std::unique_ptr<grpc::Server> m_server;
  std::string m_address;
};
} // namespace partitionless
