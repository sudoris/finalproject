#include <iostream>
#include <string>

#include "Game.hpp"

using namespace std;

// Const
Game::Game() {
	
    energy = 100;
    backpack = new Point*[5];
    
    cs162.loadCompartments();
}

// Dest
Game::~Game() {
    for (int i = 0; i < 5; i++) {
		delete backpack[i];
	}	
	delete [] backpack;
	
	
	
	
}

// Menu
void Game::gameMenu() {
    
    // print intro to game
    cout << "(      _______-=================-____)" << endl;	
    cout << "(    _(          All aboard!!        )_)" << endl;       
    cout << "(    (                                ))" << endl;   
    cout << "(    (       To CS 162 and beyond!!   ) Oo)" << endl;    
    cout << "(     (______________________________)    0o)" << endl;
    cout << "(    _____                                  o.)" << endl;
    cout << "(  __|[_]|__ ___________ _______    ____      .)" << endl;
    cout << "( |[] [] []| [] [] [] [] [_____(__  ][]]__n_n_][.)" << endl;
    cout << "(_|________|_[_________]_[________]_|__|________)<)" << endl;
    cout << "(  oo    oo 'oo      oo ' oo    oo 'oo 0000---oo\\_)" << endl;
    cout << "(~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~)" << endl << endl;          
             
    cout << "You arrive right as the train is about to leave the station and quickly get on from the back of the train. " 
         << "Upon boarding, you look down at your ticket to see what car your seat is in. It reads: Coach 6 Row 4 Seat A. "
         << "You look up and see a sign indicating that you are currently already in Coach 6. You look around the empty "
         << "compartment and wonder to yourself, \"Where is everyone else? And why are there no seats?!\ You even bought "
         << "a first class ticket! You walk over and peer through the window to the next car but don't see anyone." << endl << endl;
         
    // set current location of player to be the last car of the train (player gets on train from the back)
    currentLocation = cs162.getLastCar();
    
	// launch game
    playGame();
    
}

// main body of game
void Game::playGame() {
    
	// run game until energy reaches 0 or 5 Point items are added to the player's backpack
    while (energy > 0 && itemCount < 5) {
        string input;
        
        currentLocation->printRoomName();
        cout << endl;
        
        currentLocation->printRoomDescription();
        
        cout << endl;
        
		// if player is currently in the first car, give only the option of moving towards the back
        if (currentLocation == cs162.getFirstCar()) {
            cout << "You can move towards the back ('b') of the train." << endl;
        }
        else if (currentLocation == cs162.getLastCar()) {
			// player is only given option of moving towards the front if they are in the last car 
            cout << "You can move towards the front ('f') of the train." << endl;
        }
        else {
			// player can move either towards the front or towards the back when they are in any other car
            cout << "You can move towards the front ('f') or back ('b') of the train." << endl;
        }
        
        cout << "> ";
        
        //getline(cin, input, '\n');
        
		cin >> input;
		
		while (input != "f"  && input != "front" && input != "b" && input != "back" && input != "s" && input != "search") {
            cin.clear();
			cin.ignore(256, '\n');
			
			
            cout << "What?" << endl;
            cout << "> "; 
            //getline(cin, input);
		    cin >> input;
			
        }
		
		cout << endl;
		
		
        if (input == "f" || input == "front") {
            cout << "You move towards the front of the train." << endl;
            cout << "The door to the next compartment is abnormally heavy." << endl;
            cout << "You hear snickering over the speakers, \"A bit out of shape are we?\"" << endl;
            cout << "You spend 5 energy pushing the door open." << endl;
            
            energy-=5;
            currentLocation = currentLocation->towardsFront;
            if (energy < 0) {
		        break;
		    }
        }
        else if (input == "b" || input == "back") {
            cout << "You move towards the back of the train." << endl;
            cout << "The door to the next compartment creaks and groans as you push against it." << endl;
            cout << "You finally push your way into the next compartment, but spend 5 energy doing so." << endl;
            cout << "You regret not eating breakfast this morning as your stomach begins to growl." << endl;
            cout << "The door swings shut again behind  you." << endl;
            
            energy-=5;
            currentLocation = currentLocation->towardsBack;
            if (energy < 0) {
		        break;
		    }
        }
        else if (input == "s" || input == "search") {
			// if player chooses to search the room, the action function is called to provide interaction with room player is currently in
            currentLocation->action(backpack, energy, itemCount);
            if (energy < 0) {
		        break;
		    }
		    
        }
		
		cout << endl;
		
		// show energy and number of Points after each round
		cout << "You have " << energy << " energy left" << endl;
		cout << "You currently have " << itemCount << " points in your backpack." << endl;
		
		
		cout << endl;
        
        
        
    }
    
	// if game ends due to energy reaching 0, print message telling player that they have died
    if (energy <= 0) {
        cout << "You have died of hunger and fatigue." << endl;
        
    }
    else {
		// if game ends due to player successfully collecting 5 points, print ending storyline
        cout << "Just as you collect your 5th point, you hear over the loudspeakers: Attention passenger! We are now arriving at the city of Data Strucutres. "
              << "I see that you have managed to collect 5 participation points just in time for our arrival. Good job. You have saved yourself and your "
              << "classmates." << endl << endl;
        
        cout << "As you prepare to get off the train, the Points in your backpack turn into beams of " 
				<< "light and shoot off towards the front and back of the train, lifting the curse of "
				<< "non-participation once and for all, or at least for now. Other students begin pouring "
				<< "in to the room to congratulate you. Some even call you a \"hero\". You're just glad that "
				<< "you won't have to take CS 261 by yourself." << endl << endl << endl;
		
		// sources for ASCII image
		cout << "Sources for ASCII images:" << endl; 
		cout << "Train - http://www.ascii-art.de/ascii/t/train.txt" << endl;
		cout << "Devil face - http://www.ascii-code.com/ascii-art/mythology/devils.php" << endl;
    }
    
    
}


