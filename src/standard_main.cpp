#include <iostream>

#include "alloc.hpp"
#include "string.hpp"

using namespace std;

void run_tests() {
    String firstString("First");
    String secondString("Second");
    String thirdString(firstString);
    String fourthString("Fourth");
    String fifthString = String();
    cout << "+: " << firstString + secondString << endl;
    cout << "+=: " << (firstString += secondString) << endl;
    cout << "indexOf(String): " << firstString.indexOf(secondString) << endl;
    cout << "indexOf(char): " << firstString.indexOf('t') << endl;
    cout << "LT: " << (secondString < firstString) << endl;
    cout << "GT: " << (secondString > firstString) << endl;
    cout << "LE: " << (secondString <= firstString) << endl;
    cout << "GE: " << (secondString >= firstString) << endl;
    cout << "<<: " << fifthString << endl;
    cout << "<<: " << fourthString << endl;
    cout << "==: " << (secondString == firstString) << endl;
    cout << "indexOf(String): " << fourthString.indexOf(fifthString) << endl;
    cout << "size(): " << fifthString.size() << endl;
    cout << "size(): " << fourthString.size() << endl;
    cout << "[]: " << firstString[0] << endl;
    cout << "[]: " << firstString[firstString.size() - 1] << endl;
    cout << "[]: " << secondString[0] << endl;
    cout << "[]: " << secondString[secondString.size() - 1] << endl;
    cout << "[]: " << fifthString[0] << endl;
    cout << "!=: " << (thirdString != thirdString) << endl;
    cout << "Enter a test string: ";
    cin >> firstString;
    cout << firstString << endl;
    cout << (firstString < secondString) << endl;
    cout << (firstString <= thirdString) << endl;
    cout << (firstString > fourthString) << endl;
    cout << (firstString >= fifthString) << endl;
}

int main() {
    AllocationTracker tracker;
    run_tests();
    tracker.print_allocation_report(std::cout);
}
