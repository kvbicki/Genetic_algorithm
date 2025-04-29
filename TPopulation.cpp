#include <iostream>
#include <math.h>
#include "TPopulation.h"

using namespace std; 

TPopulation::TPopulation(unsigned int candidates_count)
{
    this->candidates_count = candidates_count;
    int i;
}
void TPopulation::info() 
{
    cout << "===================="<<endl;
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
    for(int i = 0; i < candidates_count; i++)
    {
        TCandidate Tc;
        candidates.push_back(Tc);
    }
}