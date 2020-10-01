#include <SDL2/SDL.h>
 
int main(int argc, char ** argv)
{
    // variables
    
    int quit = 0,i;
    SDL_Event event;
    int leftMouseButtonDown = 0;
    SDL_Point mousePos;
    SDL_Point clickOffset={0};
    SDL_Rect recta[2] = {{ 288, 208, 100, 100 },{ 50, 50, 100, 80 }};
    SDL_Rect * selectedRect = NULL;
    
    // init SDL
    
    SDL_Init(SDL_INIT_VIDEO);
    SDL_Window * window = SDL_CreateWindow("SDL2 Drag and Drop",
        SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 640, 480, 0);
    SDL_Renderer * renderer = SDL_CreateRenderer(window, -1, 0);
    while (!quit)
    {
        SDL_Delay(10);
        SDL_PollEvent(&event);
    
        switch (event.type)
        {
            case SDL_QUIT:
                quit = 1;
                break;
            case SDL_MOUSEBUTTONUP:
                if (leftMouseButtonDown && event.button.button == SDL_BUTTON_LEFT)
                {
                    leftMouseButtonDown = 0;
                    selectedRect = NULL;
                }
                break;
            case SDL_MOUSEBUTTONDOWN:
                if (!leftMouseButtonDown && event.button.button == SDL_BUTTON_LEFT)
                {
                    leftMouseButtonDown = 1;
                    
                    for (i=0;i<2;i++)
                    {
                        if (SDL_PointInRect(&mousePos, recta+i))
                        {
                            selectedRect = recta+i;
                            clickOffset.x = mousePos.x - selectedRect->x;
                            clickOffset.y = mousePos.y - selectedRect->y;
                            
                            break;
                        }
                    }
                }
                break;
            case SDL_MOUSEMOTION:
                {
                    mousePos.x = event.motion.x;
                    mousePos.y=event.motion.y;
                    
                    if (leftMouseButtonDown && selectedRect != NULL)
                    {
                        selectedRect->x = mousePos.x - clickOffset.x;
                        selectedRect->y = mousePos.y - clickOffset.y;
                    }
                }
                break;
        }
    
        SDL_SetRenderDrawColor(renderer, 242, 242, 242, 255);
        SDL_RenderClear(renderer);
        
        for (i=0;i<2;i++)
        {
            if (recta+i == selectedRect)
                SDL_SetRenderDrawColor(renderer, 0, 0, 255, 255);
            else
                SDL_SetRenderDrawColor(renderer, 0, 255, 0, 255);
            
            SDL_RenderFillRect(renderer, recta+i);
        }
        
        SDL_RenderPresent(renderer);
    }
    
    // cleanup SDL
    
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
    
    return 0;
}
