#include <iostream>
#include "TAlgorithm.h"
#include <cstdlib>
#include <time.h>

using namespace std;




int main()
{
    srand(time(0));

    TPopulation pop{10};
    pop.calculate();
    pop.info();
    cout << endl;
    pop.test(1000);

    // cout << "Wylosowani osobnicy: "<<endl;
    // for (int i = 0; i < 10; i++)
    // {
    //     TCandidate* can = pop.promote_candidate();
    //     // can = pop.promote_candidate();
    //     cout <<"candidate#"<< can->get_id()<< " " <<can-> give_rate() << endl;
    // }
}

