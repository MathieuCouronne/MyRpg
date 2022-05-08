/*
** EPITECH PROJECT, 2022
** read.c
** File description:
** Read config file
*/

#include <stdio.h>
#include "my_rpg.h"
#include "my.h"
#include "macros.h"

void update_match(data_parsing_match_t *matches, char **array)
{
    if (!my_str_isnum(array[1]))
        return;
    for (unsigned int i = 0; matches[i].key; i++) {
        if (my_strcmp(matches[i].key, array[0]) == 0) {
            *(matches[i].value) = my_getnbr(array[1]);
            break;
        }
    }
}

config_t *parse_config(void)
{
    char *line = NULL;
    FILE *file = fopen(CONFIG_FILE_PATH, "r");
    config_t *config = init_config();

    if (!config) {
        if (file)
            fclose(file);
        return NULL;
    }
    if (!file)
        return config;
    get_config_data(config, file, &line);
    get_config_keybinds(config, file, &line);
    fclose(file);
    return config;
}
