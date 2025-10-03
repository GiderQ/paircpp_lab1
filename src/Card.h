#ifndef Card_h
#define Card_h

#include <compare>

struct Card
{
    long long suit, rank;

    auto operator<=>(const Card& rhs) const {
        return rank <=> rhs.rank;
    }
};

#endif