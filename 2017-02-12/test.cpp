#define CATCH_CONFIG_MAIN
#include "catch.hpp"

TEST_CASE("a") {
        CHECK_THROWS(throw 3);
}

TEST_CASE("b") {
        int i = 0;
            SECTION("a") { i = 1; }
                SECTION("b") { i = 2; REQUIRE(i == 2); }
                    CHECK(i > 0);
}
