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
    static unsigned int _id;
    TCandidate BestCandidate;
    double rate_sum = 0;
public:
    TPopulation(unsigned int candidates_count);
    void calculate();
    void info();
    void alg_info();
    TCandidate best();
    TCandidate* promote_candidate();
    std::string get_mark(TCandidate);
    double best_rate();
};