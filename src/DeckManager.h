#ifndef DeckManager_h
#define DeckManager_h

#include "Card.h"
#include <random>
#include <vector>

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

#endif // DeckManager_h