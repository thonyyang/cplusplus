#ifndef __TRUCK__
#define __TRUCK__

#include <iostream>
#include <string>
#include <cstdlib>
#include "vehicle.h"

using namespace std;

class Truck : public Vehicle {
    private:
        bool has_hitch;
        static const int NUM_WHEELS= 4;
        static const int FLAT_RATE = 25;

    public:
        Truck(string new_name, char new_symbol, float new_speed, float new_wheel_radius, bool new_has_hitch);
        int go(long elapsed_time); // calls the base class go and then randomly will increase the miles due to a nitro burst.
        void honkHorn() const; // displays something that represents this type of horn.
};
#endif
