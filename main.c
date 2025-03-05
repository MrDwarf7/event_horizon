#ifndef SDL_MAIN_HANDLED
#define SDL_MAIN_HANDLED
#endif

#include <math.h>
#include "SDL2/SDL.h"

enum {
    WIDTH = 1000,
    HEIGHT = 1000,
};

/* Draw the Event Horizon */
void draw(SDL_Renderer *renderer) {
    for (int col = 0; col < HEIGHT; ++col) {
        for (int row = 0; row < WIDTH; ++row) {
            const float x = col, y = row;
            constexpr float w = WIDTH, h = HEIGHT;
            const float cx = (2 * x - w) / h;
            const float cy = (2 * y - h) / h;
            float d = sqrtf((cx * cx) + (cy * cy));

            d -= 0.5;
            d += 0.01 * h / (2 * (y - x) + h - w);
            d = fabsf(d);
            if (d < 1e-6)
                d = 1e-6;
            d = 0.1 / d;

            const Uint8 color = (Uint8) (255 * d / (1 + d));
            SDL_SetRenderDrawColor(renderer, color, color, color, 255);
            SDL_RenderDrawPoint(renderer, row, col);
        }
    }
}

int main() {
    void SDL_SetMainReady();
    const int err = SDL_Init(SDL_INIT_VIDEO);
    if (err != 0) {
        SDL_Log("Unable to initialize SDL: %s", SDL_GetError());
        return EXIT_FAILURE;
    }

    SDL_Window *window = SDL_CreateWindow("SDL2 Window", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, WIDTH, HEIGHT, 0);
    SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

    SDL_RenderClear(renderer);
    draw(renderer);
    SDL_RenderPresent(renderer);

    SDL_Event event;
    int quit = 0;

    while (quit != 1) {
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) {
                quit = 1;
            }

            if (event.type == SDL_KEYDOWN) {
                switch (event.key.keysym.sym) {
                    case SDLK_ESCAPE:
                    case SDLK_q:
                        quit = 1;
                        break;
                    default:
                        continue;
                }
            }
        }
    }

    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();

    return EXIT_SUCCESS;
}
