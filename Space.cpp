#include "Space.hpp"

#include <iostream>

using namespace std;

Space::Space() {
    Space *towardsFront = 0;
	Space *towardsBack = 0;
	Space *side1 = 0; 
	Space *side2 = 0;
    
}

Space::~Space() {
    
}

void Space::printRoomName() {
    cout << ":: " << roomName << " ::" << endl;
}

void Space::printRoomDescription() {
    cout << roomDescription << endl;
}

void Space::roomCompleted() {
    completed = true;
}
