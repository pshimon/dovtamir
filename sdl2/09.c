#include "mysdl.h"
#define SCREEN_WIDTH 640
#define  SCREEN_HEIGHT  480
extern    SDL_Window* window;
extern SDL_Renderer* renderer;

int main( int argc, char* args[] ) {
    int quit=0,ret;
    SDL_Event e;
    SDL_Texture* texture = 0;
    SDL_Rect topLeftViewport;
    SDL_Rect topRightViewport;
    SDL_Rect bottomViewport;
    ret=sdl_start( "07", SDL_WINDOWPOS_UNDEFINED,
            SDL_WINDOWPOS_UNDEFINED,
            SCREEN_WIDTH, SCREEN_HEIGHT,0);
    if(ret) return ret;
        if(read_texture(&texture,"../image/viewport.png")) return 17;
    while( !quit ){
        while( SDL_PollEvent( &e ) != 0 ) {
            if( e.type == SDL_QUIT ) quit=1;
            if( e.type == SDL_KEYDOWN ) quit=1;

        }
        SDL_SetRenderDrawColor(renderer, 0, 0xFF, 0xFF, 0xFF );
        SDL_RenderClear( renderer );
        topLeftViewport.x = 0;
        topLeftViewport.y = 0;
        topLeftViewport.w = SCREEN_WIDTH / 2;
        topLeftViewport.h = SCREEN_HEIGHT / 2;
        SDL_RenderSetViewport(renderer, &topLeftViewport );
        SDL_RenderCopy(renderer, texture, NULL, NULL );
        topRightViewport.x = SCREEN_WIDTH / 2;
        topRightViewport.y = 0;
        topRightViewport.w = SCREEN_WIDTH / 2;
        topRightViewport.h = SCREEN_HEIGHT / 2;
        SDL_RenderSetViewport( renderer, &topRightViewport );
        SDL_RenderCopy(renderer, texture, NULL, NULL );
        bottomViewport.x = 0;
        bottomViewport.y = SCREEN_HEIGHT / 2;
        bottomViewport.w = SCREEN_WIDTH;
        bottomViewport.h = SCREEN_HEIGHT / 2;
        SDL_RenderSetViewport(renderer, &bottomViewport );   
        SDL_RenderCopy(renderer, texture, NULL, NULL );
        SDL_RenderPresent( renderer );

    }
    SDL_DestroyTexture(texture );
    sdl_stop();

    return 0;
}
