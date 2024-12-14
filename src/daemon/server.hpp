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
class server : public partitionless::rpc::PublicGateway::Service {
public:
  server(std::string address);
  void run();
  void pause();
  void halt();

private:
  grpc::Status Authorize(grpc::ServerContext *context, const partitionless::rpc::AuthorizationRequest *request,
                         partitionless::rpc::AuthorizationToken *response) override;

private:
  std::unique_ptr<grpc::Server> m_server;
  std::string m_address;
};
} // namespace partitionless
