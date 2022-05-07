/*
** EPITECH PROJECT, 2022
** add_experience.c
** File description:
** Add experience
*/

#include "my_rpg.h"

bool add_experience(character_t *character, unsigned int exp)
{
    unsigned int missing_exp = character->exp_required - character->current_exp;

    if (missing_exp <= exp) {
        exp -= missing_exp;
        character->current_exp = exp;
        character->level++;
        character->exp_required *= 2;
        character->unspent += 5;
        return true;
    }
    character->current_exp += exp;
    return false;
}
