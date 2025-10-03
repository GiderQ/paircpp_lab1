#ifndef STATS_H
#define STATS_H

#include <vector>
#include <map>

struct Statistics {
    int totalStacks;
    std::map<int, int> frequency;
    int mode;
    double average;
    double median;
};

Statistics computeStatistics(const std::vector<int>& stackLengths);
void printStatistics(const Statistics& stats);

#endif