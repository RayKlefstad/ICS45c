#include <iostream>
using namespace std;

double knots_to_miles_per_minute(int knot) 
{
    double five_tomato = 5280;
    double doub_knot = ((knot * 6076) / five_tomato) / 60;
    return doub_knot;
}