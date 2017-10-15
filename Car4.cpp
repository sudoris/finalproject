#include <iostream>
#include <string>


#include "Car4.hpp" 
#include "Space.hpp"

using namespace std;

Car4::Car4() {
    roomName = "Coach 4";
    roomDescription = "As soon as you enter the room, a disco ball turns on and begins to spin, dazzling you with the brilliance of all three of the "
                      "primary colors. Unlike the previous train compartments, this one has no windows. You hear Sandstorm by Darude begin to play "
                      "on the speakers and wonder what year it is. There is also a bar in the corner with empty shot glasses scattered about.";
}

void Car4::action(Point **backpack, int &energy, int &itemCount) {
    
    if (completed) {
        cout << "You don't find anything new." << endl;
    }
    else if (!completed) {
        cout << "You begin by searching the bar thinking there might be something there to help you get through this ordeal, but all you find is some "
                << "Coors Light. You sit down at the bar in despair, and place your head down on the bar to cry. Suddenly, you hear someone or something "
                << "say: Can I get you a drink? One of our light brews maybe? Lifting your head up, you see a robot wearing a bartender's outfit standing "
                << "in front of you behind the counter. In alarm, you quickly ask \"Who the heck are you?\" The robot replies: I was a once eager student " 
                << "like you. But I didn't participate and was changed into a robot bartender, to serve Coors Light until someone shows up and manages "
                << "to collect at least 5 participation points. Ok, that's enough chit-chat, here is the question I failed to answer. Good luck, my fate rests "
                << "in your hands. " << endl;
        
        cout << "A screen appears on the robot bartender's torso, displayed on it is another question from Piazza." << endl;
        
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

bool Car4::askQuestion(int &energy) {
    int answer;
    
    cout << "How would I output \"take nap\" to an open file named toDoList? " << endl << endl;
    cout << "1) toDoList.out(\"take nap\");" << endl ;
    cout << "2) toDoList=\"take nap\"\;" << endl;
    cout << "3) toDoList<<\"take nap\"\;" << endl;
    cout << "> ";
    cin >> answer;
    if (cin.fail() || answer < 1 || answer > 3) {
        cin.clear();
        cin.ignore(256, '\n');
        cout << "That is not a valid answer. Choose a number from the list." << endl;
		cout << "> ";
        cin >> answer;
    }    
    
    if (answer == 3) {
        return true;
    }
    else {
        return false;
    }
   
    
}