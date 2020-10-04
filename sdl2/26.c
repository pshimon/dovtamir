#include "mysdl.h"

//Screen dimension constants
#define SCREEN_WIDTH 640
#define SCREEN_HEIGHT  480
#define DOT_WIDTH 20
#define DOT_HEIGHT 20
#define DOT_VEL 1 // velocity step
extern    SDL_Window* window;
    extern SDL_Renderer* renderer;

int main( int argc, char* args[] )
{
    SDL_Texture* texture = 0;
    int quit=0,ret;
    SDL_Event e;
    int dot[4]={0};//x,y,vx,vy
    SDL_Rect quad;
    ret=sdl_start( "26", SDL_WINDOWPOS_UNDEFINED,
            SDL_WINDOWPOS_UNDEFINED,
            SCREEN_WIDTH, SCREEN_HEIGHT,SDL_WINDOW_SHOWN);
    if(ret) return ret;
        ret=read_texture(&texture,"../image/26.bmp");
    if(ret) return ret;
    quad.w=DOT_WIDTH;
    quad.h=DOT_HEIGHT;
   
    while( !quit ) {
        while( SDL_PollEvent( &e ) != 0 ) {
            if( e.type == SDL_QUIT ) {
                quit = 1;
            }
            if( e.type == SDL_KEYDOWN && e.key.repeat == 0 ) {
                switch( e.key.keysym.sym ) {
                    case SDLK_UP: dot[3] -= DOT_VEL; break;
                    case SDLK_DOWN: dot[3] += DOT_VEL; break;
                    case SDLK_LEFT: dot[2] -= DOT_VEL; break;
                    case SDLK_RIGHT: dot[2] += DOT_VEL; break;
                    default: quit=1;
                }
            }            
        }
        dot[0]+=dot[2];
        dot[1]+=dot[3];
        if(dot[0]<0) dot[0]=SCREEN_WIDTH;
        if(dot[0]>SCREEN_WIDTH) dot[0]=0;
        if(dot[1]<0) dot[1]=SCREEN_HEIGHT;
        if(dot[1]>SCREEN_HEIGHT) dot[1]=0;
        quad.x=dot[0]-DOT_WIDTH/2;
        quad.y=dot[1]-DOT_HEIGHT/2;

        SDL_SetRenderDrawColor( renderer, 0xFF, 0xFF, 0xFF, 0xFF );
        SDL_RenderClear( renderer );
        SDL_RenderCopy( renderer, texture, NULL, &quad );
        SDL_RenderPresent( renderer );
    }
	SDL_DestroyTexture(texture );
        sdl_stop();
	return 0;
}
