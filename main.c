#include <SDL.h>

int
main (int argc, char* argv[])
{
  SDL_Init(SDL_INIT_VIDEO);

  SDL_Window *window = SDL_CreateWindow("SDL2Test",
					SDL_WINDOWPOS_UNDEFINED,
					SDL_WINDOWPOS_UNDEFINED,
					800,
					600,
					0);

  SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_SOFTWARE);
  SDL_SetRenderDrawColor(renderer, 0, 0, 0, SDL_ALPHA_OPAQUE);
  SDL_RenderClear(renderer);
  SDL_RenderPresent(renderer);
  
  SDL_Event event;
  while (1)
    {
      SDL_PollEvent (&event);
      if (event.type == SDL_QUIT)
	break;
    }

  SDL_DestroyWindow(window);
  SDL_Quit();

  return 0;
}
