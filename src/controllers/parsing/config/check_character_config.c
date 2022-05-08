/*
** EPITECH PROJECT, 2022
** check_character_config.c
** File description:
** check_character_config
*/

#include <stdbool.h>
#include "my_rpg.h"
#include "structs.h"

bool check_all_characters(character_t **characters)
{
    for (size_t i = 0; i < 3; i++) {
        if (!check_character_config(characters[i]))
            return false;
    }
    return true;
}

bool check_character_config(character_t *character)
{
    if (!character) {
        printf("ça passe\n");
        return true;
    }
    if (character->class > 2)
        return false;
    if (character->hp == 0 || character->max_hp == 0
    || character->stats->defense == 0
    || character->stats->dexterity == 0 || character->stats->speed == 0
    || character->stats->strength == 0 || character->stats->vitality == 0) {
        return false;
    }
    return true;
}