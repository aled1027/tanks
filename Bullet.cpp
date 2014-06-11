#include "Bullet.h"

void Bullet::setDamage(int d) {
    damage = d;
}
int Bullet::getDamage() {
    return damage;
}
void Bullet::move() {
    Entity::move();
}
