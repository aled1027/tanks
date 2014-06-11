#include "utils/point_vector.h"
#include "Entity.h"
#include "Tank.h"

#include <iostream>
#include <string>
#include <sstream>

#include "SDL/SDL.h"
#include "SDL/SDL_image.h" //if using this must add -lSDL_image to command prompt compilation line 
#include "SDL/SDL_ttf.h" //if using this must add -lSDL_ttf to command prompt compilation line 

#include "utils/sdl_utils.h"

const int SCREEN_BPP = 32; //bits per pixel
const int FRAMES_PER_SECOND = 50;

const int SCREEN_WIDTH = 600;
const int SCREEN_HEIGHT = 400;

SDL_Event event;
SDL_Surface *screen = NULL;

bool init();
bool load_files();
void clean_up();

int main() {
	//Generate the message surfaces ... tut author says we should probably check for errors...
	bool quit = false;
	if (init() == false) {
		std::cout << "\nError with init\n";
		return 1;
	}
    //---------------fps management-----------
    Timer fps;
    
	//---------------initialize and declare --------------
    Tank tank;
    
    //---------------main loop---------------
	while (quit == false) {
        fps.start();
        //------------handle input-----------------
		while (SDL_PollEvent(&event)) {
            tank.handle_input();
			if (event.type == SDL_QUIT) { quit = true; }
		}

        tank.move();

        //----------------print things to screen------------------------
        // make background white
        SDL_FillRect( screen, &screen->clip_rect, SDL_MapRGB( screen->format, 0xFF, 0xFF, 0xFF ) ); 
        tank.showDot();
	    //Update the screen
	    if( SDL_Flip( screen ) == -1 ) { return 1; }

        if ( fps.get_ticks() < 1000 / FRAMES_PER_SECOND ) {
            SDL_Delay( (1000/FRAMES_PER_SECOND) - fps.get_ticks() );
        }
	}
    //---------------clean up and exit----------------
	clean_up();
    std::cout << "exiting..." << std::endl;
	return 0;
}

//-------------some boring sdl functions ------------------
bool init() {
	if (SDL_Init( SDL_INIT_EVERYTHING ) == -1) {
		return 1;
	}
	screen = SDL_SetVideoMode(SCREEN_WIDTH, SCREEN_HEIGHT, SCREEN_BPP, SDL_SWSURFACE);
	if (screen == NULL) {
		return 1;
	}
	if (TTF_Init() == -1) {
		return 1;
	}
	SDL_WM_SetCaption("Hello World", NULL);
	return true;
}


void clean_up() {
	SDL_FreeSurface (screen);
	TTF_Quit();
	SDL_Quit();
}
