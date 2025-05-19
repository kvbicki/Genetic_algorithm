#include <iostream>
#include <math.h>
#include <numeric> 
#include <algorithm>
#include "TAlgorithm.h"
using namespace std;

TAlgorithm::TAlgorithm(unsigned int candidates_count,unsigned int max_population_count,unsigned int min_improvment_proc)
{
    this->candidates_count = candidates_count;
    this->max_population_count = max_population_count;
    this->min_improvment_proc = min_improvment_proc;
}

void TAlgorithm::run()
{
    for(int i=0;i<max_population_count;i++){
        
        TPopulation* pop = new TPopulation(candidates_count);
        pop->calculate();
        pop->alg_info();
        wczesniejsze.push_back(pop);

        if(wczesniejsze.size() > 2){
            delete wczesniejsze[0];
            wczesniejsze[0] = nullptr;
            wczesniejsze.erase(wczesniejsze.begin());
        }
        if(wczesniejsze.size() >= 2){

            double val1 = wczesniejsze[0]->best_rate();
            double val2 = wczesniejsze[1]->best_rate();
            cout <<" val1: " << val1 << " val2: " << val2 << endl;
            bool roznica =  std::abs(wczesniejsze[1]->best_rate() - wczesniejsze[0]->best_rate()) / wczesniejsze[1]->best_rate() * 100 < min_improvment_proc;
            // cout << roznica << endl;
            wczesniejsze_rate.push_back(roznica);
        }


        if(wczesniejsze_rate.size() >= pop_check){

            if (std::all_of(wczesniejsze_rate.begin(), wczesniejsze_rate.end(), [](bool val){ return val; })) {
                std::cout << "Wszystkie wartości to true" << std::endl;
                return;
            } else {
                std::cout << "Dalej" << std::endl;
            }
        
        

            wczesniejsze_rate.erase(wczesniejsze_rate.begin());
        }
        
        cout<< endl;

    }
    cout << "Ilosc danych w wektorze: " << wczesniejsze.size()<<endl;
    cout << "Ilosc danych w wektorze rate: " << wczesniejsze_rate.size()<<endl;

}
// bool TAlgorithm::check()
// {
//     unsigned val = 0
//     for(int i=0;i<wczesniejsze.size();i++){
//         val += wczesniejsze.

//     }

// }