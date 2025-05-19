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
    int i;
    for( i = 0; i < candidates_count;i++)
    {
        cout << "candidate#" << i << ": " << candidates[i].give_rate() << endl;
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
        if(losowa < a)
        {
            return &candidates[i];
        }
    }

}
std::string TPopulation::get_mark(TCandidate)
{
    return 0;
}