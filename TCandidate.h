#pragma once
#include <string>
#include "TParam.h"
#include <vector>
#include <algorithm>

// #define GENS_COUNT 2

class TCandidate
{
protected:
    double max_gen1 = 50;
    double max_gen2 = 60;
    // TParam genotype[GENS_COUNT] = {
    //     TParam("x1", 0, max_gen1, 1),
    //     TParam("x2", 0, max_gen2, 1)
    // };
    int gens_count = 0;
    std::vector<TParam> genotype;

public:
    TCandidate();   
    TCandidate(const TCandidate& original);
    void info();
    void show_rate();
    virtual void calc_rate();
    std::string get_binary_rate();
    std::string decimal_to_binary(int number);
    void get_max_binary_rate();
    double get_rate() const;
    unsigned int get_id() const;
    double get_gene_value(int num);
	void set_genes_value(std::string binary_value);
    int needed_bits(int max_value) const;
    int get_max_bits() const;

protected:
    void init_vector();
    double rate;
    double possible_rate;
    static unsigned int _id;
    unsigned int id;
    std::string x1_max_bin;
    std::string x2_max_bin;
};