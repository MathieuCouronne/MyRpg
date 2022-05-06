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

static bool init_txt(sfText **text,
    int *class_stats, float *shifts)
{
    for (size_t y = 0; y < 5; y++) {
        text[y] = sfText_create();
        if (!text[y]) {
            return false;
        }
        sfText_setString(text[y], itoa(class_stats[y]));
        sfText_setCharacterSize(text[y], 20);
        sfText_setColor(text[y], sfWhite);
        sfText_setPosition(text[y], (sfVector2f) {650, shifts[y]});
    }
    text[5] = NULL;
    return true;
}

static bool init_txt_array(sfText **text, sfFont *font,
    int *class_stats)
{
    float shifts[5] = {515, 585, 655, 730, 800};

    if (!init_txt(text, class_stats, shifts))
            return false;
    for (size_t j = 0; text[j]; j++)
        sfText_setFont(text[j], font);
    text[5] = NULL;
    return true;
}

sfText **create_stat_text_scene(sfFont *font,
    stats_scene_t *stats)
{
    sfText **text = malloc(sizeof(sfText *) * 8);

    if (!text || !init_txt_array(text, font, stats->stats))
        return NULL;
    text[6] = sfText_create();
    if (!text[6])
        return NULL;
    sfText_setFont(text[6], font);
    sfText_setString(text[6], "Unspent:");
    sfText_setCharacterSize(text[6], 20);
    sfText_setColor(text[6], sfWhite);
    sfText_setPosition(text[6], (sfVector2f) {470, 450});
    text[7] = NULL;
    return text;
}
