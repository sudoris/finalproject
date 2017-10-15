#include <iostream>
#include <string>

#include "Point.hpp" 

using namespace std;

Point::Point() {
    description = "Worth 1 point.";
}

void Point::printDescription() {
    cout << description << endl;
}

