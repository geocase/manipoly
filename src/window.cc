#include <iostream>
#include <SDL2/SDL.h>

#include "window.h"

cWindow::cWindow() {
	this->sdlwin = SDL_CreateWindow(this->winTitle.c_str(),
	                                SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
	                                this->winx, this->winy,
	                                SDL_WINDOW_SHOWN);
	
	this->sdlren = SDL_CreateRenderer(this->sdlwin, -1, SDL_RENDERER_SOFTWARE);
	if(this->sdlren && this->sdlwin) {
		std::cout << "Created window and renderer" << std::endl;
	} else {
		std::cout << "SDL_ERROR" << std::endl << SDL_GetError() << std::endl;
	}
}
