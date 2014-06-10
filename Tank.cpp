#include "Tank.h"

Bullet Tank::fire() {
    Bullet b(position, velocity, acceleration, direction,health, maxHealth);
    b.setDamage(1);
    outstandingBullets.push_back(b);
    return b;
}
