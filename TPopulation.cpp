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
        int random_number = std::rand() % 100 + 1; // liczba od 1-100
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

    int split_index = std::rand() % 11 + 1; // liczba od 1-11
	//cout << "Split index: " << split_index << endl;
    std::string rate1 = can1-> get_binary_rate();
	std::string rate2 = can2->get_binary_rate();

	std::string new_rate1 = mutation(rate1.substr(0, split_index) + rate2.substr(split_index));
	std::string new_rate2 = mutation(rate2.substr(0, split_index) + rate1.substr(split_index));

	//cout << "can1: " << can1->get_id() << " rate: " << can1->get_rate() << endl;
    //cout << "can2: " << can2->get_id() << " rate: " << can2->get_rate() << endl;

	can1->set_genes_value(new_rate1);
    can2->set_genes_value(new_rate2);

	//cout << "new can1: " << can1->get_id() << " rate: " << can1->get_rate() << endl;
	//cout << "new can2: " << can2->get_id() << " rate: " << can2->get_rate() << endl;

    candidates.push_back(*can1);
    candidates.push_back(*can2);
}
std::string TPopulation::mutation(std::string old_binary)
{
    for(unsigned int i = 0; i < old_binary.length(); i++)
    {
        if (std::rand() % 100 < 5) // 5% szans na mutacjê
        {
            old_binary[i] = (old_binary[i] == '0') ? '1' : '0'; // zmiana bitu
        }
	}
	return old_binary;
}
void TPopulation::info() 
{

    cout << "===================="<<endl;
    cout << "Populacja: " << _id << endl;
    for(int i = 0; i < candidates_count;i++)
    {
        cout << "candidate#" << candidates[i].get_id() << ": " << candidates[i].get_rate() << endl;
    }
    
}
void TPopulation::calculate()
{
    rate_sum = 0;
    best_val = 0;

    for (int i = 0; i < candidates_count; i++)
    {
        candidates[i].calc_rate();
        rate_sum += candidates[i].get_rate();
        if (candidates[i].get_rate() > best_val)
        {
            best_val = candidates[i].get_rate();
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
    cout<< "== Population #"<< _id << "|| best val: "<< BestCandidate.get_rate() << endl;

}
double TPopulation::best_rate()
{
    return BestCandidate.get_rate();
}
TCandidate* TPopulation::promote_candidate()
{
    // cout << rate_sum << endl;
    double losowa = static_cast<double>(std::rand()) / RAND_MAX * rate_sum;
    double a = 0;
    for (int i = 0; i < candidates_count;i++)
    {
        a = a+candidates[i].get_rate();
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