#pragma once

#include <iostream>
#include <utility> // pair
#include "utils/point_vector.h"

#include "SDL/SDL.h"
#include "SDL/SDL_image.h" //if using this must add -lSDL_image to command prompt compilation line 

#include "sdl_utils.h"

class Tank;
class Bullet;

class Entity {
    public:
        Entity ();
        Entity(Point, Vector, Vector, float, float, float);
        ~Entity();

        Point getPosition() const;
        Vector getVelocity() const;
        Vector getAcceleration() const;;
        float getDirection() const;
        float getHealth() const;
        float getMaxHealth() const;
        void setVelocity(Vector);
        void printPosition();
        
        //behavior
        void moveTo(Point);
        void moveBy(Vector);
        void move(); // moves by its velocity
        // if the position is off the screen, moves the position to edge of screen and sets velocity to 0
        void checkAndFixXPosition();
        void checkAndFixYPosition();

        //SDL
        void show();
        void showDot();
        void handle_input();


    protected: 
        Point position;
        Vector velocity; // includes direction 
        Vector acceleration;
        float direction; // an angle from x-axies ie between 0 2pi
        float health;
        float maxHealth;
        virtual void getHit(Bullet); // entity should be a bullet
        virtual void die();
        //SDL
        SDL_Rect box;
        SDL_Surface *dot;
        int width; // width and height of image
        int height;
        
};

/*
void _apply_surface(int x, int y, SDL_Surface* source, SDL_Surface* destination, SDL_Rect* clip = NULL) {
	//make temp rect to hold the offsets
	SDL_Rect offset;
	offset.x = x;
	offset.y = y;
	//blit the surface
	SDL_BlitSurface(source, clip, destination, &offset);
}

SDL_Surface * _load_image (std::string filename) {
	SDL_Surface *loadedImage = NULL;
	SDL_Surface *optimizedImage = NULL;
	loadedImage = IMG_Load(filename.c_str());
	if (loadedImage != NULL) {
		optimizedImage = SDL_DisplayFormat(loadedImage);
		SDL_FreeSurface(loadedImage);
	}
	if (optimizedImage != NULL) {
		Uint32 colorkey = SDL_MapRGB(optimizedImage->format, 0xFF, 0xFF, 0xFF); //currently set to white
		SDL_SetColorKey(optimizedImage, SDL_SRCCOLORKEY, colorkey);
	}
	return optimizedImage;
}
*/

