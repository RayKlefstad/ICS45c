#include <iostream>
using namespace std;

double knots_to_miles_per_minute(int knot) 
{
    long long knots = knot;
    double five_tomato = 5280;
    double doub_knot = ((knots * 6076) / five_tomato) / 60;
    return doub_knot;
}