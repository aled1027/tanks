#include "sdl_utils.h"

SDL_Surface * load_image(std::string filename) {
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


void apply_surface(int x, int y, SDL_Surface* source, SDL_Surface* destination, SDL_Rect* clip = NULL) {
	SDL_Rect offset;
	offset.x = x;
	offset.y = y;
	SDL_BlitSurface(source, clip, destination, &offset);
}

Timer::Timer()
{
	startTicks = 0;
	pausedTicks = 0;
	paused = false;
	started = false;
}
void Timer::start()
{
	started = true;
	paused = false;
	startTicks = SDL_GetTicks();
}
void Timer::stop()
{
	started = false;
	paused = false;
}
int Timer::get_ticks()
{
	if (started == true) {
		if (paused == true) {
			return pausedTicks;
		}
		else {
			return SDL_GetTicks() - startTicks;
		}
	}
	return 0; //if timer isn't running
}
void Timer::pause()
{
	if ( (started == true) && (paused == false) ) {
		paused == true;
		pausedTicks == SDL_GetTicks() - startTicks;
	}
}
void Timer::unpause()
{
	if (paused == true) {
		paused = false;
		startTicks = SDL_GetTicks() - pausedTicks;
		pausedTicks = 0;
	}
}
bool Timer::is_started() {
	return started;
}
bool Timer::is_paused() {
	return paused;
}


