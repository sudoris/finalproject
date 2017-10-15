#include <iostream>
#include <string>

#include "Car3.hpp" 
#include "Space.hpp"

using namespace std;

Car3::Car3() {
    roomName = "Coach 3";
    roomDescription = "This just looks like a regular old train compartment. There is a restroom at one end. You decide to use the restroom. "
                      "The first thing you see when entering the restroom is an extremely large mirror hanging on the wall. As you close the door "
                      "behind you, you notice that there is another smaller mirror hanging off the back of the door. Looking back at the mirror "
                      "above the sink, you an infinitely repeating series of smaller and smaller reflections of you and your surroundings.";
}

void Car3::action(Point **backpack, int &energy, int &itemCount) {
    
    if (completed) {
        cout << "You find nothing of interest." << endl;
    }
    else if (!completed) {
        cout << "You search the restroom for toilet paper. There seems to be a cabinet behind the mirror. You begin to open the mirror, but as soon as "
                << "you touch the mirror, it begins to flash and turns into a screen. On it are the words: Welcome to Welcome to Welcome to the room of "
                << "recursion the room of recursion the room of recursion. Answer your classmate's question to continue. No is not an option." << endl;
                
        
        while (!askQuestion(energy)) {
            cout << "You are zapped by a strong jolt of electricity for answering incorrectly! You lose 5 energy!" << endl; 
            energy-=5;
            cout << "You have " << energy << " remaining." << endl;
            if (energy <= 0) {
                return;
            }
        }
        
        cout << "That is the correct answer!" << endl;
        cout << "You gain 1 point, it is added to your backpack." << endl;
        
        backpack[itemCount] = new Point();
        itemCount++;
        
        roomCompleted();
        
    }
    
    
}

bool Car3::askQuestion(int &energy) {
    int answer;
    
    cout << "Help, I have my base case correctly set to 0, but my program still gets stuck in an infinite recursive loop" << endl << endl;
    cout << "1) Sorry buddy, can't help you there, I don't do recursion." << endl ;
    cout << "2) Check your base case again, it isn't always 0." << endl;
    cout << "> ";
    cin >> answer;
    
    
    if (cin.fail() || answer < 1 || answer > 2) {
        cin.clear();
        cin.ignore(256, '\n');
        
        
        cout << "That is not a valid answer. Choose a number from the list." << endl;
		cout << "> ";        
        cin >> answer;
    }
    
    if (answer == 2) {
        return true;
    }
    else {
        return false;
    }
}