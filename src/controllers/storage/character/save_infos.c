/*
** EPITECH PROJECT, 2022
** save_infos.c
** File description:
** Save character info into the config file
*/

#include "my_rpg.h"

void save_characters_infos(FILE *file, character_t *character)
{
    data_parsing_match_t matches[] = {
        {"CLASS", &character->class},
        {"UNSPENT_POINTS", &character->unspent},
        {"LEVEL", &character->level},
        {"EXP", &character->current_exp},
        {"HP", (unsigned int *) &character->hp},
        {"MP", &character->mp},
        {NULL, NULL}
    };

    for (unsigned int i = 0; matches[i].key; i++) {
        write_value(file, matches[i]);
    }
}
