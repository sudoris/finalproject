#ifndef GAME_HPP
#define GAME_HPP

#include <string>
#include <iostream> 

#include "Train.hpp"
#include "Space.hpp"
#include "Point.hpp"

using namespace std;

class Game {
    
protected:
    Train cs162;
    // counter for items in array
    int itemCount = 0;
    Point **backpack;
    Space *currentLocation;
    
    // game ends if energy reaches 0
    int energy;
  
public:
	
	// Constructor
    Game();
	// Destructor
    ~Game();
    
    void gameMenu();
    void playGame();
    
    
    
    
    
};

#endif /* GAME_HPP */