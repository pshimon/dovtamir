/* Ported from Fabien Sanglards DoomFirePSX https://github.com/fabiensanglard/DoomFirePSX/blob/master/flames.html */
#include <SDL2/SDL.h>
#include <stdio.h>
#include <stdlib.h>

#define FIRE_WIDTH 320
#define FIRE_HEIGHT 336

SDL_Window *window = NULL;
SDL_Renderer *renderer = NULL;

static unsigned char palette[37][3] = {
	{ 0x07,0x07,0x07 },
	{ 0x1F,0x07,0x07 },
	{ 0x2F,0x0F,0x07 },
	{ 0x47,0x0F,0x07 },
	{ 0x57,0x17,0x07 },
	{ 0x67,0x1F,0x07 },
	{ 0x77,0x1F,0x07 },
	{ 0x8F,0x27,0x07 },
	{ 0x9F,0x2F,0x07 },
	{ 0xAF,0x3F,0x07 },
	{ 0xBF,0x47,0x07 },
	{ 0xC7,0x47,0x07 },
	{ 0xDF,0x4F,0x07 },
	{ 0xDF,0x57,0x07 },
	{ 0xDF,0x57,0x07 },
	{ 0xD7,0x5F,0x07 },
	{ 0xD7,0x5F,0x07 },
	{ 0xD7,0x67,0x0F },
	{ 0xCF,0x6F,0x0F },
	{ 0xCF,0x77,0x0F },
	{ 0xCF,0x7F,0x0F },
	{ 0xCF,0x87,0x17 },
	{ 0xC7,0x87,0x17 },
	{ 0xC7,0x8F,0x17 },
	{ 0xC7,0x97,0x1F },
	{ 0xBF,0x9F,0x1F },
	{ 0xBF,0x9F,0x1F },
	{ 0xBF,0xA7,0x27 },
	{ 0xBF,0xA7,0x27 },
	{ 0xBF,0xAF,0x2F },
	{ 0xB7,0xAF,0x2F },
	{ 0xB7,0xB7,0x2F },
	{ 0xB7,0xB7,0x37 },
	{ 0xCF,0xCF,0x6F },
	{ 0xDF,0xDF,0x9F },
	{ 0xEF,0xEF,0xC7 },
	{ 0xFF,0xFF,0xFF } 
};

static unsigned char fire_pixels[FIRE_WIDTH*FIRE_HEIGHT];


int handle_input(SDL_Event *e)
{
	if (e->type == SDL_KEYDOWN) {
		SDL_Keycode keycode = e->key.keysym.sym;
		if (keycode == SDLK_ESCAPE) {
			return 1;
		}
	}

	return 0;
}
void setup()
{
	int i;
	for (i = 0; i < FIRE_WIDTH; i++) {
		fire_pixels[(FIRE_HEIGHT-1)*FIRE_WIDTH+i] = 36;
	}
}

void spread_fire(int src)
{
	int pixel = fire_pixels[src];
	if (pixel == 0) {
		fire_pixels[src - FIRE_WIDTH] = 0;
	} else {
		int randIdx = (rand() % 3) & 3;
		int dst = src - randIdx + 1;
		fire_pixels[dst - FIRE_WIDTH] = pixel - (randIdx & 1);	
	}
}

void update()
{
	int x;
	int y;
	for(x = 0; x < FIRE_WIDTH; x++) {
		for(y = 1; y < FIRE_HEIGHT; y++) {
			spread_fire(y * FIRE_WIDTH + x);
		}
	}
}

void draw()
{
	int i;
	for (i = 0; i < FIRE_WIDTH*FIRE_HEIGHT; i++) {
		int x = i % FIRE_WIDTH;
		int y = i / FIRE_WIDTH;
		int r = palette[fire_pixels[i]][0];
		int g = palette[fire_pixels[i]][1];
		int b = palette[fire_pixels[i]][2];
		SDL_SetRenderDrawColor(renderer, r, g, b, 255);
		SDL_RenderDrawPoint(renderer, x, y);
	}
}

int main() {
	if (SDL_Init(SDL_INIT_VIDEO) != 0) {
		SDL_Log("Unable to initialize SDL: %s", SDL_GetError());
		return 1;
	}

	window = SDL_CreateWindow(
			"Doom Fire",
			SDL_WINDOWPOS_UNDEFINED,
			SDL_WINDOWPOS_UNDEFINED,
			FIRE_WIDTH,
			FIRE_HEIGHT,
			SDL_WINDOW_OPENGL
	);

	if (window == NULL) {
		SDL_Log("Could not create window: %s\n", SDL_GetError());
		return 1;
	}

	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

	if (renderer == NULL) {
		SDL_Log("Could not create renderer: %s\n", SDL_GetError());
		return 1;
	}
	
	setup();
	while(1) {
		SDL_Event e;
		if (SDL_PollEvent(&e)) {
			if (e.type == SDL_QUIT) {
				break;
			}
			
		}
		
		if (handle_input(&e)) {
			break;
		}

		update();

		SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
		SDL_RenderClear(renderer);
		draw();
		SDL_RenderPresent(renderer);
	}

	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	SDL_Quit();
	return 0;
}
