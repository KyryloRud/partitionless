// Copyright (c) 2024 Kyrylo Rud
// All rights reserved.
//
// Licensed under the Partitionless License (Version 1.0).
// See the LICENSE file in the project root or contact Kyrylo Rud
// at <krud.official@gmail.com> for details.

#pragma once

#include <chrono>
#include <cstdint>
#include <string>

namespace partitionless {
using token_version_t = std::int32_t;
using time_point_t = std::chrono::time_point<std::chrono::system_clock>;

struct authorization_token {
  partitionless::token_version_t version;
  std::string client_id;
  std::string key;
  partitionless::time_point_t timestamp;
  std::string signature;
};
} // namespace partitionless
