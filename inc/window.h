#ifndef WINDOW_H
#define WINDOW_H

#include <SDL2/SDL.h>

class cWindow;

class cWindow {
public:
	SDL_Window *sdlwin;
	SDL_Renderer *sdlren;
	
	uint32_t winx = 640, winy = 320;
	std::string winTitle = "";

	cWindow();
};

#endif
