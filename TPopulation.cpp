#include <iostream>
#include <math.h>
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
    double best_val = 0;

    for(int i = 0; i < candidates_count; i++)
    {
        TCandidate Tc;
        Tc.calc_rate();
        candidates.push_back(Tc);
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