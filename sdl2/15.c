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
        SDL_Rect quad;
        double degrees=0;
        SDL_RendererFlip fliptype = SDL_FLIP_NONE;
        ret=sdl_start( "15", SDL_WINDOWPOS_UNDEFINED,
                        SDL_WINDOWPOS_UNDEFINED,
                        SCREEN_WIDTH, SCREEN_HEIGHT,0);
        if(ret) return ret;
        ret=read_texture(&texture,"../image/arrow.png");
        if(ret) return ret;
        while( !quit ) {
                while( SDL_PollEvent( &e ) != 0 ) {
                        if( e.type == SDL_QUIT ) {
                                quit = 1;
                        }
                        if( e.type == SDL_KEYDOWN ) 
                                switch( e.key.keysym.sym )
                                {
                                        case SDLK_a:
                                                degrees -= 60;
                                                break;

                                        case SDLK_d:
                                                degrees += 60;
                                                break;

                                        case SDLK_q:
                                                fliptype = SDL_FLIP_HORIZONTAL;
                                                break;

                                        case SDLK_w:
                                                fliptype = SDL_FLIP_NONE;
                                                break;

                                        case SDLK_e:
                                                fliptype = SDL_FLIP_VERTICAL;
                                                break;
                                        default:
                                                quit=1;
                                }
                }
                SDL_SetRenderDrawColor( renderer, 0xFF, 0xFF, 0xFF, 0xFF );
                SDL_RenderClear( renderer );
                SDL_QueryTexture(texture, NULL, NULL, &quad.w, &quad.h);
                quad.x=(SCREEN_WIDTH-quad.w)/2;
                quad.y=(SCREEN_HEIGHT-quad.h)/2;
                SDL_RenderCopyEx( renderer, texture, 0, &quad,degrees,0,fliptype );

                SDL_RenderPresent( renderer );
        }
        SDL_DestroyTexture(texture );
        sdl_stop();
        return 0;
}
