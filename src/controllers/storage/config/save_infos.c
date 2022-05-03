/*
** EPITECH PROJECT, 2022
** save_infos.c
** File description:
** Write info into the config file
*/

#include <stdio.h>
#include "my_rpg.h"

void save_infos(FILE *file, config_t *config)
{
    data_parsing_match_t matches[] = {
        {"ASSETS_LOADED", &config->assets_loaded},
        {"VOLUME", &config->volume},
        {NULL, NULL}
    };

    for (unsigned int i = 0; matches[i].key; i++) {
        write_value(file, matches[i]);
    }
}
