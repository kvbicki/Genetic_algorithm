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

    cout << "Wylosowani osobnicy: ";
    for (int i = 0; i < 10; i++)
    {
        TCandidate* can = pop.promote_candidate();
        // can = pop.promote_candidate();
        cout << can-> give_rate() << endl;
    }
    
    return 0;
    
}