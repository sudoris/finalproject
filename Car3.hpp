#ifndef CAR3_HPP
#define CAR3_HPP

#include "Space.hpp"

using namespace std;

class Car3 : public Space {
    
protected:
    
    
    virtual bool askQuestion(int &energy);
    
    
    
public:
    
    // Constructor
    Car3();
    // Destructor
    ~Car3();
    
    
    friend class Space;
    virtual void action(Point **backpack, int &energy, int &itemCount);
    
};

#endif /* Car3 */