#pragma once

#include <iostream>
#include <utility> // pair
#include "utils/point_vector.h"

class Entity {
    public:
        Entity ();
        Entity(Point, float, float, float, float, float);
        ~Entity();

        // behavior
        void moveTo(Point);
        void moveDirectionDistance(float, float);

        // get things
        Point getPosition() const;
        float getVelocity() const;
        float getAcceleration() const;;
        float getDirection() const;
        float getHealth() const;
        float getMax_health() const;
    protected: 
        Point position;
        float velocity;
        float acceleration;
        float direction; // an angle from x-axies ie between 0 2pi
        float health;
        float max_health;
        // float armor // float damage_reduction;
};

/*
class Tank : public Entity {
    public: 
        Tank(Point, float, float, float, float, float);
        ~Tank();
    
        void moveTo(Point);
        void movePointDistance(Point, float);
    
    
    protected:
    private:
        float fire_rate;
};

*/
