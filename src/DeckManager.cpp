#include "DeckManager.h"
#include <algorithm>

DeckManager::DeckManager(int suits)
    : randomGenerator(std::random_device{}()), currentIndex(0), numSuits(suits) {
    GenerateDeck();
    ShuffleDeck();
}

void DeckManager::GenerateDeck() {
    for (int s = 0; s < numSuits; ++s) {
        for (int r = 0; r < RanksCount; ++r) {
            deck.push_back({ s, r });
        }
    }
}

void DeckManager::ShuffleDeck() {
    currentIndex = 0;
    std::shuffle(deck.begin(), deck.end(), randomGenerator);
}

Card DeckManager::operator()() {
    if (currentIndex >= deck.size()) {
        ShuffleDeck();
        currentIndex = 0;
    }
    return deck[currentIndex++];
}