#include <vector>
#include "TPopulation.h"

class TAlgorithm
{
private:
    unsigned int stop_max_population_count;
    unsigned int stop_min_improvment_proc;

    TPopulation* wsk_population_pres;
    TPopulation* wsk_population_prev;

    std::vector<TPopulation*> older; 
    std::vector<bool> older_rate;      
    unsigned int pop_check;                   

public:
    TAlgorithm(unsigned int candidates_count, unsigned int max_population_count, unsigned int min_improvment_proc);
    ~TAlgorithm();

    void run();

private:
    bool is_max_population();
    bool is_min_improvment();
    bool is_stop();
};