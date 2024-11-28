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
  const partitionless::token_version_t version;
  const std::string client_id;
  const std::string key;
  const partitionless::time_point_t timestamp;
  const std::string signature;
};
} // namespace partitionless
