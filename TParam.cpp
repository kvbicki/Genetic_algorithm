#include <iostream>
#include <math.h>
#include <cstdlib>
#include "TParam.h"

using namespace std;

TParam::TParam(double x_start, double x_end, double dx)
{
    set_range(x_start, x_end, dx);
    name = "";
    set_rand_val();
}
TParam::TParam(double x_start, double x_end, double dx, double val)
{
    set_range(x_start, x_end, dx);
    set_val(val);
    name = "";
}
TParam::TParam(std::string name, double x_start, double x_end, double dx)
{
    set_range(x_start,x_end,dx);
    set_name(name);
    set_rand_val();
}
TParam::TParam(std::string name, double x_start, double x_end, double dx, double val)
{
    set_range(x_start,x_end,dx);
    set_val(val);
    set_name(name);
}
void TParam::set_range(double x_start, double x_end, double dx)
{
    this->x_start = x_start;
    this->x_end = x_end;
    this->dx = dx;
    set_rand_val();
}
int TParam::get_val_id(double val)
{
    if (val < x_start) return 0;
    else if (val > x_end) return (x_end - x_start) / dx;
    else
    {
        double x = x_start;
        int _id = 0;
        while (fabs(x + _id * dx - val) > dx / 2) _id++;       
        return _id;
    }
}
void TParam::info()
{
    cout << "\n";
    cout << "==================\n";
    cout << "== name: " << name << "\n";
    cout << "== range: ["<< x_start << "; " << x_end << "; "<< dx << "]\n";
    cout << "== value: "<< get_val() << "\t (id: #" << val_id << ")\n";
    cout << "==================\n\n";
}
void TParam::set_rand_val()
{
    int vals_count = fabs(x_end - x_start) /dx +1;
    val_id = rand()%vals_count;
}