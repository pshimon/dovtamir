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
        Uint8 a = 255;
        ret=sdl_start( "12", SDL_WINDOWPOS_UNDEFINED,
                        SDL_WINDOWPOS_UNDEFINED,
                        SCREEN_WIDTH, SCREEN_HEIGHT,0);
        if(ret) return ret;
        ret=read_texture_ck(&foo_texture,"../image/fadeout.png",0,0xff,0xff);
        if(ret) return ret;
        SDL_SetTextureBlendMode( foo_texture, SDL_BLENDMODE_BLEND);
        ret=read_texture(&bg_texture,"../image/fadein.png");
        if(ret) return ret;
        while( !quit ) {
                while( SDL_PollEvent( &e ) != 0 ) {
                        if( e.type == SDL_QUIT ) {
                                quit = 1;
                        }
                        if( e.type == SDL_KEYDOWN ) {
                                if ( e.key.keysym.sym == SDLK_ESCAPE) {
                                        quit=1;
                                } else if( e.key.keysym.sym == SDLK_w ) { 
                                        if( a + 32 > 255 ) {
                                                a = 255;
                                        } else {
                                                a += 32;
                                        }
                                } else if( e.key.keysym.sym == SDLK_s ) {
                                        if( a - 32 < 0 ) {
                                                a = 0;
                                        } else {
                                                a -= 32;
                                        }
                                }
                        }
                }
                SDL_SetRenderDrawColor( renderer, 0xFF, 0xFF, 0xFF, 0xFF );
                SDL_RenderClear( renderer );
                SDL_RenderCopy( renderer, bg_texture, NULL, 0);
                SDL_SetTextureAlphaMod( foo_texture, a);
                SDL_RenderCopy( renderer, foo_texture, NULL,0);
                SDL_RenderPresent( renderer );
        }
        SDL_DestroyTexture(foo_texture );
        SDL_DestroyTexture(bg_texture );
        sdl_stop();
        return 0;
}
