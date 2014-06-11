#include "Tank.h"

Tank::~Tank() {
    for (auto i=outstandingBullets.begin(); i != outstandingBullets.end(); i++) {
        if (*i) {
            delete *i;
        }
    }
}

void Tank::fire(Vector vect) {
    //Bullet b(position, velocity, acceleration, direction,health, maxHealth);
    Bullet * b = new Bullet();
    b->setPosition(position);
    b->setVelocity(vect);
    b->setDamage(1);
    outstandingBullets.push_back(b);
}

void Tank::move() {
    Entity::move();
    for (auto i=outstandingBullets.begin(); i != outstandingBullets.end(); i++) {
        if (*i) {
            (*i)->move();
        }
    }
}

void Tank::handle_input() {
    // le bug: hitting shift calls the second loop
    // research modifers -- implement better
    //
    //
    //
    Entity::printVelocity();
    if (event.type == SDL_KEYDOWN ) {
        //if (event.key.keysym.mod & KMOD_LSHIFT) {
        if (event.key.keysym.mod & KMOD_LSHIFT) {
            std::cout << "hitting here" << std::endl;
            // if we are modified with shift, then fire!
            switch( event.key.keysym.sym ) {
                case SDLK_UP: 
                    fire(Vector(0.0,-1.0)); break;
                case SDLK_DOWN: 
                    fire(Vector(0.0,1.0)); break;
                case SDLK_LEFT: 
                    fire(Vector(-1.0,0.0)); break;
                case SDLK_RIGHT: 
                    fire(Vector(1.0,0.0)); break;
                default: break;
            }
            return;
        } else {
            // otherwise, move the entity (aka set the velocity)
            switch( event.key.keysym.sym ) {
                case SDLK_UP: 
                    setVelocity(Vector(0.0,0.0,0.0,-1.0));
                    velocity.scale(2);
                    break;
                case SDLK_DOWN: 
                    setVelocity(Vector(0.0,0.0,0.0,1.0));
                    velocity.scale(2);
                    break;
                case SDLK_LEFT: 
                    setVelocity(Vector(0.0,0.0,-1.0,0.0));
                    velocity.scale(2);
                    break;
                case SDLK_RIGHT: 
                    setVelocity(Vector(0.0,0.0,1.0,0.0)); 
                    velocity.scale(2);
                    break;
                default: break;
            }
            std::cout << "here" << std::endl;
        }
    }
    Entity::printVelocity();
}

void Tank::showDot() {
    Entity::showDot();
    for (auto i=outstandingBullets.begin(); i != outstandingBullets.end(); i++) {
        if (*i) {
            (*i)->showDot();
        }
    }
}
