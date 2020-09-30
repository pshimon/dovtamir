#include "mysdl.h"
#define SCREEN_WIDTH 640
#define  SCREEN_HEIGHT  480
extern    SDL_Window* window;
extern SDL_Renderer* renderer;
int main( int argc, char* args[] ) {
    int quit=0,i,ret;
    SDL_Event e;
    SDL_Rect fillRect = { SCREEN_WIDTH / 4, SCREEN_HEIGHT / 4, SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2 };
    SDL_Rect outlineRect = { SCREEN_WIDTH / 6, SCREEN_HEIGHT / 6, SCREEN_WIDTH * 2 / 3, SCREEN_HEIGHT * 2 / 3 };

    ret=sdl_start( "07", SDL_WINDOWPOS_UNDEFINED,
            SDL_WINDOWPOS_UNDEFINED,
            SCREEN_WIDTH, SCREEN_HEIGHT,0);
    if(ret) return ret;
    while( !quit ){
        while( SDL_PollEvent( &e ) != 0 ) {
            if( e.type == SDL_QUIT ) quit=1;
            if( e.type == SDL_KEYDOWN ) quit=1;

        }
        SDL_SetRenderDrawColor(renderer, 0xFF, 0xFF, 0xFF, 0xFF );
        SDL_RenderClear( renderer );
        SDL_SetRenderDrawColor(renderer, 0xFF, 0x00, 0x00, 0xFF );		
	SDL_RenderFillRect( renderer, &fillRect );//Render red filled quad
        SDL_SetRenderDrawColor(renderer, 0x00, 0xFF, 0x00, 0xFF );		
	SDL_RenderDrawRect( renderer, &outlineRect );//Render green outlined quad
        SDL_SetRenderDrawColor(renderer, 0x00, 0x00, 0xFF, 0xFF );		
	SDL_RenderDrawLine(renderer, 0, SCREEN_HEIGHT / 2, SCREEN_WIDTH, SCREEN_HEIGHT / 2 );//Draw blue horizontal line
        SDL_SetRenderDrawColor(renderer, 0xFF, 0xFF, 0x00, 0xFF );
	for(i = 0; i < SCREEN_HEIGHT; i += 4 ) SDL_RenderDrawPoint(renderer, SCREEN_WIDTH / 2, i );
	SDL_RenderPresent( renderer );
    }
    sdl_stop();
    return 0;
}
