#include <iostream>
// #include "TAlgorithm.h"
#include "TCandidate.h"
#include "TCandidate_Zad1.h"
#include "TCandidate_Zad2.h"
#include "TCandidate_Zad3.h"
#include <cstdlib>
#include <time.h>

using namespace std;

int main()
{
    srand(time(0));

    // TCandidate can1;
    // can1.get_max_binary_rate();
//    TPopulation* pop1 = new TPopulation(10);
//    pop1->calculate();
//    pop1->info();
//    TPopulation* pop2 = new TPopulation(pop1);
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
	// unsigned int candidates_count = 10;
    // unsigned int max_population_count = 20;
	// unsigned int min_improvment_proc = 2;
    // TAlgorithm task{candidates_count,max_population_count,min_improvment_proc };
	// task.run();

    TCandidate_Zad1 can1;
    can1.calc_rate();
    can1.info();
    TCandidate_Zad2 can2;
    can2.calc_rate();
    can2.info();
    TCandidate_Zad3 can3;
    can3.calc_rate();
    can3.info();
}

