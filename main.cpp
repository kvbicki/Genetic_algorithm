#include <iostream>
#include "TParam.h"
#include "TCandidate.h"
#include "TPopulation.h"
#include <cstdlib>
#include <time.h>

using namespace std;

int main()
{
    srand(time(0));
    TPopulation pop(10);
    pop.info();

    pop.calculate();
    pop.info();
    pop.best();

    TPopulation pop1(10);
    pop1.calculate();
    pop1.info();
    pop1.best().info();
    
    return 0;
    
}