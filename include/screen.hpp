#include <stdio.h>
#include <SDL2/SDL.h>
#include "map.hpp"
#include "time.hpp"

int screenWidth = 720;
int screenHeight = 480;

void initialize()
{
    if(SDL_Init(SDL_INIT_VIDEO) < 0){
        printf("Error: SDL failed to initialize\nSDL Error: '%s'\n", SDL_GetError());
    }

    SDL_Window *window = SDL_CreateWindow("AI with Jetpack and Rocket Launcher", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, screenWidth, screenHeight, 0);

    if(!window)
    {
        printf("Error: Failed to open window\nSDL Error: '%s'\n", SDL_GetError());
    }

    SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    if(!renderer)
    {
        printf("Error: Failed to create renderer\nSDL Error: '%s'\n", SDL_GetError());
    }

    bool running = true;
    
    while(running)
    {
        SDL_Event event;
        
        while(SDL_PollEvent(&event))
        {
            switch(event.type)
            {
                case SDL_QUIT:
                    running = false;
                    break;

                default:
                    break;
            }
        }

        SDL_SetRenderDrawColor(renderer, 30, 30, 30, 255);
        SDL_RenderClear(renderer);

        // Render map

        // Render UI

        SDL_RenderPresent(renderer);
    }
};

void update()
{

};