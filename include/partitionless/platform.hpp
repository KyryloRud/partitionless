// Copyright (c) 2024 Kyrylo Rud
// All rights reserved.
//
// Licensed under the Partitionless License (Version 1.0).
// See the LICENSE file in the project root or contact Kyrylo Rud
// at <krud.official@gmail.com> for details.

#pragma once

#ifdef __linux__
#include <sys/types.h>
#else
#include <cstdint>
using uid_t = std::uint32_t;
using gid_t = std::uint32_t;
#endif
