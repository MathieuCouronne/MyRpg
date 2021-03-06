/*
** EPITECH PROJECT, 2022
** get_options.c
** File description:
** Parse player inventory
*/

#include <stddef.h>
#include <stdio.h>
#include "character.h"
#include "my_rpg.h"
#include "my.h"

static void update_config(config_t *config, char **array)
{
    data_parsing_match_t matches[] = {
        {"ASSETS_LOADED", &config->assets_loaded},
        {"VOLUME", &config->volume},
        {NULL, NULL}
    };

    update_match(matches, array);
}

void get_config_data(config_t *config, FILE *file, char **line)
{
    size_t size = 0;
    char **array = NULL;

    while (getline(line, &size, file) != -1) {
        clear_str(*line, '\n');
        array = my_str_to_word_array(*line, " ");
        if (get_2d_array_length(array) != 2)
            continue;
        if (my_strcmp(*line, "## KEYS") == 0)
            return;
        else
            update_config(config, array);
    }
}
