/*
** EPITECH PROJECT, 2021
** my_rpg
** File description:
** my_rpg main file
*/

#include "my_rpg.h"
#include "display.h"
#include "inventory.h"

static void event_handling(game_t *game, sfEvent *event)
{
    while (sfRenderWindow_pollEvent(game->window, event)) {
        handle_menu_events(game->scenes->main_menu->buttons, *event, game);
        handle_events(game, event);
    }
}

int main(void)
{
    game_t *game = init_game();

    if (!game)
        return 84;
    while (sfRenderWindow_isOpen(game->window)) {
        sfRenderWindow_clear(game->window, sfBlack);
        event_handling(game, game->event);
        scene_manager(game);
        sfRenderWindow_display(game->window);
    }
    destroy_all(game);
}
