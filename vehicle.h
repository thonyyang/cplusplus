#ifndef __VEHICLE__
#define __VEHICLE__

#include <iostream>
#include <vector>
#include "wheel.h"
#include <string>

using namespace std;

class Vehicle {
    private:
        char symbol;  // racer's single character symbol
        string name;  // racer's name
        float speed;  // miles per second
        int flat_rate; // the rate at which the racer can get a flat.  The value will be between 1-100.
        vector<Wheel*> wheels;
        int total_miles_traveled;

    public:
        
        // based upon the num_wheels, this constructor should create each wheel and add it to the wheels vector.
        Vehicle(string new_name, char new_symbol, float new_speed, int new_flat_rate, int num_wheels, float new_wheel_radius);
        ~Vehicle(); // destructor. this should free up the memory that was allocated for each of the wheels.

        string getName() const;
        float getSpeed() const;
        char getSymbol() const;

        virtual int go(long elapsed_time); // the code for this is shown below.
        void display() const; // should display the name and symbol
        virtual void honkHorn() const; 
        void setMilesTraveled(int miles_traveled);
        int getMilesTraveled() const;

        int getNumFlatWheels() const ; // returns the total number of flat wheels.
        void causeFlat(); // should change at least one tire to a status of flat regardless of whether it is already flat
        void fixFlat(); // should change at least one tire to a status of not flat.
};
#endif
