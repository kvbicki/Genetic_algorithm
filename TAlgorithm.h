#pragma once
#include <string>
#include <vector>
#include "TPopulation.h"

class TAlgorithm
{
private:
    unsigned int candidates_count;
    unsigned int max_population_count;
    unsigned int min_improvment_proc;
    unsigned int pop_check = 5;
    std::vector<TPopulation*> wczesniejsze;
    std::vector<double> wczesniejsze_rate;

public:
    TAlgorithm(unsigned int candidates_count,unsigned int max_population_count,unsigned int min_improvment_proc);
    void run();
    bool check();
};