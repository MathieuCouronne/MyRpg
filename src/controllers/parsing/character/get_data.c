/*
** EPITECH PROJECT, 2022
** get_data.c
** File description:
** Parse player data
*/

#include <stddef.h>
#include <stdio.h>
#include "character.h"
#include "my_rpg.h"
#include "my.h"

static void update_character_data(character_t *character, char **array)
{
    data_parsing_match_t matches[] = {
        {"CLASS", &character->class},
        {"UNSPENT_POINTS", &character->unspent},
        {"LEVEL", &character->level},
        {"EXP", &character->current_exp},
        {"HP", &character->hp},
        {NULL, NULL}
    };

    update_character(matches, array);
}

void get_player_data(character_t *character, FILE *file, char **line)
{
    size_t size = 0;
    char **array = NULL;

    while (getline(line, &size, file) != -1) {
        clear_str(*line, '\n');
        array = my_str_to_word_array(*line, " ");
        if (get_2d_array_length(array) != 2)
            continue;
        if (my_strcmp(*line, "## STATS") == 0)
            return;
        if (my_strcmp(array[0], "PLAYER_NAME") == 0)
            character->name = array[1];
        else
            update_character_data(character, array);
    }
}
