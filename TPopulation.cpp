#include <iostream>
#include <math.h>
#include <cstdlib>
#include "TPopulation.h"

using namespace std; 

unsigned int TPopulation::_id = 0;

TPopulation::TPopulation(unsigned int candidates_count, TCandidate* pattern)

{
    this->candidates_count = candidates_count;
    id = ++_id;
    for (int i = 0; i < candidates_count; ++i)
    {
        candidates.push_back(pattern->create());
    }
}

TPopulation::TPopulation(const TPopulation& orginal)
{
    id = ++_id;
    candidates_count = orginal.get_candidates_count(); 
    best_val = orginal.get_best_rate();                 

    for (int i = 0; i < candidates_count / 2; i++) {
        int random_number = std::rand() % 100 + 1;

        const TCandidate* wsk_os_org1 = orginal.promote_candidate();
        const TCandidate* wsk_os_org2 = orginal.promote_candidate(); 

        TCandidate* can1 = wsk_os_org1->create_copy();
        TCandidate* can2 = wsk_os_org2->create_copy();
 

        if (random_number >= 75) {
            std::string rate1 = can1->get_binary_rate();
            std::string rate2 = can2->get_binary_rate();
            std::string new_rate1 = mutation(rate1);
            std::string new_rate2 = mutation(rate2);

            can1->set_genes_value(new_rate1);
            can2->set_genes_value(new_rate2);

            candidates.push_back(can1);
            candidates.push_back(can2);
        } else {
            cross(can1, can2);
        }
    }
}
TPopulation::~TPopulation() {
    for (auto candidate : candidates) {
        delete candidate;
    }
    candidates.clear();
    BestCandidate = nullptr;
}


void TPopulation::cross(TCandidate* can1, TCandidate* can2)
{
    int split_index = std::rand() % can1->get_max_bits() + 1;

    std::string rate1 = can1->get_binary_rate();
    std::string rate2 = can2->get_binary_rate();

    std::string new_rate1 = mutation(rate1.substr(0, split_index) + rate2.substr(split_index));
    std::string new_rate2 = mutation(rate2.substr(0, split_index) + rate1.substr(split_index));

    can1->set_genes_value(new_rate1);
    can2->set_genes_value(new_rate2);

    candidates.push_back(can1);
    candidates.push_back(can2);
}

std::string TPopulation::mutation(std::string old_binary)
{
    for (unsigned int i = 0; i < old_binary.length(); i++)
    {
        if (std::rand() % 100 < 5)
        {
            old_binary[i] = (old_binary[i] == '0') ? '1' : '0';
        }
    }
    return old_binary;
}

void TPopulation::info()
{
    cout << "====================" << endl;
    cout << "Population: " << _id << endl;
    for (int i = 0; i < candidates_count; i++)
    {
        cout << "candidate#" << candidates[i]->get_id() << ": " << candidates[i]->get_rate() << endl;
    }
    cout << endl;
    cout << "Best candidate id#" << BestCandidate->get_id() << " Rate: " << BestCandidate->get_rate() << endl;
}

void TPopulation::calculate()
{
    rate_sum = 0;
    best_val = 0;

    for (int i = 0; i < candidates_count; i++)
    {
        candidates[i]->calc_rate();
        rate_sum += candidates[i]->get_rate();
        if (candidates[i]->get_rate() > best_val)
        {
            best_val = candidates[i]->get_rate();
            BestCandidate = candidates[i];
        }
    }
}

TCandidate* TPopulation::get_best_candidate()
{
    return BestCandidate;
}

double TPopulation::get_best_rate() const
{
    if (candidates.empty()) {
        return -1;
    }

    double best = -1;
    for (size_t i = 0; i < candidates.size(); ++i) {
        if (!candidates[i]) {
            continue;
        }

        double r = candidates[i]->get_rate();
        if (r > best) best = r;
    }

    return best;
}

TCandidate* TPopulation::promote_candidate() const
{
    
    double random_num = static_cast<double>(std::rand()) / RAND_MAX * rate_sum;
    double cumulative_rate = 0.0;

    for (int i = 0; i < candidates_count; ++i)
    {
        cumulative_rate += candidates[i]->get_rate();
        if (random_num <= cumulative_rate)
        {
            return candidates[i];
        }
    }
    return candidates[candidates_count - 1];
}

unsigned int TPopulation::get_candidates_count() const 
{
    return candidates_count;
}

void TPopulation::test(int num_testing)
{
    std::vector<std::pair<int, int>> results(get_candidates_count());
    for (int i = 0; i < get_candidates_count(); ++i)
        results[i] = { i + 1, 0 };

    for (int i = 0; i < num_testing; ++i)
    {
        TCandidate* selected = promote_candidate();
        int id = selected->get_id();
        results[id - 1].second++;
    }

    std::sort(results.begin(), results.end(),
        [](const std::pair<int, int>& a, const std::pair<int, int>& b) {
            return a.second > b.second;
        });

    for (int i = 0; i < get_candidates_count(); ++i)
    {
        int id = results[i].first;
        int hits = results[i].second;
        double procent = (static_cast<double>(hits) * 100) / num_testing;

        std::cout << "candidate#" << id << "   ";
        std::cout << "Percent value: " << procent << "%";
        std::cout << " Hits: : " << hits << std::endl;
    }
}

unsigned int TPopulation::get_id()
{
    return id;
}
