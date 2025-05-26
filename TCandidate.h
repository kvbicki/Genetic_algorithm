#pragma once
#include <string>
#include "TParam.h"
#include <vector>
#include <algorithm>

class TCandidate
{
private:
    std::string name;
    TParam p1{0, 100, 1};
    TParam p2{0, 10, 1};
    std::vector<TParam> genes;
    double ocena;
    static unsigned int _id;
    unsigned int id;
public:
    TCandidate();   
    void info();
    void rate();
    void calc_rate();
    std::string get_binary_rate();
    double give_rate();
    unsigned int get_id();
};