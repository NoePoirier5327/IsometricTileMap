#pragma once

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <stdio.h>
#include "tile.hpp"

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
     * @param value:TileType, valeur à attribuer aux coordonnées dans la carte
    */
    void modify(int x, int y, TileType value);
    
    /**
     * @brief Accesseur du type d'une tile dans la map à des coordonnées données, si les coordonnées sortent de la carte, on récupère du vide
     * @param x:int, index de la colonne de la carte à récupérer
     * @param y:int, index de la ligne de la carte à récupérer
     * @return TileType, tuile stockée dans la map à récupérer
     */
    TileType get_tile(int x, int y);
    
    /**
     * @brief Méthode d'affichage du tilemap
     * @param renderer:SDL_Renderer, surface de rendu du tile map
     * @param texture:SDL_Texture, texture du tile_set
    */
    void display(SDL_Renderer *renderer, SDL_Texture *texture);

  private:
    Tile ***map; // carte composée d'intances de tuiles
    int map_width;
    int map_height;
    int tile_width;
    int tile_height;
};
