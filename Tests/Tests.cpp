#include <catch2/catch_test_macros.hpp>
#include "CopyOnWrite/CopyOnWrite.h"

TEST_CASE("Test Instantiating COW")
{
    auto cow = EA::makeCOW<int>(23);

    REQUIRE(*cow == 23);
}
