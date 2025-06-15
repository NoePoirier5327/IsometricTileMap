#include <stdio.h>
#include <SDL2/SDL.h>

#include "headers/map.hpp"

int main(int argc, char **argv)
{
  SDL_Surface *win_surface = nullptr;
  SDL_Window *window = nullptr;

  Map *i_map = new Map(5,5);

  // On initialise la SDL, s'il y a une erreur, l'initialisation renvoie -1
  if (SDL_Init(SDL_INIT_EVERYTHING) < 0)
  {
    fprintf(stderr, "Erreur dans l'initialisation de SDL : %s\n", SDL_GetError());
    return 1;
  }

  // Création de la fenêtre
  window = SDL_CreateWindow("Isometric Tile Map", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 1280, 720, SDL_WINDOW_SHOWN);

  // Vérification de la bonne création de la fenêtre
  if (!window)
  {
    fprintf(stderr, "Erreur dans la création de la fenêtre : %s\n", SDL_GetError());
    return 1;
  }

  // Récupération de la surface de la fenêtre
  win_surface = SDL_GetWindowSurface(window);

  // On vérifie qu'on a bien récupérer la surface
  if (!win_surface)
  {
    fprintf(stderr, "Erreur dans la récupération de la surface : %s\n", SDL_GetError());
    return 1;
  }

  // On affiche un rectangle blanc
  SDL_FillRect(win_surface, nullptr, SDL_MapRGB(win_surface->format, 255, 255, 255));

  // On met à jour la fenêtre
  SDL_UpdateWindowSurface(window);

  // On attend
  int a;
  scanf("%d", &a);

  i_map->display();

  delete i_map;

  // Destruction de la fenêtre
  SDL_DestroyWindow(window);

  // Destruction de la surface
  SDL_FreeSurface(win_surface);

  // On quitte SDL
  SDL_Quit();

  // Fin de programme
  return 0;
}
