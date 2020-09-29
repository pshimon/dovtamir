#include "mysdl.h"
SDL_Renderer *renderer=0;
SDL_Window *window=0;

int sdl_start(char * wname,int x,int y,int w,int h,int flags)
{
       
    if (SDL_Init(SDL_INIT_VIDEO|SDL_INIT_AUDIO)) {
        fprintf(stderr, "SDL could not initialize! SDL_Error: %s\n", SDL_GetError());
        return 1;
    }
    TTF_Init();
    if (!SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "1")) {
        fprintf(stderr,"Warning: Linear texture filtering not enabled!");
    }
    window =
        SDL_CreateWindow(wname, x, y,w,h,flags);
    if (!window) {
        fprintf(stderr, "Window  could not be created! SDL_Error: %s\n", SDL_GetError());
        return 2;
    }
    renderer =
        SDL_CreateRenderer(window, -1,
                           SDL_RENDERER_ACCELERATED |
                           SDL_RENDERER_PRESENTVSYNC);
    if (!renderer) {
        fprintf(stderr, "renderer could not be created! SDL_Error: %s\n", SDL_GetError());
        return 3;
    }
    SDL_SetRenderDrawBlendMode(renderer,SDL_BLENDMODE_BLEND);
    return 0;
}
void sdl_stop()
{
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    TTF_Quit();
    SDL_Quit();

}
void sdl_get_text(SDL_Texture ** tex,char *text, TTF_Font *font,SDL_Color *color)
{
    SDL_Surface *surface;
    SDL_DestroyTexture(*tex);
    surface = TTF_RenderUTF8_Blended(font, text, *color);
    *tex = SDL_CreateTextureFromSurface(renderer, surface);
    SDL_FreeSurface(surface);
 }

int read_texture(SDL_Texture ** tex,char * file) 
{
        SDL_Surface * surf;      
        surf = IMG_Load(file);
        if (!surf) {
            fprintf(stderr, "Unable to load image! SDL_Error: %s\n", SDL_GetError());
            return 1;
        }
        *tex = SDL_CreateTextureFromSurface(renderer,surf);                     SDL_FreeSurface(surf);
        return 0;
}
int inside(int x, int y, SDL_Rect rect) 
{
	//printf("(%d %d %d %d)\n",rect.x,rect.y,rect.x+rect.w,rect.y+rect.h);
	if(x<rect.x) {
		return 0;
	}
	if(x>rect.x+rect.w) {
		return 0;
	}
	if(y<rect.y) {
		return 0;
	}
	if(y>rect.y+rect.h) {
		return 0;
	}
	return 1;
}
void set_color(SDL_Color * clr) {
	SDL_SetRenderDrawColor(renderer,clr->r , clr->g, clr->b, clr->a);
}
void set_FOV(SDL_Rect *rect) {
	SDL_RenderSetViewport(renderer, rect);
}





int sdl_start_mw(SDL_Renderer ** rnd, SDL_Window **wnd,
                SDL_Rect *r)
{
       
    if (SDL_Init(SDL_INIT_VIDEO)) {
        fprintf(stderr, "SDL could not initialize! SDL_Error: %s\n", SDL_GetError());
        return 1;
    }
    TTF_Init();
    if (!SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "1")) {
        fprintf(stderr,"Warning: Linear texture filtering not enabled!");
    }
    *wnd =
        SDL_CreateWindow("sdl_gui_window", r->x, r->y,r->w,r->h,SDL_WINDOW_RESIZABLE);
    if (!*wnd) {
        fprintf(stderr, "Window  could not be created! SDL_Error: %s\n", SDL_GetError());
        return 2;
    }
    *rnd =
        SDL_CreateRenderer(*wnd, -1,
                           SDL_RENDERER_ACCELERATED |
                           SDL_RENDERER_PRESENTVSYNC);
    if (!*rnd) {
        fprintf(stderr, "renderer could not be created! SDL_Error: %s\n", SDL_GetError());
        return 3;
    }
    SDL_SetRenderDrawBlendMode(*rnd,SDL_BLENDMODE_BLEND);
    return 0;
}
void sdl_stop_mw(SDL_Renderer * rnd, SDL_Window *wnd)
{
    SDL_DestroyRenderer(rnd);
    SDL_DestroyWindow(wnd);
    TTF_Quit();
    SDL_Quit();

}
void sdl_get_text_mw(SDL_Renderer * rnd,SDL_Texture ** tex,char *text, TTF_Font *font,SDL_Color *color)
{
    SDL_Surface *surface;
    SDL_DestroyTexture(*tex);
    surface = TTF_RenderUTF8_Blended(font, text, *color);
    *tex = SDL_CreateTextureFromSurface(rnd, surface);
    SDL_FreeSurface(surface);
 }
int read_texture_mw(SDL_Renderer * rnd,SDL_Texture ** tex,char * file) 
{
        SDL_Surface * surf;      
        surf = IMG_Load(file);
        if (!surf) {
            fprintf(stderr, "Unable to load image! SDL_Error: %s\n", SDL_GetError());
            return 1;
        }
        *tex = SDL_CreateTextureFromSurface(rnd,surf);                     SDL_FreeSurface(surf);
        return 0;
}

