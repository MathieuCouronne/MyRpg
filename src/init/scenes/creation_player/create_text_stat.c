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

void init_txt(sfText ***text, sfFont *font,
int **class_stats, float *shifts)
{
    for (size_t i = 0; i < 3; i++) {
        text[i] = malloc(sizeof(sfText *) * 6);
        for (size_t y = 0; y < 5; y++) {
            text[i][y] = sfText_create();
            sfText_setFont(text[i][y], font);
            sfText_setString(text[i][y], itoa(class_stats[i][y]));
            sfText_setCharacterSize(text[i][y], 20);
            sfText_setColor(text[i][y], sfWhite);
            sfText_setPosition(text[i][y], (sfVector2f) {650, shifts[y]});
        }
        text[i][5] = NULL;
    }
}

sfText ***create_stat_text(sfFont *font, main_creation_scenes_t *creation)
{
    sfText ***text = malloc(sizeof(sfText **) * 4);
    float shifts[5] = {515, 585, 655, 730, 800};

    init_txt(text, font, creation->stats, shifts);
    text[3] = NULL;
    return text;
}
