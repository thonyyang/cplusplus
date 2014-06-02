#include "vehicle.h"
#include <iostream>
#include <ctime>
#include <cstdlib>
        
        // based upon the num_wheels, this constructor should create each wheel and add it to the wheels vector.
Vehicle::Vehicle(string new_name, char new_symbol, float new_speed, int new_flat_rate, int num_wheels, float new_wheel_radius){
    total_miles_traveled = 0;
    name = new_name;
    symbol = new_symbol;
    speed = new_speed;
    flat_rate = new_flat_rate;
    for(int i = 0; i < num_wheels; i++){
        wheels.push_back(new Wheel(new_wheel_radius));
    }
}
Vehicle::~Vehicle(){
    // destructor. this should free up the memory that was allocated for each of the wheels.
    while(wheels.size() != 0){
        wheels[] delete;
       // wheels.pop_back();  // BB -1 this doesn't free up the memory.
    }
}

string Vehicle::getName() const{
    return name;
}

float Vehicle::getSpeed() const{
    return speed;
}

char Vehicle::getSymbol() const{
    return symbol;
}

int Vehicle::go(long elapsed_time) {
    int damage = (rand() % 100) + 1;
    if (damage <= flat_rate) {
        causeFlat();
    } else {
        fixFlat();
    }
    float actual_speed = (wheels.size() - getNumFlatWheels())/(float)wheels.size() * speed;
    total_miles_traveled = total_miles_traveled + (elapsed_time * actual_speed);
    return total_miles_traveled;
}
void Vehicle::display() const{
    // should display the name and symbol
    cout << getName() << " symbol: " << getSymbol() << endl;
}
void Vehicle::honkHorn() const{
    cout << "HONK!" << endl;
}

void Vehicle::setMilesTraveled(int miles_traveled){
   total_miles_traveled = miles_traveled; 
}

int Vehicle::getMilesTraveled() const{
    return total_miles_traveled;
}

int Vehicle::getNumFlatWheels() const{
    // returns the total number of flat wheels.
    int num_flats = 0;
    
    for(int i = 0; i < wheels.size(); i++){
        Wheel* w = wheels[i];
        if(w->isFlat()){ 
          num_flats++;
        }
    }
    return num_flats;
}
void Vehicle::causeFlat(){
    // should change at least one tire to a status of flat regardless of whether it is already flat
    for(int i = 0; i < wheels.size(); i++){
        Wheel* e = wheels[i];
        if(!e->isFlat()){ 
          e->setFlat();
          break;
        }
    }
}
void Vehicle::fixFlat(){
    // should change at least one tire to a status of not flat.
    for(int i = 0; i < wheels.size(); i++){
        Wheel* r = wheels[i];
        if(r->isFlat()){ 
          r->fixFlat();
          break;
        }
    }
}

