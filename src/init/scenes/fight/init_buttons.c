/*
** EPITECH PROJECT, 2021
** init_buttons.c
** File description:
** init buttons for fight
*/

#include <stdlib.h>
#include <SFML/Window.h>
#include "structs.h"
#include "my_rpg.h"

button_t **init_attack_buttons(void)
{
    button_t **buttons = malloc(sizeof(button_t *) * 5);
    sfVector2f scale = {2.35, 1};

    if (!buttons)
        return NULL;
    buttons[0] = create_button("Charge", (sfVector2f) {33, 779}, attack_enemy,
        scale);
    buttons[1] = create_button("Slap", (sfVector2f) {967, 779},
        attack_enemy, scale);
    buttons[2] = create_button("Gamble", (sfVector2f) {33, 890},
        gamble_fight, scale);
    buttons[3] = create_button("Escape", (sfVector2f) {967, 890},
        escape_fight, scale);
    buttons[4] = NULL;
    if (!buttons[0] || !buttons[1] || !buttons[2] || !buttons[3])
        return NULL;
    return buttons;
}
