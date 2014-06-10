#pragma once
#include "utils/point_vector.h"

#include "Entity.h"
#include "Bullet.h"
#include <vector>

class Tank : public Entity {
    public: 
        Tank(Point _p, Vector _v, Vector _a, float _d, float _h, float _m) : Entity(_p,_v,_a,_d,_h,_m) {}
        Bullet fire();
    protected:
        float fireRate;
        std::vector<Bullet> outstandingBullets;
};

