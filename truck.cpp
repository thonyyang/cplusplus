#include "truck.h"
#include <iostream>

Truck::Truck(string new_name, char new_symbol, float new_speed, float new_wheel_radius, bool new_has_hitch): Vehicle(new_name, new_symbol, new_speed, FLAT_RATE, NUM_WHEELS, new_wheel_radius) {
    // BB -1 hitch?
}

int Truck::go(long elapsed_time){
    // calls the base class go and then randomly will increase the miles due to a nitro burst.
    int distance = 0;
   distance  = Vehicle::go(elapsed_time);

    int boost = (rand() % 100) + 1;
    if(boost >= 70){
        distance = distance + 2;
    }
    Vehicle::setMilesTraveled(distance);
    // BB -1 didn't tell the base class that you changed the value.
    return distance;
}

void Truck::honkHorn() const{
    // displays something that represents this type of horn.
    cout << "BUULLL HOORN" << endl;
}
