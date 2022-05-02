/*
** EPITECH PROJECT, 2022
** get_stats.c
** File description:
** Parse player stats
*/

#include <stddef.h>
#include <stdio.h>
#include "character.h"
#include "my_rpg.h"
#include "my.h"

static void update_character_stats(character_t *character, char **array)
{
    data_parsing_match_t matches[] = {
        {"STR", &character->stats->strength},
        {"DEF", &character->stats->defense},
        {"VIT", &character->stats->vitality},
        {"SPD", &character->stats->speed},
        {"DEX", &character->stats->dexterity},
        {NULL, NULL}
    };

    update_character(matches, array);
}

void get_player_stats(character_t *character, FILE *file, char **line)
{
    size_t size = 0;
    char **array = NULL;

    while (getline(line, &size, file) != -1) {
        array = my_str_to_word_array(*line, " ");
        if (get_2d_array_length(array) != 2)
            continue;
        if (my_strcmp(*line, "## INVENTORY") == 0)
            return;
        if (my_strcmp(array[0], "PLAYER_NAME") == 0)
            character->name = array[0];
        else
            update_character_stats(character, array);
    }
}
