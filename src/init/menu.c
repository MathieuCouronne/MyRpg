/*
** EPITECH PROJECT, 2021
** game.c
** File description:
** Game initializer
*/

#include <stdlib.h>
#include <SFML/Graphics.h>
#include <SFML/Window.h>
#include "menu.h"
#include "structs.h"

game_asset_t *init_menu_background(void)
{
    game_asset_t *background = malloc(sizeof(game_asset_t));

    if (!background)
        return NULL;
    background->sprite = sfSprite_create();
    background->texture = sfTexture_createFromFile
        ("./assets/images/connexion.jpg", NULL);
    sfSprite_setTexture(background->sprite, background->texture, sfTrue);
    return background;
}
