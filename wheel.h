#ifndef __WHEEL__
#define __WHEEL__

using namespace std;

class Wheel {
    private:
        float radius; // radius of the tire in inches.
        bool flat;

    public:
        Wheel();
        Wheel(float new_radius);
        void setRadius(float new_radius);
        float getRadius() const;
        bool isFlat() const;  // returns true if this tire is flat.
        void setFlat(); // changes this tire to flat.
        void fixFlat(); // changes this tire to not flat.
};
#endif
