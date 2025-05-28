#include <iostream>
#include <math.h>
#include <cstdlib>
#include "TCandidate.h"

using namespace std;

unsigned int TCandidate::_id = 0;
TCandidate::TCandidate() 
{
    genes.push_back(p1);
    genes.push_back(p2);
    ocena = 0;
    id = _id++;
}
void TCandidate::info()
{
    cout << "===================="<<endl;
    cout << "Najlepszy osobnik" << endl;
    cout << "gens count: " << genes.size() << endl;
    cout << "x1" << " value:" << genes[0].get_val()<< endl;
    cout << "x2" << " value:" << genes[1].get_val() << endl;
    cout << "Rate: " << ocena << endl;
    cout << "===================="<<endl;
}
void TCandidate::rate()
{
    cout << "Rate: " << ocena << endl;
}
double TCandidate::get_rate()
{
    return ocena;
}
void TCandidate::calc_rate()
{
    ocena = genes[0].get_val()*genes[0].get_val()+genes[1].get_val();

}
unsigned int TCandidate::get_id()
{
    return id;
}
std::string TCandidate::get_binary_rate() {
    int first = static_cast<int>(get_gene_value(0));

    std::string binary1 = "";
    if (first == 0) {
        binary1 = "0000000";
    }
    else {
        while (first > 0) {
            binary1 += (first % 2 == 0 ? '0' : '1');
            first /= 2;
        }
        std::reverse(binary1.begin(), binary1.end());
        while (binary1.length() < 7) {
            binary1 = '0' + binary1;
        }
    }
    int second = static_cast<int>(get_gene_value(1));
    std::string binary2 = "";
    if (second == 0) {
        binary2 = "0000";
    }
    else {
        while (second > 0) {
            binary2 += (second % 2 == 0 ? '0' : '1');
            second /= 2;
        }
        std::reverse(binary2.begin(), binary2.end());
        while (binary2.length() < 4) {
            binary2 = '0' + binary2;
        }
    }
    return binary1 + binary2;
}

double TCandidate::get_gene_value(int num)
{
    return genes[num].get_val();
}
void TCandidate::set_genes_value(std::string binary_value)
{
    std::string bin_gen1 = binary_value.substr(0, 7);
    std::string bin_gen2 = binary_value.substr(7,4);

    int gen1 = std::stoi(bin_gen1, nullptr, 2);
    int gen2 = std::stoi(bin_gen2, nullptr, 2);

	if (gen1 > 100) gen1 = 100;
	if (gen2 > 10) gen2 = 10;

    genes[0].set_val(gen1);
	genes[1].set_val(gen2);
}
