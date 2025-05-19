#pragma once
#include <string>
#include "TParam.h"
#include <vector>

class TCandidate
{
private:
    std::string name;
    TParam p1{0, 100, 1};
    TParam p2{0, 10, 1};
    std::vector<TParam> genes;
    double ocena;
public:
    TCandidate();   
    void info();
    void rate();
    void calc_rate();
    double give_rate();
};