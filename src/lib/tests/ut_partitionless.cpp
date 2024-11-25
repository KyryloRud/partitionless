// Copyright (c) 2024 Kyrylo Rud
// All rights reserved.
//
// Licensed under the Partitionless License (Version 1.0).
// See the LICENSE file in the project root or contact Kyrylo Rud
// at <krud.official@gmail.com> for details.

#include <gtest/gtest.h>
#include <partitionless.hpp>

TEST(partitionless_lib, connect)
{
    EXPECT_NO_THROW({ partitionless::connect(); });
}
