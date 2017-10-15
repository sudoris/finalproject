#ifndef TRAIN_HPP
#define TRAIN_HPP

#include "Space.hpp"
#include "Car5.hpp"
#include "Car4.hpp"
#include "Car3.hpp"
#include "Freight.hpp"
#include "Head.hpp"

using namespace std;

class Train {
    
protected:

    // Pointers to first and last cars of the train
    Space *firstCar;
    Space *lastCar;
    
    
    
public:
    Train(); 
    ~Train();
    
    // initializes all rooms
    void loadCompartments();
    
    Space* getFirstCar();
    Space* getLastCar();
};

#endif /* TRAIN_HPP */
