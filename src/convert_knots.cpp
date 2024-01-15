#include <iostream>
#include "convert_knots.hpp"
using namespace std;

int main() 
{
    int knots = 0;
    cout << "Enter your speed in knots: " << endl;
    cin >> knots;
    cout << "Speed is miles per minute is: " << knots_to_miles_per_minute(knots) << endl;
    return 0;
}