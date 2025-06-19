#include "headers/map.hpp"

Map::Map(int map_width, int map_height)
{
  this->map_width = map_width;
  this->map_height = map_height;
  
  // Allocation de la carte
  this->map = new Tile**[this->map_height];
  for (int ligne = 0; ligne < this->map_height; ligne++) this->map[ligne] = new Tile*[this->map_width];

  // Remplissage de la carte et ajout des coordonnées + instanciation des tuiles
  for (int ligne = 0; ligne < this->map_height; ligne++)
    for (int colonne = 0; colonne < this->map_width; colonne++)
      this->map[ligne][colonne] = new Tile(t_grass, 100, 100, colonne, ligne);
}

Map::~Map()
{
  // on désintancie les tuiles
  for (int ligne = 0; ligne < this->map_height; ligne++)
    for (int colonne = 0; colonne < this->map_width; colonne++)
      delete this->map[ligne][colonne];
  
  // on désintancie le tableau
  for (int ligne = 0; ligne < this->map_height; ligne++)
    delete[] this->map[ligne];
  delete[] this->map;
}

void Map::modify(int x, int y, TileType value) { if (x >= 0 && x < this->map_width && y >= 0 && y < this->map_height) this->map[x][y]->set_type(value); }

TileType Map::get_tile(int x, int y)
{
  if (x >= 0 && x < this->map_width && y >= 0 && y < this->map_height) return this->map[x][y]->get_type();
  else return t_void;
}

void Map::display(SDL_Renderer *renderer)
{
  // Affichage dans le terminal
  //printf("\x1b[1,0H]");
  for (int ligne = 0; ligne < this->map_height; ligne++)
  {
    for (int colonne = 0; colonne < this->map_width; colonne++) printf("%d ", this->map[ligne][colonne]->get_type());
    printf("\n");
  }

  // Affichage sur la fenêtre sdl
  for (int ligne = 0; ligne < this->map_height; ligne++)
    for (int colonne = 0; colonne < this->map_width; colonne++)
      this->map[ligne][colonne]->display(renderer);
}
