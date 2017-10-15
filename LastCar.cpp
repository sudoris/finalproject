#include <iostream>
#include <string>

#include "LastCar.hpp" 
#include "Space.hpp"

using namespace std;

LastCar::LastCar() {
    roomName = "Coach 6";
    roomDescription = "There doesn't seem to be much in this room. Outside the window its nice and bright out, but "
                      "little of it manages to shine in to the dimly lit train compartment. Type 's' to search the " 
					  "room (searching the room is highly recommended for first time players)\ "
                      "or choose which way you want to go.";
}

void LastCar::action(Point **backpack, int &energy, int &itemCount) {
    
	// if the question in the room has not been successfully answered yet
    if (!completed) {
        
        
        cout << "Before searching the room, you check to see what you have in your backpack. All you find is some loose change. "
             << "You continue your search and notice something written on the wall. It reads: Participation - it matters. Finally, "
			 << "on the wall next to the entrance, you find what looks like a panel to speak into with a large red button next to "
			 << "it with the words HELP printed on it. You press the button and the panel begins to flicker on accompanied by a "
			 << "large buzzing sound. A hideous looking face appears on the screen..." << endl << endl;        
        cout << "~       . ...... .        ~" << endl;
        cout << " ~   .               .   ~" << endl
             << "  ~.    __       __    .~" << endl
             << " .     @@@       @@@     ." << endl
             << ".            /            ." << endl
             << ".           /             ." << endl
             << ".          /              ." << endl
             << " .     *  ----     *     ." << endl
             << "  .     *         *     ." << endl
             << "    .     *******     ." << endl
             << "       .           ." << endl
             << "            ..." << endl << endl     
             << "Through the speakers you hear: Why hello there. Nice of you to join us on the CS 162 train. During this trip, you will learn about "
             << "everything from pointers and more pointers, dynamic memory, object oriented design, file handling, inheritance and polymorphism, recursion "
             << "and linked structures, and more! That is...only if you learn how to participate! If you're wondering where everyone else is, it's because "
             << "they've all been digitalized and trapped in our system called Piazza for not participating! Sure, they didn't even know there was going to "
             << "be a participation grade to begin with, but what's done is done! Luckily for you, I tweaked the rules while in bed last night in my pajamas "
             << "and decided to begin telling students of the importance of participation right off the bat. The only way to save your classmates, and yourself "
             << "is to collect at least 5 pointers by helping solve unaswered questions left by your fellow students on Piazza. You have until we reach our "
             << "destination, CS 261. Oh, or until your energy runs out and you die of hunger. No refreshments will be served for the duration of this trip." << endl;
			 
        
        roomCompleted();
    }
    else if (completed) {
		 // when the room has already been completed, show a simple description 
         cout << "You find yourself back in the room you started. Nothing much to see here except for that same creepy face smiling at you through the speaker "
              << "panel." << endl;
    }
    
    
    
}

bool LastCar::askQuestion(int &energy) {
    
}


