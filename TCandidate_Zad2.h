#pragma once

#include "TCandidate.h"

class TCandidate_Zad2 : public TCandidate
{
public:
    TCandidate_Zad2() : TCandidate() {
        set_gens_range();
    }
    TCandidate_Zad2(const TCandidate_Zad2& orginal) : TCandidate(orginal) {}


private:
    void set_gens_range()
    {
    double max_gen1 = 10;
    double max_gen2 = 10;
    genotype[0].set_range(0, max_gen1, 1);
    genotype[1].set_range(0, max_gen2, 1);
    };

public:
    void calc_rate()
    {
        double x1 = genotype[0].get_val();
        double x2 = genotype[1].get_val();

        rate = x1+x2;
    }
};

