#include <iostream>
#include <math.h>
#include "TPopulation.h"

using namespace std; 

unsigned int TPopulation::count = 0;

TPopulation::TPopulation(unsigned int candidates_count)
{
    this->candidates_count = candidates_count;
    TPopulation::count += 1;
    _id = TPopulation::count;
}
void TPopulation::info() 
{

    cout << "===================="<<endl;
    cout << "Populacja: " << _id << endl;
    if (candidates.empty()) {
        int i;
        for( i = 0; i < candidates_count;i++)
        {
            cout << "candidate#" << i << ": " << "0" << endl;
        }
    } else {
        int i;
        for( i = 0; i < candidates_count;i++)
        {
            cout << "candidate#" << i << ": " << candidates[i].give_rate() << endl;
        }
    }
    cout << "===================="<<endl;
}
void TPopulation::calculate()
{
    double best_val = 0;

    for(int i = 0; i < candidates_count; i++)
    {
        TCandidate Tc;
        candidates.push_back(Tc);
        if(best_val < candidates[i].give_rate())
        {
            best_val = candidates[i].give_rate();
            TCandidate BestCandidate = candidates[i];
        }
    }
    
}

TCandidate TPopulation::best()
{
    return BestCandidate;
}