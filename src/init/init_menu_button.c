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

// buttons->title = title_menu("Cyber_Coc");
button_t **init_buttons(void)
{
    button_t **buttons = malloc(sizeof(button_t *) * 4);
    float pos_x = 960 - 350 / 2;

    buttons[0] = create_button("Play", (sfVector2f) {pos_x ,500});
    buttons[1] = create_button("Settings",(sfVector2f) {pos_x, 650});
    buttons[2] = create_button("Quit", (sfVector2f) {pos_x, 800});
    buttons[3] = NULL;
    return buttons;
}
