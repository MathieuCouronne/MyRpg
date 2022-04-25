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
            ("./assets/images/fight.png", NULL);
    sfSprite_setScale(background->sprite, (sfVector2f) {1.05 , 1});
    sfSprite_setTexture(background->sprite, background->texture, sfTrue);
    return background;
}

player_t *player_fight(void)
{

    player_t *player = malloc(sizeof(player_t));

    player->sprite = sfSprite_create();
    player->rect = rect_player();
    player->texture = sfTexture_createFromFile(
            "./assets/images/character.png", NULL);
    sfSprite_setTexture(player->sprite, player->texture, sfTrue);
    player->position.x = 0;
    player->position.y = 0;
    sfSprite_setScale(player->sprite, (sfVector2f) {5, 5});
    sfSprite_setPosition(player->sprite, player->position);
    sfSprite_setTextureRect(player->sprite, *player->rect);
    player->clock = sfClock_create();
    return player;
}

fight_t *init_fight(void)
{
    fight_t  *fight = malloc(sizeof(fight_t));

    if (!fight)
        return NULL;
    fight->background_fight = init_fight_background();
    fight->player = player_fight();
    return fight;
}
