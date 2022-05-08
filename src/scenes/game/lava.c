/*
** EPITECH PROJECT, 2021
** lava.c
** File description:
** Display lava
*/

#include <SFML/Graphics.h>
#include "my_rpg.h"
#include "structs.h"

static const sfColor lava_color = (sfColor) {0, 255, 1, 255};

void draw_lava(game_t *game)
{
    sfCircleShape **lava = NULL;
    sfVector2f pos = {0, 0};

    if (!game || !game->scenes || !game->scenes->game_scene ||
    !game->scenes->game_scene->lava)
        return;
    lava = game->scenes->game_scene->lava;
    for (unsigned int i = 0; lava[i]; i++) {
        if (!lava[i])
            return;
        pos = sfCircleShape_getPosition(lava[i]);
        if (!color_cmp(get_pixel_at_pos(game, pos), lava_color))
            continue;
        sfRenderWindow_drawCircleShape(game->window, lava[i], NULL);
    }
    destroy_game_lava(game->scenes->game_scene->lava);
    game->scenes->game_scene->lava = init_lava();
}
