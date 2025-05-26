#include <iostream>
#include "TAlgorithm.h"
#include <cstdlib>
#include <time.h>

using namespace std;

int main()
{
    srand(time(0));

    TPopulation* pop1 = new TPopulation(10);
    pop1->calculate();
    pop1->info();
    TPopulation* pop2 = new TPopulation(pop1);
    pop2->calculate();
    pop2->info();
    TPopulation* pop3 = new TPopulation(pop2);
    pop3->calculate();
    pop3->info();
    // cout << "Wylosowani osobnicy: "<<endl;
    // for (int i = 0; i < 10; i++)
    // {
    //     TCandidate* can = pop.promote_candidate();
    //     // can = pop.promote_candidate();
    //     cout <<"candidate#"<< can->get_id()<< " " <<can-> give_rate() << endl;
    // }
}

