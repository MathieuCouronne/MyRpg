/*
** EPITECH PROJECT, 2021
** game.c
** File description:
** Game destroyer
*/

#include <stdlib.h>
#include "my_rpg.h"
#include "fight.h"

void destroy_all(game_t *game)
{
    menu_destroy_buttons(game->scenes->main_menu->buttons);
    destroy_menu(game->scenes->main_menu->background);
    destroy_map(game->scenes->game_scene);
    destroy_player(game->player);
    destroy_sound(game->sound);
    destroy_fight(game->scenes->fight);
    destroy_ennemy(game->ennemy);
    destroy_game(game);
}
