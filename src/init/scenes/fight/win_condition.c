/*
** EPITECH PROJECT, 2021
** game.c
** File description:
** create_map main game and npc
*/

#include <stdlib.h>
#include "my_rpg.h"
#include "structs.h"
#include "macros.h"


game_asset_t *init_victory(void)
{
    game_asset_t *victory = malloc(sizeof(game_asset_t));

    if (!victory)
        return NULL;
    victory->sprite = sfSprite_create();
    victory->texture =
            sfTexture_createFromFile(VICTORY_PATH, NULL);
    if (!victory->sprite || !victory->texture)
        return NULL;
    sfSprite_setTexture(victory->sprite, victory->texture, sfTrue);
    return victory;
}

game_asset_t *init_defeat(void)
{
    game_asset_t *defeat = malloc(sizeof(game_asset_t));

    if (!defeat)
        return NULL;
    defeat->sprite = sfSprite_create();
    defeat->texture =
            sfTexture_createFromFile(DEFEAT_PATH, NULL);
    if (!defeat->sprite || !defeat->texture)
        return NULL;
    sfSprite_setTexture(defeat->sprite, defeat->texture, sfTrue);
    return defeat;
}

void init_win_condition(fight_t *fight)
{
    fight->defeat_prite = init_defeat();
    fight->win_sprite = init_victory();
    fight->victory = false;
    fight->defeat = false;
    fight->text_player_hp = init_text_player_hp(fight);
    fight->text_enemy_hp = init_text_enemy_hp(fight);
}
