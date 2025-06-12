#pragma once
#include <string>
#include <vector>
#include <algorithm>
#include "TCandidate.h"
#include "TCandidate_Zad1.h"
#include "TCandidate_Zad2.h"
#include "TCandidate_Zad3.h"

class TPopulation
{
private:
    unsigned int candidates_count;
    std::vector<TCandidate*> candidates;
    double best_val;
    static unsigned int _id;
    unsigned int id;
    TCandidate* BestCandidate;
    double rate_sum = 0;

public:
    TPopulation(unsigned int candidates_count, TCandidate* pattern);
    TPopulation(const TPopulation &orignal);
    ~TPopulation();

    void calculate();
    void info();

    TCandidate* get_best_candidate();
    TCandidate* promote_candidate() const;
    void cross(TCandidate* can1, TCandidate* can2);
	std::string mutation(std::string old_binary);
    // std::string get_mark(TCandidate);

    double get_best_rate() const;
    unsigned int get_candidates_count() const;
    void test(int num_testing);
    unsigned int get_id();
    void set_id(unsigned int id) { this->id = id; }
};
