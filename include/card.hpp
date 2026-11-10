#pragma once

#include <cstdint>
#include <optional>
#include <string>
#include <string_view>

namespace poker {
    //card indexes ranked 0 - 51, encoded as rank * 4 + suit;
    //rank: 0 - 12 suit 0 - 3 c, d, h, s
    using Card = std::uint8_t;

    //Set of cards: bit c is set if card c is present
    using CardMask = std::uint64_t;

    inline constexpr int kNumRanks = 13;
    inline constexpr int kNumSuits = 4;
    inline constexpr int kNumCards = 52;

    constexpr Card make_card(int rank, int suit) {
        return static_cast<Card>(rank * 4 + suit);
    }

    constexpr int rank_of(Card c) { return c >> 2; }
    constexpr int suit_of(Card c) { return c & 3; }

    constexpr CardMask to_mask(Card c) { return CardMask{1} << c; }

    // "Ah" -> card; returns std::nullopt for anything invalid
    std::optional<Card> parse_card(std::string_view s);

    // card -> "Ah"
    std::string to_string(Card c);
}
