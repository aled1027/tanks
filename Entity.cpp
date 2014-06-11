#include "Entity.h"
#include "Bullet.h"

Entity::Entity() { 
    position = Point();
    velocity = Vector(0.0, 0.0, 0.0, 0.0);
    acceleration = Vector(0.0, 0.0, 0.0, 0.0);
    direction = 0;
    health = 0;
    maxHealth = 0;

    box.x = 0;
    box.y = 0;
    box.w = 20;
    box.h = 20;

    dot = load_image("images/dot.bmp");
    width = 10;
    height = 10;
}

Entity::Entity (Point _position, Vector _velocity, Vector _acceleration, float _direction, float _health, float _maxHealth) {
    position = _position;
    velocity = _velocity;
    acceleration = _acceleration;
    direction = _direction; // an angle from x-axies ie between 0 2pi
    health = _health;
    maxHealth = _maxHealth;

    box.x = 0;
    box.y = 0;
    box.w = 20;
    box.h = 20;

    dot = load_image("images/dot.bmp");
    width = 10;
    height = 10;
}
Entity::~Entity() {
    SDL_FreeSurface(dot);
}
Point Entity::getPosition() const {
    return position;
}
Vector Entity::getVelocity() const {
    return velocity;
}

Vector Entity::getAcceleration() const {
    return acceleration;
}
float Entity::getDirection() const {
    return direction;
}
float Entity::getHealth() const {
    return health;
}
float Entity::getMaxHealth() const {
    return maxHealth;
}

void Entity::setPosition(Point p) {
    position = p;
}
void Entity::setVelocity(Vector v) {
    velocity = v;
}

void Entity::printPosition() {
    std::cout << "entity position: ";
    position.print();
    std::cout << std::endl;
}
void Entity::printVelocity() {
    std::cout << "entity velocity: ";
    velocity.print();
    std::cout << std::endl;
}

//behavior
void Entity::moveTo(Point p) {
    position = p;
}
void Entity::moveBy(Vector v) {
    position = position + v;
}

void Entity::move() {

    position = position + velocity;
    checkAndFixXPosition();
    checkAndFixYPosition();
}

void Entity::checkAndFixXPosition() {
    // returns false if position is off the screen
    auto pair = position.getPair();
    if ((pair.first<0)) {
        position.setX(0);
        velocity = Vector();
    } else if (pair.first > SCREEN_WIDTH) {
        position.setX(SCREEN_WIDTH-width);
        velocity = Vector();
    }
}

void Entity::checkAndFixYPosition() {
    // returns false if position is off the screen
    auto pair = position.getPair();
    if ((pair.second<0)) {
        position.setY(0);
        velocity = Vector();
    } else if (pair.second > SCREEN_HEIGHT) {
        position.setY(SCREEN_HEIGHT-height);
        velocity = Vector();
    }
}

void Entity::getHit(Bullet b) {
    //health -= b.getDamage();
    if (health < 0) {
        this->die();
    } 
}

void Entity::die() {
    std::cout << "this entity died" << std::endl;
}

void Entity::show() {
    SDL_FillRect(screen, &box, SDL_MapRGB( screen->format, 0x77, 0x77, 0x77 ) );
}
void Entity::showDot() {
    auto pair = position.getPair();
    float x = pair.first;
    float y = pair.second;
    apply_surface(x, y, dot, screen, NULL);
}


