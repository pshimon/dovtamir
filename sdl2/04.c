#include "mysdl.h"
#define WIDTH 640
#define  HEIGHT  480
extern SDL_Window *window;
enum KeyPressSurfaces
{
	KEY_PRESS_SURFACE_DEFAULT,
	KEY_PRESS_SURFACE_UP,
	KEY_PRESS_SURFACE_DOWN,
	KEY_PRESS_SURFACE_LEFT,
	KEY_PRESS_SURFACE_RIGHT,
	KEY_PRESS_SURFACE_TOTAL
};

int main( int argc, char* args[] ) {
    SDL_Surface* screenSurface = 0;
    SDL_Surface* surf[KEY_PRESS_SURFACE_TOTAL]={0};
    int quit=0,i,ret;
    char sfname[32];
    SDL_Event e;
        ret=sdl_start("04",SDL_WINDOWPOS_UNDEFINED,
                        SDL_WINDOWPOS_UNDEFINED,WIDTH, HEIGHT,0);
        if(ret) return ret;
    screenSurface = SDL_GetWindowSurface( window );
    for(i=0;i<KEY_PRESS_SURFACE_TOTAL; ++i ) {
        sprintf(sfname,"../image/%02d.bmp",i);
        surf[i]=SDL_LoadBMP(sfname);
        if( !surf[i]) {
            fprintf(stderr, "Unable to load image! SDL_Error: %s\n", SDL_GetError() );
            exit(3);
        }
    }
    i=0;
    while( !quit ){
        while( SDL_PollEvent( &e ) != 0 ) {
            if( e.type == SDL_QUIT ) quit = 1;
            if( e.type == SDL_KEYDOWN ) {
                switch( e.key.keysym.sym ) {
                    case SDLK_UP:
                        i=KEY_PRESS_SURFACE_UP;
                        break;
                    case SDLK_DOWN:
                        i=KEY_PRESS_SURFACE_DOWN;
                        break;
                    case SDLK_LEFT:
                        i=KEY_PRESS_SURFACE_LEFT;
                        break;
                    case SDLK_RIGHT:
                        i=KEY_PRESS_SURFACE_RIGHT;
                        break;
                    case SDLK_ESCAPE:
                        quit=1;
                        break;
                    default:
                        i=KEY_PRESS_SURFACE_DEFAULT;
                        break;
                }
            }
        }
  
        SDL_BlitSurface(surf[i], NULL, screenSurface, NULL );
        SDL_UpdateWindowSurface( window );
    }
    for(i=0;i<KEY_PRESS_SURFACE_TOTAL; ++i ) SDL_FreeSurface(surf[i]);
        sdl_stop();
        return 0;
}


