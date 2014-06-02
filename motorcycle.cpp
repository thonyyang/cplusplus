#include "motorcycle.h"
#include <iostream>

using namespace std;

Motorcycle::Motorcycle(string name, char new_symbol, float new_speed, float new_wheel_radius): Vehicle(name, new_symbol, new_speed, FLAT_RATE, NUM_WHEELS, new_wheel_radius){
}

int Motorcycle::go(long elapsed_time){
    // calls the base class go and then randomly increases the miles due to a turbo boost.
    int distance = 0;
   distance = Vehicle::go(elapsed_time);
    int boost = (rand() % 100) + 1;
    if(boost >= 55){
        distance = distance +  1;
    }
    Vehicle::setMilesTraveled(distance);
    // BB didn't tell the base class that you changed the value.
    return distance;
}

void Motorcycle::honkHorn() const{
    // displays something that represents this type of horn.
    cout << "BEEP BEEP" << endl;
}

