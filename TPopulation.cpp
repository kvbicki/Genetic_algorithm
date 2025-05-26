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
    for (unsigned int i = 0; i < candidates_count; ++i)
    {
        TCandidate Tc;
        candidates.push_back(Tc);
    }
}

TPopulation::TPopulation(TPopulation* older) {

    this-> candidates_count = older->get_candidates_count();
    _id++;
    for(int i = 0 ;i < candidates_count/2;i++){
        // int random_number = std::rand() % 100 + 1; // liczba od 1-100
        int random_number = 8;
        TCandidate* can1 = older->promote_candidate();
        TCandidate* can2 = older->promote_candidate();
        if(random_number >= 75){
            candidates.push_back(*can1);
            candidates.push_back(*can2);
        }
        else{
            cross(can1,can2);
        }
    }
}
void TPopulation::cross(TCandidate* can1, TCandidate* can2){
    int random_number = std::rand() % 11 + 1; // liczba od 1-11
    std::string rate1 = can1-> get_binary_rate();
    cout << rate1 << endl;
    candidates.push_back(*can1);
    candidates.push_back(*can2);
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
    rate_sum = 0;
    best_val = -INFINITY;

    for (int i = 0; i < candidates_count; i++)
    {
        candidates[i].calc_rate();
        rate_sum += candidates[i].give_rate();
        if (candidates[i].give_rate() > best_val)
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
    std::vector<std::pair<int, int>> results(get_candidates_count());
    for (int i = 0; i < get_candidates_count(); ++i)
        results[i] = { i + 1, 0 };

    for (int i = 0; i < num_testing; ++i)
    {
        TCandidate* selected = promote_candidate();
        int id = selected->get_id();
        results[id - 1].second++;  
    }

    std::sort(results.begin(), results.end(),[](const std::pair<int, int>& a, const std::pair<int, int>& b) {return a.second > b.second;});

    for (int i = 0; i < get_candidates_count(); ++i)
    {
        int id = results[i].first;
        int trafienia = results[i].second;
        double procent = (static_cast<double>(trafienia) * 100) / num_testing;

        std::cout << "candidate#" << id << "   ";
        std::cout << "Ilosc procent: " << procent << "%";
        std::cout << " Ilosc trafien: " << trafienia << std::endl;
    }
}