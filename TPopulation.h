#pragma once
#include <string>
#include <vector>
#include "TCandidate.h"

class TPopulation
{
private:
    unsigned int candidates_count;
    std::vector<TCandidate> candidates;
    double best_val;
public:
    TPopulation(unsigned int candidates_count);
    void calculate();
    void info();
};