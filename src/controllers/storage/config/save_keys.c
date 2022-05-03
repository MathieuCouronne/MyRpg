/*
** EPITECH PROJECT, 2022
** save_keys.c
** File description:
** Write keys into the config file
*/

#include <stdio.h>
#include "my_rpg.h"

void save_keys(FILE *file, config_t *config)
{
    data_parsing_match_t matches[] = {
        {"MOVE_UP", (unsigned int *) &config->keys->up},
        {"MOVE_LEFT", (unsigned int *) &config->keys->left},
        {"MOVE_DOWN", (unsigned int *) &config->keys->down},
        {"MOVE_RIGHT", (unsigned int *) &config->keys->right},
        {"PAUSE", (unsigned int *) &config->keys->pause},
        {"INTERACT", (unsigned int *) &config->keys->interact},
        {"INVENTORY", (unsigned int *) &config->keys->inventory},
        {NULL, NULL}
    };

    for (unsigned int i = 0; matches[i].key; i++) {
        write_value(file, matches[i]);
    }
}
