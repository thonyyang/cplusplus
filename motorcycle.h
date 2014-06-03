#ifndef __MOTORCYCLE__
#define __MOTORCYCLE__

#include <iostream>
#include <string>
#include <cstdlib>
#include "vehicle.h"

using namespace std;

class Motorcycle : public Vehicle {
    private:
        static const int NUM_WHEELS = 2;
        static const int FLAT_RATE = 40;
 
    public:
        Motorcycle(string name, char new_symbol, float new_speed, float new_wheel_radius);
        int go(long elapsed_time); // calls the base class go and then randomly increases the miles due to a turbo boost.
        void honkHorn() const; // displays something that represents this type of horn.
};
#endif
