#include "mysdl.h"
#define SCREEN_WIDTH 640
#define  SCREEN_HEIGHT  480
extern    SDL_Window* window;
extern SDL_Renderer* renderer;

int main( int argc, char* args[] )
{
        int quit=0,ret;
        SDL_Texture* texture = 0;
        SDL_Event e;
        SDL_Rect spriteclips[ 4 ];
        SDL_Rect quad;
        ret=sdl_start( "11", SDL_WINDOWPOS_UNDEFINED,
                        SDL_WINDOWPOS_UNDEFINED,
                        SCREEN_WIDTH, SCREEN_HEIGHT,SDL_WINDOW_SHOWN);
        if(ret) return ret;
        ret=read_texture_ck(&texture,"../image/dots.png",0,0xff,0xff);
        if(ret) return ret;
        spriteclips[ 0 ].x =   0;
        spriteclips[ 0 ].y =   0;
        spriteclips[ 0 ].w = 100;
        spriteclips[ 0 ].h = 100;

        spriteclips[ 1 ].x = 100;
        spriteclips[ 1 ].y =   0;
        spriteclips[ 1 ].w = 100;
        spriteclips[ 1 ].h = 100;

        spriteclips[ 2 ].x =   0;
        spriteclips[ 2 ].y = 100;
        spriteclips[ 2 ].w = 100;
        spriteclips[ 2 ].h = 100;

        spriteclips[ 3 ].x = 100;
        spriteclips[ 3 ].y = 100;
        spriteclips[ 3 ].w = 100;
        spriteclips[ 3 ].h = 100;

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
                quad.w = spriteclips[ 0 ].w;
                quad.h = spriteclips[ 0 ].h;
                SDL_RenderCopy( renderer, texture,spriteclips , &quad );
                quad.x=SCREEN_WIDTH - spriteclips[ 1 ].w;
                quad.y=0;
                quad.w = spriteclips[ 1 ].w;
                quad.h = spriteclips[ 1 ].h;
                SDL_RenderCopy( renderer, texture,spriteclips +1, &quad );
                quad.x=0;
                quad.y=SCREEN_HEIGHT - spriteclips[ 2 ].h;
                quad.w = spriteclips[ 2 ].w;
                quad.h = spriteclips[ 2 ].h;
                SDL_RenderCopy( renderer, texture,spriteclips+2 , &quad );
                quad.x=SCREEN_WIDTH - spriteclips[ 3 ].w;
                quad.y=SCREEN_HEIGHT - spriteclips[ 3 ].h;
                quad.w = spriteclips[ 3 ].w;
                quad.h = spriteclips[ 3 ].h;
                SDL_RenderCopy( renderer, texture,spriteclips+3 , &quad );
                SDL_RenderPresent( renderer );
        }
        SDL_DestroyTexture(texture );
        sdl_stop();
        return 0;
}
