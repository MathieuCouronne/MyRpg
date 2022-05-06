/*
** EPITECH PROJECT, 2021
** game.c
** File description:
** Game initializer
*/

#include <SFML/Window.h>
#include <stdlib.h>
#include "structs.h"
#include "my_rpg.h"
#include "macros.h"

sfText **init_text_life(fight_t *text_fight)
{
    sfText **text_life = malloc(sizeof(sfText *) * 4);
    int life = 100;

    if (!text_life)
        return NULL;
    for (size_t i = 0; i < 3; i++) {
        text_life[i] = sfText_create();
        if (!text_life[i])
            return NULL;
        sfText_setFont(text_life[i], text_fight->font);
        sfText_setString(text_life[i], itoa(life));
        sfText_setCharacterSize(text_life[i], 20);
        sfText_setColor(text_life[i], sfWhite);
        sfText_setPosition(text_life[i], (sfVector2f) {650, 450});
    }
    text_life[3] = NULL;
    return text_life;
}
