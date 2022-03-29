/*
** EPITECH PROJECT, 2021
** my_rpg
** File description:
** my_rpg main file
*/

#include "my_rpg.h"

int main(void)
{
    game_t *game = init_game();
    sfEvent event = {};

    if (!game)
        return 84;
    while (sfRenderWindow_isOpen(game->window)) {
        while (sfRenderWindow_pollEvent(game->window, &event)) {
            if (event.type == sfEvtClosed)
                sfRenderWindow_close(game->window);
        }
    }
}
