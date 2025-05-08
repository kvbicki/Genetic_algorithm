#include <iostream>
#include <math.h>
#include "TCandidate.h"

using namespace std;

TCandidate::TCandidate() 
{
    genes.push_back(p1);
    genes.push_back(p2);
    ocena = genes[0].get_val()*genes[0].get_val()+genes[1].get_val();
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