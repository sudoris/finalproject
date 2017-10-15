#include <iostream>
#include <string>


#include "Freight.hpp" 
#include "Space.hpp"

using namespace std;

// basically an empty room where the player can receive a free Point object
Freight::Freight() {
    roomName = "Car 2";
    roomDescription = "This is just an empty freight car. It would normally carry stuff.";
    
}

void Freight::action(Point **backpack, int &energy, int &itemCount) {
    
    if (completed) {
        cout << "You find nothing of interest." << endl;
    }
    else if (!completed) {
        cout << "You find an old crate in one corner and open it. Just as you are about to put the cover back on, you notice something shiny inside " 
             << "You take a closer look and realize that someone left a Point inside!" << endl;
    
        backpack[itemCount] = new Point();
        itemCount++;
            
        roomCompleted();
    }
    
}

bool Freight::askQuestion(int &energy) {
    
}