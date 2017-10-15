#ifndef CAR5_HPP
#define CAR5_HPP

#include "Space.hpp"

using namespace std;

class Car5 : public Space {
    
protected:
    
    
    virtual bool askQuestion(int &energy);
    
    
    
public:
    
    // Constructor
    Car5();
    // Destructor
    ~Car5();
    
    
    friend class Space;
    virtual void action(Point **backpack, int &energy, int &itemCount);
    
};

#endif /* Car5 */