#include <iostream>
#include <math.h>
#include <cstdlib>
#include "TCandidate.h"

using namespace std;

unsigned int TCandidate::_id = 0;
TCandidate::TCandidate() 
{
    gens_count = genotype.size();
    rate = 0;
    id = _id++;

}
TCandidate::~TCandidate() {
}
TCandidate::TCandidate(const TCandidate& original)
{
    rate = original.get_rate();

    for (int i =0; i < gens_count; i++){
        double x_start = original.genotype[i].get_x_start();
        double x_end = original.genotype[i].get_x_end();
        double dx = original.genotype[i].get_dx();
        genotype[i].set_range(x_start, x_end, dx);


        double val = original.genotype[i].get_val();
        genotype[i].set_val(val);
    }
    gens_count = genotype.size();
}
void TCandidate::info()
{
    cout << "===================="<<endl;
    cout << "Best candidate" << endl;
    cout << "gens count: " << gens_count << endl;
    for (int i = 0; i < gens_count; ++i) {
        cout << "x" << (i + 1) << ": " << genotype[i].get_val() << endl;
    }
    cout << "Rate: " << rate << endl;
    cout << "===================="<<endl;
}
void TCandidate::show_rate()
{
    cout << "Rate: " << rate << endl;
}
double TCandidate::get_rate() const
{
    return rate;
}

unsigned int TCandidate::get_id() const
{
    return id;
}
std::string TCandidate::get_binary_rate() {
    std::string result = "";
    for (int i = 0; i < gens_count ; ++i) {
        int value = static_cast<int>(genotype[i].get_val());
        int bits_needed = needed_bits((i == 0) ? genotype[0].get_x_end() : genotype[1].get_x_end());
        std::string binary = decimal_to_binary(value);
        while (binary.length() < bits_needed) {
            binary = '0' + binary;
        }
        result += binary;
    }
    return result;
}

double TCandidate::get_gene_value(int num)
{
    return genotype[num].get_val();
}
void TCandidate::set_genes_value(std::string binary_value) {
    int start = 0;
    for (int i = 0; i < gens_count; ++i) {
        int bits_needed = needed_bits((i == 0) ? genotype[0].get_x_end() : genotype[1].get_x_end());
        std::string bin_gene = binary_value.substr(start, bits_needed);
        int value = std::stoi(bin_gene, nullptr, 2);
        if (i == 0 && value > genotype[0].get_x_end()) value = genotype[0].get_x_end();
        if (i == 1 && value > genotype[1].get_x_end()) value = genotype[1].get_x_end();
        genotype[i].set_val(value);
        start += bits_needed;
    }
}


void TCandidate::get_max_binary_rate()
{
    possible_rate = genotype[0].get_x_end() * genotype[0].get_x_end() + genotype[1].get_x_end();

    
    x1_max_bin = decimal_to_binary(static_cast<int>(genotype[0].get_x_end()));
    x2_max_bin = decimal_to_binary(static_cast<int>(genotype[1].get_x_end()));
    cout << "====================" << endl;
    cout << "Possible Max Rate (dec): " << possible_rate << endl;
    cout << "Possible Max Rate (bin): " << decimal_to_binary(static_cast<int>(possible_rate)) << endl;
    cout << "x1_max le : " << x1_max_bin.length() << endl;
    cout << "x1_max (bin): " << x1_max_bin << endl;
    cout << "x2_max len: " << x2_max_bin.length() << endl;
    cout << "x2_max (bin): " << x2_max_bin<< endl;
    cout << "====================" << endl;
}
std::string TCandidate::decimal_to_binary(int number)
{
    if (number == 0) return "0";
    std::string result = "";
    while (number > 0)
    {
        result = (number % 2 == 0 ? "0" : "1") + result;
        number /= 2;
    }
    return result;
}
int TCandidate::needed_bits(int max_value) const {
    int bits = 0;
    while ((1 << bits) <= max_value) {
        bits++;
    }
    return bits;
}
int TCandidate::get_max_bits() const{

    return needed_bits(possible_rate);
}