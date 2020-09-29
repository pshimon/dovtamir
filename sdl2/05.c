#include "mysdl.h"
#define WIDTH 640
#define HEIGHT  480
extern SDL_Window *window;

int main( int argc, char* args[] ) {
    SDL_Surface* screenSurface = 0;
    SDL_Surface* ssurf=0;
    SDL_Surface* osurf=0;
    int quit=0,ret;
    SDL_Event e;
    SDL_Rect stretchRect;

        ret=sdl_start("04",SDL_WINDOWPOS_UNDEFINED,
                        SDL_WINDOWPOS_UNDEFINED,WIDTH, HEIGHT,0);
        if(ret) return ret;
    screenSurface = SDL_GetWindowSurface( window );
    ssurf=SDL_LoadBMP("../image/stretch.bmp");
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
        stretchRect.x = 0;
        stretchRect.y = 0;
        stretchRect.w = WIDTH;
        stretchRect.h = HEIGHT;
        SDL_BlitScaled(osurf, NULL, screenSurface, &stretchRect );
        SDL_UpdateWindowSurface( window );
    }

        sdl_stop();
    return 0;
}
