/*
** EPITECH PROJECT, 2021
** my_rpg.h
** File description:
** my_rpg header file
*/

#include <stdio.h>
#include <SFML/Audio.h>
#include <stdlib.h>
#include "structs.h"
#include "menu.h"
#include "my_rpg.h"
#include "inventory.h"
#include "character.h"

static stats_t **init_war_stats(void)
{
    stats_t **stats = malloc(sizeof(stats_t *) * NB_STATS + 1);

    stats[NB_STATS] = NULL;
    stats[0]->name = "STR";
    stats[0]->amount = BASE_WAR_STR;
    stats[1]->name = "DEF";
    stats[1]->amount = BASE_WAR_DEF;
    stats[2]->name = "VIT";
    stats[2]->amount = BASE_WAR_VIT;
    stats[3]->name = "SPD";
    stats[3]->amount = BASE_WAR_SPD;
    stats[4]->name = "DEX";
    stats[4]->amount = BASE_WAR_DEX;
    return stats;
}

character_t *create_character(void)
{
    character_t *character = malloc(sizeof(character_t *));

    character->name = "Enter a name";
    character->class_name = "Warrior";
    character->unspent = 20;
    character->stats = init_war_stats();
    character->level = 1;
    character->exp = 0;
    return character;
}
