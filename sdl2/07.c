#include "mysdl.h"
#define SCREEN_WIDTH 640
#define  SCREEN_HEIGHT  480
extern    SDL_Window* window;
extern SDL_Renderer* renderer;

int main( int argc, char* args[] ) {
    int quit=0,ret;
    SDL_Event e;
    SDL_Texture* texture = 0;
    ret=sdl_start( "07", SDL_WINDOWPOS_UNDEFINED,
            SDL_WINDOWPOS_UNDEFINED,
            SCREEN_WIDTH, SCREEN_HEIGHT,0);
    if(ret) return ret;
        ret=read_texture(&texture,"../image/texture.png");
    if(ret) return ret;
    while( !quit ){
        while( SDL_PollEvent( &e ) != 0 ) {
            if( e.type == SDL_QUIT ) quit=1;
            if( e.type == SDL_KEYDOWN ) quit=1;
        }
        SDL_RenderClear( renderer );
        SDL_RenderCopy(renderer, texture, NULL, NULL );
        SDL_RenderPresent( renderer );

    }
    SDL_DestroyTexture(texture);
    sdl_stop();
    return 0;
}
