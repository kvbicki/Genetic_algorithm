#include <iostream>
#include "TAlgorithm.h"
#include <cstdlib>
#include <time.h>

using namespace std;

int main()
{
    srand(time(0));

    //ALGORITHM

    TCandidate* pattern;
    int _type = -1;

    cout << "Choose candidate type: " << endl;
    cin >> _type;

    switch (_type)
    {
    case 1:
        pattern = new TCandidate_Zad1();
        break;
    case 2:
        pattern = new TCandidate_Zad2();
        break;
    case 3:
        pattern = new TCandidate_Zad3();
        break;
    default:
        pattern = new TCandidate_Zad1();
        break;
    }


	unsigned int candidates_count = 20;
    unsigned int max_population_count = 200;
	unsigned int min_improvment_proc = 2;
    unsigned int pop_check = 5;
    TAlgorithm task{pattern,candidates_count,max_population_count,min_improvment_proc, pop_check};
	task.run();
}

