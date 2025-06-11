#include <iostream>
#include <SDL2/SDL.h>

int main(int argc, char **argv)
{
  SDL_Surface *win_surface = nullptr;
  SDL_Window *window = nullptr;

  // On initialise la SDL, s'il y a une erreur, l'initialisation renvoie -1
  if (SDL_Init(SDL_INIT_EVERYTHING) < 0)
  {
    std::cerr << "Erreur dans l'initialisation de SDL : " << SDL_GetError() << std::endl;
    return 1;
  }

  // Création de la fenêtre
  window = SDL_CreateWindow("Hello SDL", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 1280, 720, SDL_WINDOW_SHOWN);

  // Vérification de la bonne création de la fenêtre
  if (!window)
  {
    std::cerr << "Erreur dans la création de la fenêtre : " << SDL_GetError() << std::endl;
    return 1;
  }

  // Récupération de la surface de la fenêtre
  win_surface = SDL_GetWindowSurface(window);

  // On vérifie qu'on a bien récupérer la surface
  if (!win_surface)
  {
    std::cerr << "Erreur dans la récupération de la surface : " << SDL_GetError() << std::endl;
    return 1;
  }

  // On affiche un rectangle blanc
  SDL_FillRect(win_surface, nullptr, SDL_MapRGB(win_surface->format, 255, 255, 255));

  // On met à jour la fenêtre
  SDL_UpdateWindowSurface(window);

  // On attend
  int a;
  std::cin >> a; 

  // Destruction de la fenêtre
  SDL_DestroyWindow(window);

  // On quitte SDL
  SDL_Quit();

  // Fin de programme
  return 0;
}
