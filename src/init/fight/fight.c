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
#include "my_rpg.h"
#include "macros.h"

game_asset_t *init_fight_background(void)
{
    game_asset_t *background = malloc(sizeof(game_asset_t));

    if (!background)
        return NULL;
    background->sprite = sfSprite_create();
    background->texture = sfTexture_createFromFile(FIGHT_BG_PATH, NULL);
    sfSprite_setTexture(background->sprite, background->texture, sfTrue);
    return background;
}

game_asset_t *init_text_bar(void)
{
    game_asset_t *background = malloc(sizeof(game_asset_t));

    if (!background)
        return NULL;
    background->sprite = sfSprite_create();
    background->texture = sfTexture_createFromFile(FIGHT_TOOLTIP_PATH, NULL);
    sfSprite_setPosition(background->sprite, (sfVector2f) {0, 800});
    sfSprite_setScale(background->sprite, (sfVector2f) {8.05, 6});
    sfSprite_setTexture(background->sprite, background->texture, sfTrue);
    return background;
}

static sfIntRect *rect_player(void)
{
    sfIntRect *rect = malloc(sizeof(sfIntRect));

    rect->top = 0;
    rect->left = 74;
    rect->width = 74;
    rect->height = 50;
    return rect;
}

player_t *player_fight(void)
{

    player_t *player = malloc(sizeof(player_t));

    player->sprite = sfSprite_create();
    player->rect = rect_player();
    player->texture = sfTexture_createFromFile(DOGWARRIOR_PATH, NULL);
    sfSprite_setTexture(player->sprite, player->texture, sfTrue);
    player->position.x = 200;
    player->position.y = 330;
    sfSprite_setScale(player->sprite, (sfVector2f) {10, 10});
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
    fight->text_bar = init_text_bar();
    fight->player = player_fight();
    fight->enemy = init_ogre();
    fight->hp_bar = init_hp_bar();
    return fight;
}
