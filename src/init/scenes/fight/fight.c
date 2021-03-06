/*
** EPITECH PROJECT, 2021
** fight.c
** File description:
** Fight initializer
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
    if (!background->sprite || !background->texture)
        return NULL;
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
    if (!background->sprite || !background->texture)
        return NULL;
    sfSprite_setPosition(background->sprite, (sfVector2f) {-20, 773});
    sfSprite_setScale(background->sprite, (sfVector2f) {17.2, 2.8});
    sfSprite_setTexture(background->sprite, background->texture, sfTrue);
    return background;
}

static sfIntRect *rect_playe(void)
{
    sfIntRect *rect = malloc(sizeof(sfIntRect));

    if (!rect)
        NULL;
    rect->top = 169;
    rect->left = 94;
    rect->width = 38;
    rect->height = 59;
    return rect;
}

player_t *player_fight(void)
{
    player_t *player = malloc(sizeof(player_t));

    if (!player)
        return NULL;
    player->sprite = sfSprite_create();
    player->rect = rect_playe();
    player->texture = sfTexture_createFromFile(DOGWARRIOR_PATH, NULL);
    sfSprite_setTexture(player->sprite, player->texture, sfTrue);
    player->position = malloc(sizeof(sfVector2f));
    player->clock = sfClock_create();
    if (!player->sprite || !player->rect || !player->texture ||
        !player->position || !player->clock)
        return NULL;
    player->position->x = 250;
    player->position->y = 260;
    sfSprite_setScale(player->sprite, (sfVector2f) {7, 7});
    sfSprite_setPosition(player->sprite, *player->position);
    sfSprite_setTextureRect(player->sprite, *player->rect);
    return player;
}

fight_t *init_fight(void)
{
    fight_t *fight = malloc(sizeof(fight_t));

    if (!fight)
        return NULL;
    fight->background_fight = init_fight_background();
    fight->buttons = init_attack_buttons();
    fight->font = sfFont_createFromFile(ARIAL_FONT_PATH);
    fight->text_bar = init_text_bar();
    fight->player = player_fight();
    fight->enemy = create_enemies();
    fight->characters = create_characters();
    fight->player_bar = init_player_bar();
    fight->enemy_bar = init_enemy_bar();
    init_win_condition(fight);
    if (!fight->background_fight || !fight->buttons || !fight->text_bar ||
    !fight->player || !fight->enemy || !fight->player_bar || !fight->enemy_bar
    || !fight->characters || !fight->win_sprite || !fight->defeat_prite)
        return NULL;
    return fight;
}
