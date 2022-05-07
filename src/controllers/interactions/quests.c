/*
** EPITECH PROJECT, 2021
** quests.c
** File description:
** Quests interactions
*/

#include "my_rpg.h"
#include "structs.h"
#include "macros.h"

void transform_dialog(game_t *game)
{
    sfVector2i relative_pos = {0, 0};
    sfVector2f pos = sfRenderWindow_mapPixelToCoords(game->window,
        relative_pos, game->view);
    sfFloatRect size = {};

    if (!game->quests)
        return;
    size = sfSprite_getGlobalBounds(game->quests->asset->sprite);
    pos.x += (float) WINDOW_WIDTH / (2 * MAP_SCALE) - size.width / 2;
    pos.y += (float) WINDOW_HEIGHT / 2 - size.height - size.height * .15f;
    game->quests->asset->pos = pos;
    sfSprite_setPosition(game->quests->asset->sprite, game->quests->asset->pos);
    transform_dialog_txt(game, game->quests->text);
}

void transform_dialog_txt(game_t *game, sfText *sprite)
{
    sfVector2i relative_pos = {0, 0};
    sfVector2f pos = sfRenderWindow_mapPixelToCoords(game->window,
        relative_pos, game->view);
    sfFloatRect size = sfSprite_getGlobalBounds(game->quests->asset->sprite);

    pos.x = game->quests->asset->pos.x + size.height * .35f;
    pos.y += (float) WINDOW_HEIGHT / 2 - size.height - size.height * .15f +
        size.height * .28f;
    sfText_setPosition(sprite, pos);
}
