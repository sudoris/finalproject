#ifndef CAR4_HPP
#define CAR4_HPP

#include "Space.hpp"

using namespace std;

class Car4 : public Space {
    
protected:
    
    
    virtual bool askQuestion(int &energy);
    
    
    
public:
    
    // Constructor
    Car4();
    // Destructor
    ~Car4();
    
    
    friend class Space;
    virtual void action(Point **backpack, int &energy, int &itemCount);
    
};

#endif /* Car4 */