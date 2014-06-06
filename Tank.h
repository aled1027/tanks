#pragma once
#include "Entity.h"

class Tank : public Entity {
    public: 
        Tank(Point, float, float, float, float, float);
        ~Tank();
    
        void moveTo(Point);
        void movePointDistance(Point, float);
    protected:

    private:
        float fire_rate;

