// Copyright (c) 2024 Kyrylo Rud
// All rights reserved.
//
// Licensed under the Partitionless License (Version 1.0).
// See the LICENSE file in the project root or contact Kyrylo Rud
// at <krud.official@gmail.com> for details.

#include "server.hpp"
#include <iostream>

int main() {
  std::cout << "partitionlessd" << std::endl;
  auto server = partitionless::server("localhost:3535");
  server.run();
  return 0;
}