#include "Entity.h"

Entity::Entity() { 
    position = Point();
    velocity = 0;
    acceleration = 0;
    direction = 0;
    health = 0;
    max_health = 0;
}

Entity::Entity (Point _position, float _velocity, float _acceleration, float _direction, float _health, float _max_health) {
    position = _position;
    velocity = _velocity;
    acceleration = _acceleration;
    direction = _direction; // an angle from x-axies ie between 0 2pi
    health = _health;
    max_health = _max_health;
}

Entity::~Entity() { }
    

Point Entity::getPosition() const {
    return position;
}

// 1. finish planning out classes
// 2. check pass-by-reference v pass-by-value
// 3. write them up
//float getVelocity() const;
//float getAcceleration() const;;
//float getDirection() const;
//float getHealth() const;
//float getMax_health() const;

