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
#include "scenes.h"
#include "fight.h"

game_asset_t *init_fight_background(void)
{
    game_asset_t *background = malloc(sizeof(game_asset_t));

    if (!background)
        return NULL;
    background->sprite = sfSprite_create();
    background->texture = sfTexture_createFromFile
            ("./assets/images/sky.png", NULL);
    sfSprite_setTexture(background->sprite, background->texture, sfTrue);
    return background;
}

fight_t *init_fight()
{
    fight_t  *fight = malloc(sizeof(fight_t));

    if (!fight)
        return NULL;
    fight->background_fight = init_fight_background();
    return fight;
}
