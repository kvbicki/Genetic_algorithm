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
    double get_rate();
    unsigned int get_id();
    double get_gene_value(int num);
	void set_genes_value(std::string binary_value);
};