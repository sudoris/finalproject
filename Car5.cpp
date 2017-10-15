#include <iostream>
#include <string>


#include "Car5.hpp" 
#include "Space.hpp"

using namespace std;

Car5::Car5() {
    roomName = "Coach 5";
    roomDescription = "Upon entering the next car, you notice that it's mostly empty except for a long red carpet that runs down the middle. Other "
                      "than that, arrows pointing at boxes and other randomly shaped objects have been drawn all over the walls and ceiling. "
                      "Enter 's' to search the room or choose which way to go.";
}

// provides more detailed description of room as well as interaction with the player
void Car5::action(Point **backpack, int &energy, int &itemCount) {
	
    // if the question in the room has already been answered
    if (completed) {
        cout << "You don't find anything new." << endl;
    }
    else if (!completed) {
        cout << "As you search the room, you notice a raised area under the carpet near the middle. You walk to the center of the room and lift the "
                << "carpet with your foot. Underneath the carpet you find a large red button in the floor with the words NEW on it. Curiousity gets "
                << "the better of you and you step on the button. As soon as you step on the button, rows of seats suddenly begin to appear. For each "
                << "row that appears, one of the arrows on the wall that turns to point at it. As the last row of seats appears, you notice that it comes "
                << "with a pop-up panel. You decide to sit down and the screen on the panel flickers on." << endl << endl;
        
        cout << "You see the following message appear on the screen: Welcome to Week 1 of the Piazza discussion board. Answer your classmate's question "
                << "correctly to earn 1 point." << endl;
        
		// continue asking question until correct answer is received
        while (!askQuestion(energy)) {
            // each time an incorrect answer is given, 5 energy is taken off			
			cout << "You are zapped by a strong jolt of electricity for answering incorrectly! You lose 5 energy!" << endl; 
            energy-=5;
            cout << "You have " << energy << " energy remaining." << endl;
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

// quizzes player
bool Car5::askQuestion(int &energy) {
    int answer;
    
    cout << "Help, I keep getting memory leaks on Valgrind. Which form of the operator delete would I use to deallocate memory " << endl
         << "allocated by a statement such as this: " << endl << endl;		 
	cout << "	student_list = new students[size]?" << endl << endl;
    cout << "1) delete []student_list" << endl ;
    cout << "2) delete student_list" << endl;
    cout << "3) delete []students" << endl;
    cout << "4) delete students[size]" << endl;  
    cout << "> ";
    cin >> answer;
    if (cin.fail() || answer < 1 || answer > 4) {
        cin.clear();
        cin.ignore(256, '\n');
        cout << "That is not a valid answer. Choose a number from the list." << endl;
		cout << "> ";
        cin >> answer;
    }
    
    if (answer == 1) {
        return true;
    }
    else {
        return false;
    }
    
}
