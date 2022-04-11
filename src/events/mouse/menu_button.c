/*
** EPITECH PROJECT, 2021
** wheel.c
** File description:
** Game wheel events handling
*/

#include "my_rpg.h"
#include "menu.h"

void click_play_menu(button_t *button, sfEvent event)
{
    sfVector2i pos;

    pos.x = event.mouseButton.x;
    pos.y = event.mouseButton.y;
    if (event.type == sfEvtMouseButtonPressed) {
        if (pos.x <= button->asset->pos.x + 350
            && pos.x >= button->asset->pos.x
            && pos.y <= button->asset->pos.y + 140
            && pos.y >= button->asset->pos.y) {
            //TODO add change of
        }
    }
}
