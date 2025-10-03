#include <iostream>
#include "DeckManager.h"
#include "Stats.h"

int main() {
    int numSuits;
    std::cout << "Enter num suits: ";
    std::cin >> numSuits;

    if (numSuits <= 0) {
        std::cout << "\nTry again\n";
        return 0;
    }

    const int cardsPerSuit = 13;
    int numCards = numSuits * cardsPerSuit;

    DeckManager deck(numSuits);
    std::vector<int> stackLengths;

    int currentStackLength = 0;
    Card previousCard{ -1, -1 };

    for (int i = 0; i < numCards; ++i) {
        Card c = deck();

        std::cout << "Card " << i + 1 << ": suit=" << c.suit +1
                  << ", rank=" << c.rank +1 << "\n";

        if (previousCard.rank == -1 || c.rank >= previousCard.rank) {
            ++currentStackLength;
        } else {
            stackLengths.push_back(currentStackLength);
            currentStackLength = 1;
        }

        previousCard = c;
    }

    if (currentStackLength > 0) {
        stackLengths.push_back(currentStackLength);
    }

    std::cout << "\nStack lengths:\n";
    for (size_t i = 0; i < stackLengths.size(); ++i) {
        std::cout << "Stack " << i + 1 << ": " << stackLengths[i] << "\n";
    }

    if (stackLengths.empty()) {
        std::cout << "\nNo values to analyze.\n";
        return 0;
    }

    Statistics stats = computeStatistics(stackLengths);
    printStatistics(stats);

    return 0;
}
