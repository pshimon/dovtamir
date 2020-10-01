#include "mysdl.h"

#define SCREEN_WIDTH 640
#define  SCREEN_HEIGHT  480
   extern SDL_Window* window;
  extern   SDL_Renderer *renderer;
 SDL_Texture * get_text_and_rect(SDL_Renderer *renderer, int x, int y, char *text,
        TTF_Font *font,SDL_Color clr , SDL_Rect *rect) {
    int text_width;
    int text_height;
    SDL_Surface *surface;
    SDL_Texture *texture;
    surface = TTF_RenderText_Solid(font, text, clr);
    texture = SDL_CreateTextureFromSurface(renderer, surface);
    text_width = surface->w;
    text_height = surface->h;
    SDL_FreeSurface(surface);
    rect->x = x;
    rect->y = y;
    rect->w = text_width;
    rect->h = text_height;
    return texture;
}

int main( int argc, char* argv[] ) {
    SDL_Event e;
    int quit=0,ret;
    TTF_Font *font=0;
    SDL_Texture *text;
    SDL_Rect rect;
    SDL_Color textColor = { 0, 0, 0 };
    if(argc!=2) {
        fprintf(stderr,"usage %s ttf_font_path\n",argv[0]);
        exit(1);
    }

    ret=sdl_start( "16", SDL_WINDOWPOS_UNDEFINED,
            SDL_WINDOWPOS_UNDEFINED,
            SCREEN_WIDTH, SCREEN_HEIGHT,0);
    if(ret) return ret;
    font = TTF_OpenFont( argv[1], 28 );
    text=get_text_and_rect(renderer, 0, 0, "The quick brown fox jumps over the lazy dog", font,textColor, &rect);
    while( !quit ){
        while( SDL_PollEvent( &e ) != 0 ) {
            if( e.type == SDL_QUIT ) quit=1;
            if( e.type == SDL_KEYDOWN ) quit=1;

        }
        SDL_SetRenderDrawColor(renderer, 0xFF, 0xFF, 0xFF, 0xFF );
        SDL_RenderClear( renderer );
        SDL_RenderCopy(renderer, text, NULL, &rect);
        SDL_RenderPresent( renderer );

    }
    TTF_CloseFont( font );
        sdl_stop();
    return 0;
}
