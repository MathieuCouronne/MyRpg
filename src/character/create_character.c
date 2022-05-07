/*
** EPITECH PROJECT, 2021
** my_rpg.h
** File description:
** my_rpg header file
*/

#include <SFML/Audio.h>
#include <stdlib.h>
#include "structs.h"
#include "my_rpg.h"
#include "inventory.h"
#include "macros.h"
#include "character.h"

stats_t *init_war_stats(void)
{
    stats_t *stats = malloc(sizeof(stats_t));

    if (!stats)
        return NULL;
    stats->strength = BASE_WAR_STR;
    stats->defense = BASE_WAR_DEF;
    stats->vitality = BASE_WAR_VIT;
    stats->speed = BASE_WAR_SPD;
    stats->dexterity = BASE_WAR_DEX;
    return stats;
}

character_t *create_character(void)
{
    character_t *character = malloc(sizeof(character_t));

    if (!character)
        return NULL;
    character->name = "Enter a name";
    character->class = WARRIOR;
    character->unspent = 20;
    if ((character->stats = init_war_stats()) == NULL)
        return NULL;
    character->level = 1;
    character->current_exp = 0;
    character->exp_required = 100;
    character->hp = 13;
    character->inventory = create_inventory(INVENTORY_WIDTH, INVENTORY_HEIGHT);
    character->camera = (sfVector2f) {DEFAULT_VIEW_X, DEFAULT_VIEW_Y};
    character->player = (sfVector2f) {DEFAULT_VIEW_X, DEFAULT_VIEW_Y};
    if (!character->inventory)
        return NULL;
    return character;
}
