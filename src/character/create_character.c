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
#include "character.h"

static stats_t *init_dog_stats(void)
{
    stats_t *stats = malloc(sizeof(stats_t));

    stats->strength = BASE_DOG_STR;
    stats->defense = BASE_DOG_DEF;
    stats->vitality = BASE_DOG_VIT;
    stats->speed = BASE_DOG_SPD;
    stats->dexterity = BASE_DOG_DEX;
    return stats;
}

static stats_t *init_mage_stats(void)
{
    stats_t *stats = malloc(sizeof(stats_t));

    stats->strength = BASE_MAGE_STR;
    stats->defense = BASE_MAGE_DEF;
    stats->vitality = BASE_MAGE_VIT;
    stats->speed = BASE_MAGE_SPD;
    stats->dexterity = BASE_MAGE_DEX;
    return stats;
}

static stats_t *init_war_stats(void)
{
    stats_t *stats = malloc(sizeof(stats_t));

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
    return character;
}
