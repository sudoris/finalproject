#ifndef SPACE_HPP
#define SPACE_HPP

#include "Point.hpp"

using namespace std;


// abstract base clase for all rooms used in game

class Space {
    
protected:
    
    string roomName, roomDescription;
    
    Space *north;
    Space *south;
    Space *towardsFront;
    Space *towardsBack;
    
	// used to ask player a question after player chooses to search room
    virtual bool askQuestion(int &energy) = 0;
    bool completed;
    
    // flag to keep track of whether question in each room has already been answered
    void roomCompleted();
    
public:
    
    // Constructor
    Space();
    // Destructor
    ~Space();
    
    void printRoomName();
    void printRoomDescription();
    
	// gives Space pointer in other classes access to protected members, probably bad design
	friend class Game;
	friend class Train;
    
    // used to allow player to interact with each room
    virtual void action(Point **backpack, int &energy, int &itemCount) = 0;
    
};

#endif /* SPACE_HPP */
