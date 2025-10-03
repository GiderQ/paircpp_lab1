#include "Stats.h"
#include <iostream>
#include <iomanip>
#include <algorithm>

Statistics computeStatistics(const std::vector<int>& stackLengths) {
    Statistics stats{};
    stats.totalStacks = static_cast<int>(stackLengths.size());

    for (int v : stackLengths) {
        stats.frequency[v]++;
    }

    stats.mode = stackLengths[0];
    int maxCount = stats.frequency[stats.mode];
    for (auto& p : stats.frequency) {
        if (p.second > maxCount) {
            maxCount = p.second;
            stats.mode = p.first;
        }
    }

    int totalCards = 0;
    for (int v : stackLengths) totalCards += v;
    stats.average = static_cast<double>(totalCards) / stats.totalStacks;

    // Median
    std::vector<int> sorted = stackLengths;
    std::sort(sorted.begin(), sorted.end());
    if (stats.totalStacks % 2 == 1) {
        stats.median = sorted[stats.totalStacks / 2];
    } else {
        stats.median = (sorted[stats.totalStacks / 2 - 1] + sorted[stats.totalStacks / 2]) / 2.0;
    }

    return stats;
}

void printStatistics(const Statistics& stats) {
    std::cout << "\n--- Statistics ---\n";
    std::cout << "Total stacks: " << stats.totalStacks << "\n";

    std::cout << std::fixed << std::setprecision(3);

    for (auto& p : stats.frequency) {
        double perc = (100.0 * p.second) / stats.totalStacks;
        std::cout << "Length " << p.first << " -> " << perc << "%\n";
    }

    std::cout << "Most common length: " << stats.mode << "\n";
    std::cout << "Average length: " << stats.average << "\n";
    std::cout << "Median length: " << stats.median << "\n";
}
