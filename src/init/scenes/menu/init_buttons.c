/*
** EPITECH PROJECT, 2021
** init_menu_button.c
** File description:
** init menu button
*/

#include <stdlib.h>
#include <SFML/Window.h>
#include "structs.h"
#include "my_rpg.h"

button_t **init_buttons(void)
{
    button_t **buttons = malloc(sizeof(button_t *) * 4);
    float pos_x = 960 - (float) 390 / 2;
    sfVector2f scale = {1, 1};

    if (!buttons)
        return NULL;
    buttons[0] = create_button("Play", (sfVector2f) {pos_x, 500}, go_to_saves,
        scale);
    buttons[1] = create_button("Settings",(sfVector2f) {pos_x, 650},
        go_to_settings, scale);
    buttons[2] = create_button("Quit", (sfVector2f) {pos_x, 800}, quit_game,
        scale);
    buttons[3] = NULL;
    return buttons;
}
