#ifndef LASTCAR_HPP
#define LASTCAR_HPP

#include "Space.hpp"

using namespace std;

class LastCar : public Space {
    
protected:
    
    // used to ask player a question after player chooses to search room
    virtual bool askQuestion(int &energy);
    
    
    
public:
    
    // Constructor
    LastCar();
    // Destructor
    ~LastCar();
    
    friend class Shape;
    
    virtual void action(Point **backpack, int &energy, int &itemCount);
    
};

#endif /* LASTCAR */