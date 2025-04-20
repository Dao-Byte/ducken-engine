#include <SDL.h>
#include <stdbool.h>

int main(int argc, char* argv[]) {
    SDL_Init(SDL_INIT_VIDEO);

    SDL_Window* window = SDL_CreateWindow("Week 2: Sprite Time",
        SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
        800, 600, SDL_WINDOW_SHOWN);

    SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, 0);

    // Load BMP sprite
    SDL_Surface* surface = SDL_LoadBMP("Ducken_sprite.bmp");
    if (!surface) {
 	SDL_Log("Failed to load BMP: %s", SDL_GetError());
	return 1;
    }
    SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, surface);
    SDL_FreeSurface(surface);

    bool running = true;
    SDL_Event event;

    while (running) {
        // Handle input
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) {
                running = false;
            }
        }

        // Clear screen
        SDL_RenderClear(renderer);

        // Draw texture
        SDL_RenderCopy(renderer, texture, NULL, NULL);


        // Show what we drew
        SDL_RenderPresent(renderer);
    }

    SDL_DestroyTexture(texture);
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}
