#include "Tank.h"

Tank::~Tank() {
    for (auto i=outstandingBullets.begin(); i != outstandingBullets.end(); i++) {
        if (*i) {
            delete *i;
        }
    }
}

void Tank::fire(Vector vect) {
    Bullet * b = new Bullet();

    auto vect2 = vect;

    if (vect == Vector(0.0,-1.0)) {
        // going up
        vect2.scale(2*height);
        b->setPosition(position + vect2);
    } else if (vect == Vector(0.0,1.0)) {
        // going down
        vect2.scale(2*height);
        b->setPosition(position + vect2);
    } else if (vect == Vector(1.0,0.0)) {
        // going right 
        vect2.scale(1.3*width);
        b->setPosition(position + vect2);
    } else {
        // going left 
        vect2.scale(2*width);
        b->setPosition(position + vect2);
    }
    vect.scale(4);
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
    if (event.type == SDL_KEYDOWN ) {
        //if (event.key.keysym.mod & KMOD_LSHIFT) {
        if (event.key.keysym.mod & KMOD_LSHIFT) {
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
        } else {
            // otherwise, move the entity (aka set the velocity)
            switch( event.key.keysym.sym ) {
                case SDLK_SPACE:
                    velocity = Vector();
                    break;
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
        }
    }
}

void Tank::showImage() {
    Entity::showImage();
    for (auto i=outstandingBullets.begin(); i != outstandingBullets.end(); i++) {
        if (*i) {
            (*i)->showImage();
        }
    }
}
