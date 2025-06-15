#include "headers/map.hpp"

Map::Map(int width, int height)
{
  this->width = width;
  this->height = height;
  
  // Allocation de la carte
  this->map = new TileMap*[this->height];
  for (int ligne = 0; ligne < this->height; ligne++) this->map[ligne] = new TileMap[this->width];

  // Remplissage de la carte
  for (int ligne = 0; ligne < this->height; ligne++)
    for (int colonne = 0; colonne < this->width; colonne++)
      this->map[ligne][colonne] = t_floor;
}

Map::~Map()
{
  for (int ligne = 0; ligne < this->height; ligne++)
    delete[] this->map[ligne];
  delete[] this->map;
}

void Map::modify(int x, int y, TileMap value) { if (x >= 0 && x < this->width && y >= 0 && y < this->height) this->map[x][y] = value; }

TileMap Map::get_tile(int x, int y)
{
  if (x >= 0 && x < this->width && y >= 0 && y < this->height) return this->map[x][y];
  else return t_void;
}

void Map::display()
{
  printf("\x1b[2;0H]");
  for (int ligne = 0; ligne < this->height; ligne++)
  {
    for (int colonne = 0; colonne < this->width; colonne++) printf("%d ", this->map[ligne][colonne]);
    printf("\n");
  }
}
