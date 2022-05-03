/*
** EPITECH PROJECT, 2022
** write.c
** File description:
** Write config into a file
*/

#include <stdio.h>
#include "my_rpg.h"
#include "character.h"
#include "my.h"
#include "macros.h"

void write_value(FILE *file, data_parsing_match_t match)
{
    char *buffer = itoa(*match.value);

    fwrite(match.key, my_strlen(match.key), 1, file);
    fwrite(" ", 1, 1, file);
    fwrite(buffer, my_strlen(buffer), 1, file);
    fwrite("\n", 1, 1, file);
}

static void write_separator(FILE *file, char *title)
{
    fwrite("\n", 1, 1, file);
    fwrite(title, my_strlen(title), 1, file);
    fwrite("\n", 1, 1, file);
}

bool write_config(config_t *config)
{
    FILE *file = fopen(CONFIG_FILE_PATH, "w");

    if (!file || !config) {
        if (file)
            fclose(file);
        return false;
    }
    save_infos(file, config);
    write_separator(file, "## KEYS");
    save_keys(file, config);
    fclose(file);
    return true;
}
