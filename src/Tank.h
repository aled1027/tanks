#pragma once
#include "../utils/point_vector.h"

#include "Entity.h"
#include "Bullet.h"
#include <vector>

class Tank : public Entity {
    public: 
        Tank() : Entity() {
            height = 20;
            width = 20;
        }
        Tank(Point _p, Vector _v, Vector _a, float _d, float _h, float _m) : Entity(_p,_v,_a,_d,_h,_m) {}
        virtual ~Tank();
        void fire(Vector);
        void handle_input();
        virtual void showImage();
        virtual void move();
    protected:
        float fireRate;
        std::vector<Bullet*> outstandingBullets;
};

