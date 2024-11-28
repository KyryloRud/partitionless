// Copyright (c) 2024 Kyrylo Rud
// All rights reserved.
//
// Licensed under the Partitionless License (Version 1.0).
// See the LICENSE file in the project root or contact Kyrylo Rud
// at <krud.official@gmail.com> for details.

#pragma once

#include <stdexcept>

namespace partitionless {
enum partitionless_error_type {
  registration_not_permitted,
  forbidden_user_id,
  forbidden_group_id,
  authentication_token_limit_reached,
};

class partitionless_error : public std::runtime_error {
public:
  partitionless::partitionless_error_type type() const;
};
} // namespace partitionless
