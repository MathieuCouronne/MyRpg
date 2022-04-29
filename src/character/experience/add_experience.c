/*
** EPITECH PROJECT, 2022
** RPG
** File description:
** Download assets from FTP
*/

#include <SFML/Network.h>
#include <stdio.h>
#include <stdlib.h>
#include "my_rpg.h"
#include "my.h"
#include "menu.h"
#include "display.h"

void add_experience(character_t *character, unsigned int exp)
{
    unsigned int missing_exp = character->exp_required - character->current_exp;
    float new_exp = 0;

    if (missing_exp <= exp) {
        exp -= missing_exp;
        character->current_exp = exp;
        character->level++;
        character->exp_required *= 2;
    }
    character->current_exp += exp;
}
