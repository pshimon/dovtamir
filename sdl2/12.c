//Texture wrapper class
#include "mysdl.h"
#define SCREEN_WIDTH 640
#define  SCREEN_HEIGHT  480
extern    SDL_Window* window;
extern SDL_Renderer* renderer;

int main( int argc, char* args[] )
{
        SDL_Texture* texture = 0;
        int quit=0,ret;
        SDL_Event e;
        Uint8 r = 255;
        Uint8 g = 255;
        Uint8 b = 255;
        ret=sdl_start( "12", SDL_WINDOWPOS_UNDEFINED,
                        SDL_WINDOWPOS_UNDEFINED,
                        SCREEN_WIDTH, SCREEN_HEIGHT,SDL_WINDOW_SHOWN);
        if(ret) return ret;
        ret=read_texture(&texture,"../image/colors.png");
        if(ret) return ret;
        while( !quit ) {
                while( SDL_PollEvent( &e ) != 0 ) {
                        if( e.type == SDL_QUIT ) {
                                quit = 1;
                        }
                        if( e.type == SDL_KEYDOWN ) 
                                switch( e.key.keysym.sym )
                                {
                                        //Increase red
                                        case SDLK_q:
                                                r += 32;
                                                break;

                                                //Increase green
                                        case SDLK_w:
                                                g += 32;
                                                break;

                                                //Increase blue
                                        case SDLK_e:
                                                b += 32;
                                                break;

                                                //Decrease red
                                        case SDLK_a:
                                                r -= 32;
                                                break;

                                                //Decrease green
                                        case SDLK_s:
                                                g -= 32;
                                                break;

                                                //Decrease blue
                                        case SDLK_d:
                                                b -= 32;
                                                break;
                                        default:
                                                quit=1;
                                }
                }


                SDL_SetRenderDrawColor( renderer, 0xFF, 0xFF, 0xFF, 0xFF );
                SDL_RenderClear( renderer );
	        SDL_SetTextureColorMod( texture, r, g, b );

                SDL_RenderCopy( renderer, texture, NULL, NULL );

                SDL_RenderPresent( renderer );
        }
        SDL_DestroyTexture(texture );
        sdl_stop();
        return 0;
}
