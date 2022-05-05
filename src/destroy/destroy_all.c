/*
** EPITECH PROJECT, 2021
** destroy_all.c
** File description:
** Game destroyer
*/

#include "my_rpg.h"

void destroy_all(game_t *game)
{
    menu_destroy_buttons(game->scenes->main_menu->buttons);
    destroy_settings(game->scenes->settings->background);
    menu_destroy_buttons(game->scenes->settings->buttons);
    settings_destroy_icons(game->scenes->settings->icons);
    destroy_menu(game->scenes->main_menu->background);
    destroy_map(game->scenes->game_scene);
    destroy_player(game->player);
    destroy_sound(game->sounds);
    destroy_fight(game->scenes->fight);
    destroy_inventory(game->scenes->inventory);
    destroy_chest(game->scenes->game_scene->chest);
    destroy_albert(game->scenes->game_scene->albert);
    destroy_chief(game->scenes->game_scene->chief);
    destroy_game(game);
}
