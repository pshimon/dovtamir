#ifndef MYSDL_H
#define MYSDL_H
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>

int sdl_start(char * wname,int x,int y,int w,int h,int flags);
void sdl_stop();
void sdl_get_text(SDL_Texture ** tex,char *text, TTF_Font *font,SDL_Color *color);
int read_texture(SDL_Texture ** tex,char * file); 
int read_texture_ck(SDL_Texture ** tex,char * file,Uint8 r,Uint8 g,Uint8 b); 

#endif
