/*
** EPITECH PROJECT, 2022
** parse_config.c
** File description:
** Parse config
*/

#include <fcntl.h>
#include <stdlib.h>
#include <sys/stat.h>
#include "my_rpg.h"
#include "my.h"
#include "macros.h"

config_value_t *get_config_option(char *key, char **content)
{
    config_value_t *option = malloc(sizeof(config_value_t));
    char **line = NULL;

    if (!option)
        return NULL;
    for (unsigned short i = 0; content[i]; i++) {
        if (!content[i] || content[i][0] == '#')
            continue;
        line = my_str_to_word_array(content[i], "=");
        if (!line[0] || !line[1])
            continue;
        if (my_strcmp(key, line[0]) == 0) {
            option->key = line[0];
            option->value = line[1];
            return option;
        }
    }
    free(option);
    return NULL;
}

config_t *parse_config(void)
{
    char **content = read_file(CONFIG_FILE_PATH);
    config_t *config = malloc(sizeof(config_t));

    if (!content || !config)
        return NULL;
    config->assets_loaded = get_config_option("ASSETS_LOADED", content);
    return config;
}
