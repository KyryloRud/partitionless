// Copyright (c) 2024 Kyrylo Rud
// All rights reserved.
//
// Licensed under the Partitionless License (Version 1.0).
// See the LICENSE file in the project root or contact Kyrylo Rud
// at <krud.official@gmail.com> for details.

#include <partitionless/authorization.hpp>

namespace partitionless {
partitionless::authorization_token authorize(std::string_view /*client_id*/) { return {}; }
} // namespace partitionless
