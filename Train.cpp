#include <iostream>
#include "Train.hpp"
#include "LastCar.hpp"
#include "Car5.hpp"
#include "Car4.hpp"
#include "Car3.hpp"
#include "Freight.hpp"
#include "Head.hpp"

using namespace std;

Train::Train() {
    // front
	firstCar = 0;
	// rear
    lastCar = 0;
}

Train::~Train() {
    Space *garbage = lastCar;
	while (garbage->towardsFront != firstCar) {
		lastCar = lastCar->towardsFront;
		delete garbage;
		garbage = lastCar;
	}
	
	delete garbage;
	delete firstCar;
}

// used to initialize rooms prior to start of the game
void Train::loadCompartments() {
    
    cout << "The train has arrived..." << endl << endl;
    
    Space *temp = 0;
    
    lastCar = new LastCar();
    lastCar->towardsFront = new Car5();
    temp = lastCar->towardsFront;
    temp->towardsBack = lastCar;
    
    temp->towardsFront = new Car4();
    temp->towardsFront->towardsBack = temp;
    temp = temp->towardsFront;
    
    temp->towardsFront = new Car3();
    temp->towardsFront->towardsBack = temp;
    temp = temp->towardsFront;
    
    temp->towardsFront = new Freight();
    temp->towardsFront->towardsBack = temp;
    temp = temp->towardsFront;
    
    temp->towardsFront = new Head();
    firstCar = temp->towardsFront;
    firstCar->towardsBack = temp;
    
    temp = 0;
    
    
    
}

Space* Train::getLastCar() {
	return lastCar;
}

Space* Train::getFirstCar() {
	return firstCar;
}




