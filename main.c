#ifndef SDL_MAIN_HANDLED
#  define SDL_MAIN_HANDLED
#endif

#include <math.h>

#define CONSTANTS_H_DEFAULTS

#include "constants.h"
#include "SDL2/SDL.h"

/* Draw the Event Horizon */
void draw(
	SDL_Renderer* renderer
) {
	for (u32 col = 0; col < HEIGHT; ++col) {
		for (u32 row = 0; row < WIDTH; ++row) {
			const f32 xcol       = (float)col;
			const f32 yrow       = (float)row;
			constexpr f32 width  = WIDTH;
			constexpr f32 height = HEIGHT;
			const f32 cxdh       = (2 * xcol - width) / height;
			const f32 cydh       = (2 * yrow - height) / height;
			f32 delt             = sqrtf((cxdh * cxdh) + (cydh * cydh));
			delt -= (f32)DELT_0_5;
			delt += (f32)DELT_0_01 * height / (2 * (yrow - xcol) + height - width);
			delt = fabsf(delt);
			if (delt < EXPONEN_1e_6) {
				delt = EXPONEN_1e_6;
			}
			delt              = DELT_1 / delt;

			const Uint8 color = (Uint8)(255 * delt / (1 + delt));
			SDL_SetRenderDrawColor(renderer, color, color, color, SDL_ALPHAOPAQUE);
			SDL_RenderDrawPoint(renderer, (int)row, (int)col);
		}
	}
}

int main() {
	SDL_SetMainReady();
	const usize err = SDL_Init(SDL_INIT_VIDEO);
	if (err != 0) {
		SDL_Log("Unable to initialize SDL: %s", SDL_GetError());
		return EXIT_FAILURE;
	}

	SDL_Window* window =
		SDL_CreateWindow("SDL2 Window", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, WIDTH, HEIGHT, 0);
	SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

	SDL_RenderClear(renderer);
	draw(renderer);
	SDL_RenderPresent(renderer);

	SDL_Event event;

	bool quit = false;

	while (!quit) {
		while (SDL_PollEvent(&event)) {
			if (event.type == SDL_QUIT) {
				quit = true;
			}

			if (event.type == SDL_KEYDOWN) {
				switch (event.key.keysym.sym) {
					case SDLK_ESCAPE:
					case SDLK_q     : quit = true; break;
					default         : continue;
				}
			}
		}
	}

	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	SDL_Quit();

	return EXIT_SUCCESS;
}
