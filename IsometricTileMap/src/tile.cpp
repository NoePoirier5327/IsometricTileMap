#include "headers/tile.hpp"

Tile::Tile(TileType value, int tile_width, int tile_height, int pos_x, int pos_y)
{
  this->type = value;
  this->tile_width = tile_width;
  this->tile_height = tile_height;
  this->pos_x = pos_x;
  this->pos_y = pos_y;

  this->color[0][0] = 255;
  this->color[0][1] = 255;
  this->color[0][2] = 255;
  this->color[1][0] = 0;
  this->color[1][1] = 0;
  this->color[1][2] = 255;
  this->color[2][0] = 0;
  this->color[2][1] = 255;
  this->color[2][2] = 0;
}

void Tile::display(SDL_Renderer *renderer)
{
  SDL_SetRenderDrawColor(renderer, this->color[this->type][0], this->color[this->type][1], this->color[this->type][2], 255);
  SDL_Rect rect = {pos_x * this->tile_width, pos_y * this->tile_height, this->tile_width, this->tile_height};
  SDL_RenderFillRect(renderer, &rect);
}

TileType Tile::get_type() { return this->type; }

void Tile::set_type(TileType value) { this->type = value; }

void Tile::set_coords(int pos_x, int pos_y) { this->pos_x = pos_x; this->pos_y = pos_y; }
