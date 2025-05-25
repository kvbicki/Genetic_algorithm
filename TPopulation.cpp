#include <iostream>
#include <math.h>
#include <cstdlib>
#include "TPopulation.h"

using namespace std; 

unsigned int TPopulation::_id = 0;

TPopulation::TPopulation(unsigned int candidates_count)
{
    this->candidates_count = candidates_count;
    _id++;
}
void TPopulation::info() 
{

    cout << "===================="<<endl;
    cout << "Populacja: " << _id << endl;
    for(int i = 0; i < candidates_count;i++)
    {
        cout << "candidate#" << candidates[i].get_id() << ": " << candidates[i].give_rate() << endl;
    }
    
}
void TPopulation::calculate()
{
    for(int i = 0; i < candidates_count; i++)
    {
        TCandidate Tc;
        Tc.calc_rate();
        candidates.push_back(Tc);
        rate_sum = rate_sum + candidates[i].give_rate();
        if(best_val < candidates[i].give_rate())
        {
            best_val = candidates[i].give_rate();
            BestCandidate = candidates[i];
        }
    }
    
}

TCandidate TPopulation::best()
{
    return BestCandidate;
}

void TPopulation::alg_info()
{
    cout<< "== Population #"<< _id << "|| best val: "<< BestCandidate.give_rate() << endl;

}
double TPopulation::best_rate()
{
    return BestCandidate.give_rate();
}
TCandidate* TPopulation::promote_candidate()
{
    // cout << rate_sum << endl;
    double losowa = static_cast<double>(std::rand()) / RAND_MAX * rate_sum;
    double a = 0;
    for (int i = 0; i < candidates_count;i++)
    {
        a = a+candidates[i].give_rate();
        if(losowa <= a)
        {
            return &candidates[i];
        }
    }
}
unsigned int TPopulation::get_candidates_count()
{
    return candidates_count;
}
void TPopulation::test(int num_testing)
{
    std::vector<int> results(get_candidates_count());

    for (int i = 0; i < num_testing; ++i)
    {
        TCandidate* selected = promote_candidate();
        int id = selected->get_id() - 1;
        results[id]++;
    }

    std::vector<int> results_sorted = results;
    std::sort(results_sorted.begin(), results_sorted.end(), std::greater<>());

    int a = 0;
    while (a < get_candidates_count()) {
        for (int i = 0; i < get_candidates_count(); i++) {
            if (results_sorted[a] == results[i]) {
                std::cout << "candidate#" << (i + 1) << "   ";
                double procent = (static_cast<double>(results[i]) * 100) / num_testing;
                std::cout << "Ilosc procent: " << procent << "%";
                std::cout << " Ilosc trafien: " << results[i] << std::endl;
                a++;
            }
        }
    }
}