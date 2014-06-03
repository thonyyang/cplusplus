#include <iostream>
#include "wheel.h"

Wheel::Wheel(){
    radius = 0.0;
    flat = false; 
}

Wheel::Wheel(float new_radius){
    radius = new_radius;
    flat = false;
}

void Wheel::setRadius(float new_radius){
    radius = new_radius;
}

float Wheel::getRadius() const{
    return radius;
}

bool Wheel::isFlat() const{
    // returns true if this tire is flat.
    return flat; 
}

void Wheel::setFlat(){
    // changes this tire to flat.
    flat = true;
}

void Wheel::fixFlat(){
    // changes this tire to not flat.
    flat = false;
}
