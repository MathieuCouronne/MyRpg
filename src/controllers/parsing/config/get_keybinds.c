/*
** EPITECH PROJECT, 2022
** get_keybinds.c
** File description:
** Parse configuration keybinds
*/

#include <stddef.h>
#include <stdio.h>
#include "character.h"
#include "my_rpg.h"
#include "my.h"

static void update_config(config_t *config, char **array)
{
    data_parsing_match_t matches[] = {
        {"INVENTORY", (unsigned int *) &config->keys->inventory},
        {"PAUSE", (unsigned int *) &config->keys->pause},
        {"INTERACT", (unsigned int *) &config->keys->interact},
        {"MOVE_RIGHT", (unsigned int *) &config->keys->right},
        {"MOVE_LEFT", (unsigned int *) &config->keys->left},
        {"MOVE_UP", (unsigned int *) &config->keys->up},
        {"MOVE_DOWN", (unsigned int *) &config->keys->down},
        {NULL, NULL}
    };

    update_match(matches, array);
}

void get_config_keybinds(config_t *config, FILE *file, char **line)
{
    size_t size = 0;
    char **array = NULL;

    while (getline(line, &size, file) != -1) {
        clear_str(*line, '\n');
        array = my_str_to_word_array(*line, " ");
        if (get_2d_array_length(array) != 2)
            continue;
        else
            update_config(config, array);
    }
}
