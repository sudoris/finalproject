#include <iostream>
#include <string>


#include "Head.hpp" 
#include "Space.hpp"

using namespace std;

Head::Head() {
    roomName = "Front of the Train";
    roomDescription = "You are in the front of the train. The door to the control room is firmly locked.";
                      
}

void Head::action(Point **backpack, int &energy, int &itemCount) {
    
    if (completed) {
        cout << "You don't find anything new." << endl;
    }
    else if (!completed) {
        cout << "You don't see anything else in the compartment and decide to bang on the door to the control room. A small window opens and you see the "
                << "face from the speaker panel at the rear of the train. Wearing that same rage enducing grin, you consider trying to poke it in the eye "
                << "but decide to instead say, \"Okay, give me my point already.\" The devil thing cackles and replies: In a hurry are we? Fine, don't get "
                << "zapped. This question will be administered orally." << endl;
        
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

bool Head::askQuestion(int &energy) {
    int answer;
    
    cout << "One of your once-classmates has an unanswered question. His question: what is the Big-O notation for a linear search?" << endl << endl;
    cout << "1) O(n)" << endl ;
    cout << "2) O(log(n))" << endl;
    cout << "3) O(2n)" << endl;
    cout << "> ";
    cin >> answer;
    if (cin.fail() || answer < 1 || answer > 3) {
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