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
        {"MOVE_UP", &config->keys->up},
        {"MOVE_LEFT", &config->keys->left},
        {"MOVE_DOWN", &config->keys->down},
        {"MOVE_RIGHT", &config->keys->right},
        {"PAUSE", &config->keys->pause},
        {"INTERACT", &config->keys->interact},
        {"INVENTORY", &config->keys->inventory},
        {NULL, NULL}
    };

    for (unsigned int i = 0; matches[i].key; i++) {
        write_value(file, matches[i]);
    }
}
