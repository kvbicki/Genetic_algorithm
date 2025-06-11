// #pragma once
// #include <string>
// #include <vector>
// #include <algorithm>
// #include "TCandidate.h"
// #include "TCandidate_Zad1.h"
// #include "TCandidate_Zad2.h"

// class TPopulation
// {
// private:
//     unsigned int candidates_count;
//     std::vector<TCandidate> candidates;
//     double best_val;
//     static unsigned int _id;
//     unsigned int id;
//     TCandidate BestCandidate;
//     double rate_sum = 0;
// public:
//     TPopulation(unsigned int candidates_count);
//     TPopulation(TPopulation* older);
//     void calculate();
//     void info();
//     TCandidate get_best_candidate();
//     TCandidate* promote_candidate();
//     void cross(TCandidate* can1, TCandidate* can2);
// 	std::string mutation(std::string old_binary);
//     std::string get_mark(TCandidate);
//     double get_best_rate();
//     unsigned int get_candidates_count();
//     void test(int num_testing);
//     unsigned int get_id();

// };