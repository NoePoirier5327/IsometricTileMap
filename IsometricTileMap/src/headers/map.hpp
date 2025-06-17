#pragma once

#include <SDL2/SDL.h>
#include <stdio.h>

enum TileMap
{
  t_floor = 0,
  t_void = -1
};

/**
 * @brief Classe permettant la gestion de la carte isométrique 
*/
class Map
{
  public:
    /**
     * @brief Constructeur de la classe, alloue la mémoire pour le tableau de la carte
     * @param map_width:int, largeur de la carte
     * @param map_height:int, hauteur de la carte
    */
    Map(int map_width, int map_height);

    /**
     * @brief Destructeur de la classe, désalloue la mémoire pour le tableau de la carte
    */
    ~Map();
    
    /**
     * @brief Méthode permettant de modifier une valeur de la carte aux indexs en paramètre
     * @param x:int, index de la colonne de la carte à modifier
     * @param y:int, index de la ligne de la carte à modifier
     * @param value:TileMap, valeur à attribuer aux coordonnées dans la carte
    */
    void modify(int x, int y, TileMap value);
    
    /**
     * @brief Accesseur du type d'une tile dans la map à des coordonnées données, si les coordonnées sortent de la carte, on récupère du vide
     * @param x:int, index de la colonne de la carte à récupérer
     * @param y:int, index de la ligne de la carte à récupérer
     * @return TileMap, tuile stockée dans la map à récupérer
     */
    TileMap get_tile(int x, int y);
    
    /**
     * @brief Méthode d'affichage du tilemap
     * @param surface:SDL_Surface, surface d'écriture du tile map
    */
    void display(SDL_Surface *surface);

  private:
    TileMap **map;
    int map_width;
    int map_height;
    int tile_width;
    int tile_height;
};
