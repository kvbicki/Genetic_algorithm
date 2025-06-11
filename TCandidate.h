#pragma once
#include <string>
#include "TParam.h"
#include <vector>
#include <algorithm>


class TCandidate
{
protected:
    int gens_count = 0;
    std::vector<TParam> genotype;

    double rate;
public:
    TCandidate();   
    virtual ~TCandidate();
    TCandidate(const TCandidate& original);

    virtual TCandidate* create() = 0;
    virtual TCandidate* create_copy() const = 0; 

    void info();
    void show_rate();
    virtual void calc_rate() = 0;
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
    virtual void init_vector() = 0;
    
    static unsigned int _id;
    unsigned int id;
    std::string x1_max_bin;
    std::string x2_max_bin;
};