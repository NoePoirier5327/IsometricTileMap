#pragma once

#include <SDL2/SDL.h>

enum TileType
{
  t_void = -1,
  t_floor = 0,
  t_water = 1,
  t_grass = 2,
  t_red_sand = 3
};

/**
  * @brief Classe gérant le fonctionnement général d'une tuile de la carte (affichage et gestion de valeur associée)
*/
class Tile
{
  public:
    /**
     * @brief Constructeur de la tuile courante, sa position sera 0, 0 par défaut
     * @param value:TileType, valeur associée à la tuile courante (il s'agit de son type)
     * @param tile_width:int, largeur de la tuile courante
     * @param tile_height:int, hauteur de la tuile courante
     * @param pos_x:int, position en x de la tuile courante (à 0 par défaut)
     * @param pos_y:int, position en y de la tuile courante (à 0 par défaut aussi)
    */
    Tile(TileType value, int tile_width, int tile_height, int pos_x=0, int pos_y=0);
    
    /**
     * @brief Méthode permettant l'affichage de la tuile courante sur la fenêtre SDL
     * @param renderer:SDL_Renderer, instance de rendu de la fenêtre SDL
     * @param texture:SDL_Texture, instance de texture du tileset
    */
    void display(SDL_Renderer *renderer, SDL_Texture *texture);
    
    /**
     * @brief Méthode permettant de récupérer le type de la tuile courante
     * @return TileType, type de la tuile courante
    */
    TileType get_type();
    
    /**
     * @brief Mutateur du type de la tuile courante
     * @param value:TileType, nouveau type à attribuer
    */
    void set_type(TileType value);
    
    /**
     * @brief Mutateur des coordonnées de la tuile courante
     * @param pos_x:int, position x de la tuile
     * @param pos_y:int, position y de la tuile
    */ 
    void set_coords(int pos_x, int pos_y);
    
  private:
    TileType type; // valeur associée à la tuile courante
    int tile_width; // largeur de la tuile
    int tile_height; // hauteur de la tuile
    int pos_x; // position en x de la tuile
    int pos_y; // position en y de la tuile
    SDL_Rect wanted_tile[4]; // Assets des tiles
};
