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
double TCandidate::give_rate()
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
    int whole_part = static_cast<int>(ocena);
    
    if (whole_part == 0) return "0";

    std::string binary = "";
    while (whole_part > 0) {
        binary += (whole_part % 2 == 0 ? '0' : '1');
        whole_part /= 2;
    }

    std::reverse(binary.begin(), binary.end());
    return binary;
}