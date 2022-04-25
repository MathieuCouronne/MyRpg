/*
** EPITECH PROJECT, 2021
** my_rpg
** File description:
** my_rpg main file
*/

#include "my_rpg.h"
#include "menu.h"
#include "display.h"
#include "game.h"
#include "fight.h"

int main(void)
{
    game_t *game = init_game();
    sfEvent event = {};

    if (!game)
        return 84;
    menu_music(game->sound);
    while (sfRenderWindow_isOpen(game->window)) {
        sfRenderWindow_clear(game->window, sfBlack);
        while (sfRenderWindow_pollEvent(game->window, &event)) {
            handle_menu_events(game->scenes->main_menu->buttons, event);
            handle_events(game, &event);
        }
        //display_main_menu(game);
        //display_fight(game);
        display_main_game(game);
        sfRenderWindow_display(game->window);
    }
    destroy_all(game);
}
