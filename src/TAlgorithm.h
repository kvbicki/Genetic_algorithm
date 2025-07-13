#include <vector>
#include "TPopulation.h"

class TAlgorithm
{
private:
    unsigned int stop_max_population_count;
    unsigned int stop_min_improvment_proc;

    TCandidate* pattern = nullptr;
    TPopulation* wsk_population_pres = nullptr;
    TPopulation* wsk_population_prev = nullptr;

    std::vector<TPopulation*> older; 
    std::vector<bool> older_rate;      
    unsigned int pop_check;     
    double result = 0;              

public:
    TAlgorithm(TCandidate* pattern,unsigned int candidates_count, unsigned int max_population_count, unsigned int min_improvment_proc, unsigned int pop_check);
    ~TAlgorithm();

    void run();

private:
    bool is_max_population();
    bool is_min_improvment();
    bool is_stop();
};