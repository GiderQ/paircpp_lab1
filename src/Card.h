#ifndef CARD_H
#define CARD_H

#include <compare>

struct Card
{
    long long suit, rank;

    auto operator<=>(const Card& rhs) const {
        return rank <=> rhs.rank;
    }
};

#endif // CARD_H