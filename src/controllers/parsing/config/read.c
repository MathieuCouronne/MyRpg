/*
** EPITECH PROJECT, 2022
** read.c
** File description:
** Read config file
*/

#include <stdio.h>
#include "my.h"
#include "my_rpg.h"
#include "character.h"
#include "macros.h"

config_t *parse_config(void)
{
    char *line = NULL;
    FILE *file = fopen(CONFIG_FILE_PATH, "r");
    config_t *config = create_config();

    if (!file || !config) {
        if (file)
            fclose(file);
        return NULL;
    }
    get_config_data(config, file, &line);
    fclose(file);
    return config;
}
