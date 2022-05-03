/*
** EPITECH PROJECT, 2021
** my_rpg.h
** File description:
** my_rpg header file
*/

#include "inventory.h"

#ifndef CHARACTER_H_
    #define CHARACTER_H_

    #define NB_STATS 5
    #define NB_CLASSES 3

    #define BASE_WAR_STR 10
    #define BASE_WAR_DEF 5
    #define BASE_WAR_VIT 100
    #define BASE_WAR_SPD 100
    #define BASE_WAR_DEX 5

    #define BASE_MAGE_STR 5
    #define BASE_MAGE_DEF 3
    #define BASE_MAGE_VIT 75
    #define BASE_MAGE_SPD 100
    #define BASE_MAGE_DEX 10

    #define BASE_DOG_STR 7
    #define BASE_DOG_DEF 0
    #define BASE_DOG_VIT 50
    #define BASE_DOG_SPD 200
    #define BASE_DOG_DEX 50

typedef enum {
    WARRIOR, MAGE, DOGGY
} character_classes;

typedef struct stats_s {
    unsigned int strength;
    unsigned int defense;
    unsigned int vitality;
    unsigned int speed;
    unsigned int dexterity;
} stats_t;

typedef struct character_s {
    char *name;
    character_classes class;
    stats_t *stats;
    inventory_t *inventory;
    unsigned int unspent;
    unsigned int level;
    unsigned int current_exp;
    unsigned int exp_required;
    unsigned int hp;
    unsigned int max_hp;
    unsigned int mp;
    unsigned int max_mp;
} character_t;

typedef struct data_parsing_match_s {
    char *key;
    unsigned int *value;
} data_parsing_match_t;

#endif
