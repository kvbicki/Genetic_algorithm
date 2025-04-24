#include <iostream>
#include "TParam.h"

using namespace std;

int main()
{
    TParam param1{ 1, 4, 1, 2};
    TParam param2{ 10, 20, 3};
    TParam param3{0, 10, 0.5, 3.3};
    TParam param4("uszy", 1, 10, 0.5);
    TParam param5("nos", 0, 10, 3, 5);

    cout<< "param1";
    param1.info();

    cout<< "param2";
    param2.info();

    cout<< "param3";
    param3.info();

    cout<< "param4";
    param4.info();

    cout << "param5";
    param5.info();

    param2.set_val(100);
    param3.set_val(7.5);

    cout << "AFTER \n";

    cout<< "param2";
    param2.info();

    cout<< "param3";
    param3.info();
    
}