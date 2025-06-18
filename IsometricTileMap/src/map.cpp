#include "headers/map.hpp"

Map::Map(int map_width, int map_height)
{
  this->map_width = map_width;
  this->map_height = map_height;
  
  // Temporaire (pour l'affichage en tile map normal)
  this->tile_width = 200;
  this->tile_height = 200;
  
  // Allocation de la carte
  this->map = new TileMap*[this->map_height];
  for (int ligne = 0; ligne < this->map_height; ligne++) this->map[ligne] = new TileMap[this->map_width];

  // Remplissage de la carte
  for (int ligne = 0; ligne < this->map_height; ligne++)
    for (int colonne = 0; colonne < this->map_width; colonne++)
      this->map[ligne][colonne] = t_floor;
}

Map::~Map()
{
  for (int ligne = 0; ligne < this->map_height; ligne++)
    delete[] this->map[ligne];
  delete[] this->map;
}

void Map::modify(int x, int y, TileMap value) { if (x >= 0 && x < this->map_width && y >= 0 && y < this->map_height) this->map[x][y] = value; }

TileMap Map::get_tile(int x, int y)
{
  if (x >= 0 && x < this->map_width && y >= 0 && y < this->map_height) return this->map[x][y];
  else return t_void;
}

void Map::display(SDL_Renderer *renderer)
{
  // Affichage dans le terminal
  //printf("\x1b[1,0H]");
  for (int ligne = 0; ligne < this->map_height; ligne++)
  {
    for (int colonne = 0; colonne < this->map_width; colonne++) printf("%d ", this->map[ligne][colonne]);
    printf("\n");
  }

  // Affichage sur la fenêtre sdl
  SDL_Rect tile_rect;
  for (int ligne = 0; ligne < this->map_height; ligne++)
    for (int colonne = 0; colonne < this->map_width; colonne++)
    {
      tile_rect.x = colonne * this->map_width;
      tile_rect.y = ligne * this->map_height;
      tile_rect.w = this->tile_width;
      tile_rect.h = this->tile_height;
      
      SDL_SetRenderDrawColor(renderer, 0, 255, 0, 100);
      SDL_RenderFillRect(renderer, &tile_rect);
      //SDL_FillRect(surface, &tile_rect, SDL_MapRGB(surface->format, 0, 0, 0));
    }
}
