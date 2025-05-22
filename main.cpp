#include <iostream>
#include "TAlgorithm.h"
#include <cstdlib>
#include <time.h>

using namespace std;
#include <vector>

void test(TPopulation& pop,int num_testing)
{
    std::vector<int> results(pop.get_candidates_count());

    for (int i = 0; i < num_testing; ++i)
    {
        TCandidate* selected = pop.promote_candidate();
        int id = selected->get_id() - 1;
        results[id]++;
    }
    for (int i = 0; i < pop.get_candidates_count(); ++i)
    {
        cout << "candidate#" << (i + 1) << "   ";
        double procent = (static_cast<double>(results[i]*100)/num_testing);
        cout << "Ilosc procent: "<< procent << "%";
        cout << " Ilosc trafien: "<< results[i] << endl;
    }
}


int main()
{
    srand(time(0));

    TPopulation pop{10};
    pop.calculate();
    pop.info();
    cout << endl;

    // cout << "Wylosowani osobnicy: "<<endl;
    // for (int i = 0; i < 10; i++)
    // {
    //     TCandidate* can = pop.promote_candidate();
    //     // can = pop.promote_candidate();
    //     cout <<"candidate#"<< can->get_id()<< " " <<can-> give_rate() << endl;
    // }
    test(pop,1000);
}

