#include <SDL.h>
#include <SDL_image.h>
//#include <SDL_ttf.h>
#include <SDL_mixer.h>
#include <stdio.h>

#define SCREEN_WIDTH 640
#define  SCREEN_HEIGHT  480
SDL_Texture* load_texture(SDL_Renderer* renderer,char * file) {
    SDL_Surface* surf;
    SDL_Texture *tex;
    surf=IMG_Load(file);
    tex=SDL_CreateTextureFromSurface(renderer,surf);
    SDL_FreeSurface(surf);
    return tex;
}

int main( int argc, char* argv[] ) {
    SDL_Window* window = 0;
    SDL_Renderer *renderer=0;
    SDL_Event event;
    int quit=0;
    Mix_Music *music = NULL;
    Mix_Chunk *scratch = NULL;
    Mix_Chunk *high = NULL;
    Mix_Chunk *medium = NULL;
    Mix_Chunk *low = NULL;
    SDL_Texture *tex=0;
    SDL_Init(SDL_INIT_VIDEO|SDL_INIT_AUDIO);
    SDL_CreateWindowAndRenderer(SCREEN_WIDTH,SCREEN_HEIGHT, 0, &window, &renderer);
    IMG_Init(IMG_INIT_PNG); 
    Mix_OpenAudio( 44100, MIX_DEFAULT_FORMAT, 2, 2048 );
    tex=load_texture(renderer,"../image/prompt.png");
    music = Mix_LoadMUS( "../sound/beat.wav" );
    scratch = Mix_LoadWAV( "../sound/scratch.wav" );
    medium = Mix_LoadWAV( "../sound/medium.wav" );
    low = Mix_LoadWAV( "../sound/low.wav" );
    while( !quit ){
        while( SDL_PollEvent( &event ) != 0 ) {
            if( event.type == SDL_QUIT ) quit=1;
            if( event.type == SDL_KEYDOWN ) {
                switch( event.key.keysym.sym ){
                    case SDLK_1:
                        Mix_PlayChannel( -1, high, 0 );
                        break;
                    case SDLK_2:
                        Mix_PlayChannel( -1, medium, 0 );
                        break;
                    case SDLK_3:
                        Mix_PlayChannel( -1, low, 0 );
                        break;
                    case SDLK_4:
                        Mix_PlayChannel( -1, scratch, 0 );
                        break;
                    case SDLK_9:
                        if( Mix_PlayingMusic() == 0 ) Mix_PlayMusic( music, -1 );
                        if( Mix_PausedMusic() == 1 ) Mix_ResumeMusic();
                        Mix_PauseMusic();
                        break;
                    case SDLK_0:
                        Mix_HaltMusic();
                        break;
                }
            }
        }
        SDL_SetRenderDrawColor(renderer, 0xFF, 0xFF, 0xFF, 0xFF );
        SDL_RenderClear( renderer );
        SDL_RenderCopy(renderer, tex, 0, 0);
        SDL_RenderPresent( renderer );
    }
    Mix_FreeChunk( scratch );
    Mix_FreeChunk( high );
    Mix_FreeChunk( medium );
    Mix_FreeChunk( low );
    Mix_FreeMusic( music );
    SDL_DestroyRenderer(renderer );
    SDL_DestroyWindow( window );
    Mix_Quit();
    IMG_Quit();
    SDL_Quit();
    exit(0);
}
