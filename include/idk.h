/*
** EPITECH PROJECT, 2021
** structs.h
** File description:
** my_rpg structs header file
*/

#include <SFML/Graphics.h>

#ifndef IDK_H_
    #define IDK_H_

typedef struct game_asset_s {
    sfSprite *sprite;
    sfTexture *texture;
    sfRectangleShape *rect;
    sfVector2f pos;
    float scaling;
} game_asset_t;

#endif
