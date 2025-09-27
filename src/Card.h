#pragma once

#include <compare>

struct Card
{
    int num;
    int suit;
    
    auto operator <=> (const Card& rhs) const {
        return number <=> rhs.num;
    }
};

