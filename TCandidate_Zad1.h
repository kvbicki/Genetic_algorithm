#pragma once

#include "TCandidate.h"

class TCandidate_Zad1 : public TCandidate
{
public:
    TCandidate_Zad1() : TCandidate()
    {
        init_vector();
    }

    TCandidate_Zad1(const TCandidate_Zad1& orginal) : TCandidate(orginal) {}
    TCandidate* create()
    {
        return new TCandidate_Zad1();
    }
    TCandidate* create_copy() const
    {
        return new TCandidate_Zad1(*this);
    }
    void calc_rate()
    {
        double x1 = genotype[0].get_val();
        double x2 = genotype[1].get_val();

        rate = 2 * (x1 * x1);
    }
protected:
    void init_vector(){
        genotype.push_back({"X1", 0, 10, 1});
        genotype.push_back({"X2", 0, 10, 1});
        gens_count = genotype.size();
    }
};