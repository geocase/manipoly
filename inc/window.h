#ifndef WINDOW_H
#define WINDOW_H

#include <SDL2/SDL.h>

typedef struct {
	uint8_t r, g, b, a;
} sColor_t;

class cWindow;

class cWindow {
public:
	SDL_Window *sdlwin;
	SDL_Renderer *sdlren;
	
	uint32_t winx = 640, winy = 320;
	std::string winTitle = "";

	cWindow();

	void DrawLine(uint32_t ax, uint32_t ay, uint32_t bx, uint32_t by, 
	              sColor_t c);
	void DrawLine(double ax, double ay, double bx, double by, 
	              sColor_t c);

	void Update();
};

#endif
