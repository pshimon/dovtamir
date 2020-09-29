#include "mysdl.h"

#define WIDTH 800
#define HEIGHT 600

extern SDL_Window *window;
extern SDL_Renderer *renderer;
int main(int argc, char *argv[]) {
        int ret;
        SDL_Event event;
        ret=sdl_start("Hello, World!",SDL_WINDOWPOS_UNDEFINED,
                        SDL_WINDOWPOS_UNDEFINED,WIDTH, HEIGHT,0);
        if(ret) return ret;
        SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
        SDL_RenderClear(renderer);
        SDL_RenderPresent(renderer);

        while(1) {
                if(SDL_PollEvent(&event)) {
                        if(event.type == SDL_QUIT) {
                                break;
                        }
                }
        }
        sdl_stop();
        return 0;
}

