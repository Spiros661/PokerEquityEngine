#include <catch2/catch_test_macros.hpp>

#include "card.hpp"

TEST_CASE("parse_card: known cards map to the right index") {
    REQUIRE(poker::parse_card("2c") == poker::Card{0});
    REQUIRE(poker::parse_card("Ah") == poker::Card{50});
}

TEST_CASE("parse_card and to_string round-trip for all 52 cards") {
    for (int i = 0; i < poker::kNumCards; ++i) {
        const auto c = static_cast<poker::Card>(i);
        INFO("card index " << i << " = " << poker::to_string(c));
        REQUIRE(poker::parse_card(poker::to_string(c)) == c);
    }
}
