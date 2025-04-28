#include <iostream>
#include "TParam.h"
#include "TCandidate.h"
#include <cstdlib>
#include <time.h>

using namespace std;

int main()
{
    srand(time(0));
    TCandidate os1{};
    os1.info();
    os1.rate();
    
}