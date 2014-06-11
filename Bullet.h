#pragma once

#include "Entity.h"

class Bullet : public Entity {
    public:
        Bullet() : Entity() {}
        Bullet(Point _p, Vector _v, Vector _a, float _d, float _h, float _m) : Entity(_p,_v,_a,_d,_h,_m) {}
        virtual ~Bullet() {}
        int getDamage();
        void setDamage(int);
        virtual void move();
    private:
        int damage;

};
