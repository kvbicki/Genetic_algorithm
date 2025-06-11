#pragma once

#include "TCandidate.h"

class TCandidate_Zad3 : public TCandidate
{
public:
    TCandidate_Zad3() : TCandidate()
    {
        init_vector();
    }

    TCandidate_Zad3(const TCandidate_Zad3& original) : TCandidate(original) {}

    void calc_rate()
    {
        double x1 = genotype[0].get_val();
        double x2 = genotype[1].get_val();
        double x3 = genotype[2].get_val();

        rate = x1+x2+x3;
    }
protected:
void init_vector(){
        genotype.push_back({"X1", 0, 100, 1});
        genotype.push_back({"X2", 0, 100, 1});
        genotype.push_back({"X3", 0, 100, 1});
        gens_count = genotype.size();
    }
};