/*
** EPITECH PROJECT, 2021
** handling.c
** File description:
** Game arrow keys events handling
*/

#include <SFML/Graphics.h>
#include "my_rpg.h"

void handle_arrow_keys(game_t *game)
{
    const sfColor collision = sfColor_fromRGB(254, 0, 0);

    if (sfKeyboard_isKeyPressed(game->config->keys->left))
        move_left(game, collision);
    if (sfKeyboard_isKeyPressed(game->config->keys->right))
        move_right(game, collision);
    if (sfKeyboard_isKeyPressed(game->config->keys->up))
        move_top(game, collision);
    if (sfKeyboard_isKeyPressed(game->config->keys->down))
        move_bottom(game, collision);
    sfSprite_setPosition(game->player->sprite, *game->player->position);
}
