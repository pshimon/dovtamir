#include "mysdl.h"
#define SCREEN_WIDTH 640
#define  SCREEN_HEIGHT  480
extern    SDL_Window* window;
extern SDL_Renderer* renderer;

int main( int argc, char* args[] )
{
        SDL_Texture* presstexture = 0;
        SDL_Texture* uptexture = 0;
        SDL_Texture* downtexture = 0;
        SDL_Texture* lefttexture=0;
        SDL_Texture* righttexture=0;
        SDL_Texture* currenttexture=0;
        int quit=0,ret;
        SDL_Event e;
        const Uint8* currentkeystates;
        ret=sdl_start( "10", SDL_WINDOWPOS_UNDEFINED,
                        SDL_WINDOWPOS_UNDEFINED,
                        SCREEN_WIDTH, SCREEN_HEIGHT,0);
        if(ret) return ret;
        ret=read_texture(&presstexture,"../image/press.png");
        if(ret) return ret;
        ret=read_texture(&uptexture,"../image/up.png");
        if(ret) return ret;
        ret=read_texture(&downtexture,"../image/down.png");
        if(ret) return ret;
        ret=read_texture(&lefttexture,"../image/left.png");
        if(ret) return ret;
        ret=read_texture(&righttexture,"../image/right.png");
        if(ret) return ret;
        while( !quit ) {
                while( SDL_PollEvent( &e ) != 0 ) {
                        if( e.type == SDL_QUIT ) {
                                quit = 1;
                        }
                        currentkeystates = SDL_GetKeyboardState( NULL );
                        if( currentkeystates[ SDL_SCANCODE_UP ] )
                        {
                                currenttexture = uptexture;
                        }
                        else if( currentkeystates[ SDL_SCANCODE_DOWN ] )
                        {
                                currenttexture = downtexture;
                        }
                        else if( currentkeystates[ SDL_SCANCODE_LEFT ] )
                        {
                                currenttexture = lefttexture;
                        }
                        else if( currentkeystates[ SDL_SCANCODE_RIGHT ] )
                        {
                                currenttexture = righttexture;
                        }
                        else
                        {
                                currenttexture = presstexture;
                        }
                }
                SDL_SetRenderDrawColor( renderer, 0xFF, 0xFF, 0xFF, 0xFF );
                SDL_RenderClear( renderer );
                SDL_RenderCopy( renderer, currenttexture, NULL, NULL );
                SDL_RenderPresent( renderer );
        }
        SDL_DestroyTexture(presstexture );
        SDL_DestroyTexture(uptexture );
        SDL_DestroyTexture(downtexture);
        SDL_DestroyTexture(lefttexture);
        SDL_DestroyTexture(righttexture);
        SDL_DestroyTexture(currenttexture);
        sdl_stop();
        return 0;
}
