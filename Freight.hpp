#ifndef FREIGHT_HPP
#define FREIGHT_HPP

#include "Space.hpp"

using namespace std;

class Freight : public Space {
    
protected:
    
    
    virtual bool askQuestion(int &energy);
    
    
    
public:
    
    // Constructor
    Freight();
    // Destructor
    ~Freight();
    
    friend class Space;
    
    virtual void action(Point **backpack, int &energy, int &itemCount);
    
};

#endif /* FREIGHT */