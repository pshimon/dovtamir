#include "mysdl.h"
//Screen dimension constants
#define SCREEN_WIDTH 640
#define SCREEN_HEIGHT  480
#define WALKING_ANIMATION_FRAMES 4
extern    SDL_Window* window;
extern SDL_Renderer* renderer;

int main( int argc, char* args[] )
{
        SDL_Texture* texture = 0;
        int quit=0,ret;
        SDL_Event e;
        SDL_Rect clips[WALKING_ANIMATION_FRAMES];
        SDL_Rect * current=0;
        SDL_Rect quad={0};
        int frame=0;
        ret=sdl_start( "14", SDL_WINDOWPOS_UNDEFINED,
                        SDL_WINDOWPOS_UNDEFINED,
                        SCREEN_WIDTH, SCREEN_HEIGHT,0);
        if(ret) return ret;
        ret=read_texture_ck(&texture,"../image/14.png",0,0xff,0xff);
        if(ret) return ret;

        clips[ 0 ].x =   0;
        clips[ 0 ].y =   0;
        clips[ 0 ].w =  64;
        clips[ 0 ].h = 205;

        clips[ 1 ].x =  64;
        clips[ 1 ].y =   0;
        clips[ 1 ].w =  64;
        clips[ 1 ].h = 205;

        clips[ 2 ].x = 128;
        clips[ 2 ].y =   0;
        clips[ 2 ].w =  64;
        clips[ 2 ].h = 205;

        clips[ 3 ].x = 196;
        clips[ 3 ].y =   0;
        clips[ 3 ].w =  64;
        clips[ 3 ].h = 205;

        while( !quit ) {
                while( SDL_PollEvent( &e ) != 0 ) {
                        if( e.type == SDL_QUIT ) {
                                quit = 1;
                        }
                        if( e.type == SDL_KEYDOWN ) {
                                quit=1;
                        }
                }
                SDL_SetRenderDrawColor( renderer, 0xFF, 0xFF, 0xFF, 0xFF );
                SDL_RenderClear( renderer );
                current=&clips[frame / 4];

                quad.x=(SCREEN_WIDTH - current->w ) / 2;
                quad.y=( SCREEN_HEIGHT - current->h ) / 2;
                quad.w=current->w;
                quad.h=current->h;
                SDL_RenderCopy( renderer, texture, current, &quad );        
                SDL_RenderPresent( renderer );
                frame++;
                if(frame/4>=WALKING_ANIMATION_FRAMES) {
                        frame=0;
                }
        }
        SDL_DestroyTexture(texture );
        sdl_stop();
        return 0;
}
