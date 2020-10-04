#include "mysdl.h"

#define SCREEN_WIDTH 640
#define  SCREEN_HEIGHT  480
   extern SDL_Window* window;
int main( int argc, char* args[] ) {
    SDL_Surface* screenSurface = 0;
    SDL_Surface* ssurf=0;
    SDL_Surface* osurf=0;
    int quit=0,ret;
    SDL_Event e;
    
    ret=sdl_start( "06", SDL_WINDOWPOS_UNDEFINED,
            SDL_WINDOWPOS_UNDEFINED,
            SCREEN_WIDTH, SCREEN_HEIGHT,0);
    if( ret) return ret;
    screenSurface = SDL_GetWindowSurface( window );
    
    ssurf=IMG_Load("../image/Tux.png");
    if( !ssurf) {
        fprintf(stderr, "Unable to load image! SDL_Error: %s\n", SDL_GetError() );
        exit(3);
    }
    osurf = SDL_ConvertSurface(ssurf,screenSurface->format, 0);
    if( !osurf){
        fprintf(stderr, "Unable optimize surface SDL_Error: %s\n", SDL_GetError() );
        exit(4);
    }
    SDL_FreeSurface(ssurf);
    while( !quit ){
        while( SDL_PollEvent( &e ) != 0 ) {
            if( e.type == SDL_QUIT ) quit=1;

        }
        SDL_BlitSurface(osurf, NULL, screenSurface,0);
        SDL_UpdateWindowSurface( window );
    }

    SDL_FreeSurface(osurf);
    sdl_stop();
    return 0;
}
