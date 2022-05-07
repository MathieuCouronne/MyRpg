/*
** EPITECH PROJECT, 2022
** save_stats.c
** File description:
** Save character stats into the save file
*/

#include "my_rpg.h"

void save_characters_stats(FILE *file, character_t *character)
{
    data_parsing_match_t matches[] = {
        {"STR", &character->stats->strength},
        {"DEF", &character->stats->defense},
        {"VIT", &character->stats->vitality},
        {"SPD", &character->stats->speed},
        {"DEX", &character->stats->defense},
        {NULL, NULL}
    };

    for (unsigned int i = 0; matches[i].key; i++) {
        write_value(file, matches[i]);
    }
}
