#ifndef HEAD_HPP
#define HEAD_HPP

#include "Space.hpp"

using namespace std;

class Head : public Space {
    
protected:
    
    
    virtual bool askQuestion(int &energy);
    
    
    
public:
    
    // Constructor
    Head();
    // Destructor
    ~Head();
    
    
    friend class Space;
    virtual void action(Point **backpack, int &energy, int &itemCount);
    
};

#endif /* HEAD */