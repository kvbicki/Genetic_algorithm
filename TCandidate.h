#pragma once
#include <string>
#include "TParam.h"
#include <vector>

class TCandidate
{
private:
    std::string name;
    TParam p1{"uszy", 1, 10, 0.5};
    TParam p2{"nos", 0, 10, 0.5};
    std::vector<TParam> genes;
    double ocena;
public:
    TCandidate();   
    void info();
    void rate();
    double give_rate();
};