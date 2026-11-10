#include "card.hpp"

#include <cctype>

namespace poker {
    namespace {
        constexpr std::string_view kRankChars = "23456789TJQKA";
        constexpr std::string_view kSuitChars = "cdhs";
    }

    std::optional<Card> parse_card(std::string_view s) {
        if (s.size() != 2) {
            return std::nullopt;
        }
        const char r = static_cast<char>(std::toupper(static_cast<unsigned char>(s[0])));
        const char su = static_cast<char>(std::tolower(static_cast<unsigned char>(s[1])));

        const auto rank = kRankChars.find(r);
        const auto suit = kSuitChars.find(su);
        if (rank == std::string_view::npos || suit == std::string_view::npos) {
            return std::nullopt;
        }
        return make_card(static_cast<int>(rank), static_cast<int>(suit));
    }

    std::string to_string(Card c) {
        return {kRankChars[rank_of(c)], kSuitChars[suit_of(c)]};
    }
}
