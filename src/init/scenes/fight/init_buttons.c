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

button_t **init_attack_buttons(void)
{
    button_t **buttons = malloc(sizeof(button_t *) * 3);
    sfVector2f scale = {2.35, 2};
// 33 744
// 967 744
    if (!buttons)
        return NULL;
    buttons[0] = create_button("Mathis", (sfVector2f) {33, 774}, go_to_saves,
        scale);
    buttons[1] = create_button("Le Bouffon",(sfVector2f) {967, 774},
        go_to_settings, scale);
    buttons[2] = NULL;
    return buttons;
}
