#include "mysdl.h"
#define SCREEN_WIDTH 640
#define  SCREEN_HEIGHT  480
extern    SDL_Window* window;
extern SDL_Renderer* renderer;

int main( int argc, char* args[] )
{
    SDL_Texture* foo_texture = 0;
    SDL_Texture* bg_texture = 0;
    int quit=0,ret;
    SDL_Event e;
    SDL_Rect quad;
    ret=sdl_start( "10", SDL_WINDOWPOS_UNDEFINED,
            SDL_WINDOWPOS_UNDEFINED,
            SCREEN_WIDTH, SCREEN_HEIGHT,0);
    if(ret) return ret;
        ret=read_texture(&foo_texture,"../image/foo.png");
    if(ret) return ret;
        ret=read_texture(&bg_texture,"../image/background.png");
    if(ret) return ret;
    while( !quit ) {
        while( SDL_PollEvent( &e ) != 0 ) {
            if( e.type == SDL_QUIT ) {
                quit = 1;
            }
            if( e.type == SDL_KEYDOWN ) quit=1;
        }
        SDL_SetRenderDrawColor( renderer, 0xFF, 0xFF, 0xFF, 0xFF );
        SDL_RenderClear( renderer );
        quad.x=0;
        quad.y=0;

        SDL_QueryTexture(bg_texture, NULL, NULL, &quad.w, &quad.h);
        SDL_RenderCopy( renderer, bg_texture, NULL, &quad );
        quad.x=240;
        quad.y=190;
        SDL_QueryTexture(foo_texture, NULL, NULL, &quad.w, &quad.h);
        SDL_RenderCopy( renderer, foo_texture, NULL, &quad );
        
        SDL_RenderPresent( renderer );
    }
	SDL_DestroyTexture(foo_texture );
        SDL_DestroyTexture(bg_texture );
    sdl_stop();
	return 0;
}
