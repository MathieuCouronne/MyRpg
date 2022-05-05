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
        if (!text[i])
            return NULL;
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

sfText **init_unspent(main_creation_scenes_t *creation, sfFont *font)
{
    sfText **text_unspent = malloc(sizeof(sfText *) * 4);

    if (!text_unspent)
        return NULL;
    for (size_t i = 0; i < 3; i++) {
        text_unspent[i] = sfText_create();
        sfText_setFont(text_unspent[i], font);
        sfText_setString(text_unspent[i], itoa(creation->unspent[creation->class]));
        sfText_setCharacterSize(text_unspent[i], 20);
        sfText_setColor(text_unspent[i], sfWhite);
        sfText_setPosition(text_unspent[i], (sfVector2f) {650, 450});
    }
    text_unspent[3] = NULL;
    return text_unspent;
}

sfText ***create_stat_text(sfFont *font, main_creation_scenes_t *creation)
{
    sfText ***text = malloc(sizeof(sfText **) * 5);
    float shifts[5] = {515, 585, 655, 730, 800};

    if (!text)
        return NULL;
    init_txt(text, font, creation->stats, shifts);
    text[3] = malloc(sizeof(sfText *) * 2);
    text[3][0] = sfText_create();
    sfText_setFont(text[3][0], font);
    sfText_setString(text[3][0], "Unspent:");
    sfText_setCharacterSize(text[3][0], 20);
    sfText_setColor(text[3][0], sfWhite);
    sfText_setPosition(text[3][0], (sfVector2f) {470, 450});
    text[3][1] = NULL;
    text[4] = NULL;
    return text;
}
