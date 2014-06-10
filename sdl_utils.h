#pragma once

#include <iostream>
#include "SDL/SDL.h"
#include "SDL/SDL_image.h" //if using this must add -lSDL_image to command prompt compilation line 
#include "SDL/SDL_ttf.h" //if using this must add -lSDL_ttf to command prompt compilation line 


extern SDL_Event event;
extern SDL_Surface *screen;
extern const int SCREEN_WIDTH;
extern const int SCREEN_HEIGHT;

SDL_Surface * load_image(std::string filename);
void apply_surface(int, int, SDL_Surface*, SDL_Surface*, SDL_Rect*);

class Timer
{
	private:
	int startTicks;
	//the ticks stored when timer is paused
	int pausedTicks;

	bool paused;
	bool started;

	public:
	Timer();
	void start();
	void stop();
	void pause();
	void unpause();

	int get_ticks();
	
	bool is_started();
	bool is_paused();
};


