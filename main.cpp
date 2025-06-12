#include <iostream>
#include "TAlgorithm.h"
#include <cstdlib>
#include <time.h>

using namespace std;

int main()
{
    srand(time(0));

    // TESTING

    // TCandidate can1;
    // can1.get_max_binary_rate();
//    TPopulation* pop1 = new TPopulation(10);
//    pop1->calculate();
//    pop1->info();
//    TPopulation* pop2 = new TPopulation(*pop1);
//    pop2->calculate();
//    pop2->info();
//    TPopulation* pop3 = new TPopulation(pop2);
//    pop3->calculate();
//    pop3->info();
// 	TPopulation* pop4 = new TPopulation(pop3);
// 	pop4->calculate();
// 	pop4->info();
// 	TPopulation* pop5 = new TPopulation(pop4);
// 	pop5->calculate();
// 	pop5->info();
    // cout << "Wylosowani osobnicy: "<<endl;
    // for (int i = 0; i < 10; i++)
    // {
    //     TCandidate* can = pop.promote_candidate();
    //     // can = pop.promote_candidate();
    //     cout <<"candidate#"<< can->get_id()<< " " <<can-> get_rate() << endl;
    // }

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


	unsigned int candidates_count = 10;
    unsigned int max_population_count = 200;
	unsigned int min_improvment_proc = 2;
    unsigned int pop_check = 5;
    TAlgorithm task{pattern,candidates_count,max_population_count,min_improvment_proc, pop_check};
	task.run();
}

