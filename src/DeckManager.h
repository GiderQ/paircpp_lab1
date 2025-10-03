#ifndef DECKMANAGER_H
#define DECKMANAGER_H

#include "Card.h"
#include <vector>
#include <random>

class DeckManager {
private:
    static constexpr int RanksCount = 13;
    int numSuits;

    std::vector<Card> deck;
    std::mt19937 randomGenerator;
    size_t currentIndex = 0;

    void ShuffleDeck();
    void GenerateDeck();

public:
    DeckManager(int suits);
    Card operator()();
};

#endif // DECKMANAGER_H
