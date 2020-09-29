#include "mysdl.h"
extern SDL_Window *window;
#define WIDTH 640
#define  HEIGHT  480
int main( int argc, char* args[] ) {
        int ret;
    SDL_Surface* screenSurface = 0;
    SDL_Surface* helloWorld = 0;
        ret=sdl_start("02",SDL_WINDOWPOS_UNDEFINED,
                        SDL_WINDOWPOS_UNDEFINED,WIDTH, HEIGHT,0);
        if(ret) return ret;
    screenSurface = SDL_GetWindowSurface( window );
    helloWorld = SDL_LoadBMP( "../image/hello_world.bmp" );
    if( !helloWorld) {
        fprintf(stderr, "Unable to load image! SDL_Error: %s\n", SDL_GetError() );
        exit(3);
    }
    SDL_BlitSurface( helloWorld, NULL, screenSurface, NULL );
    SDL_UpdateWindowSurface( window );			
    SDL_Delay( 2000 );
    SDL_FreeSurface( helloWorld );
        sdl_stop();
    exit(0);
}
