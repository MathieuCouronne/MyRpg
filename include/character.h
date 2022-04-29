/*
** EPITECH PROJECT, 2021
** my_rpg.h
** File description:
** my_rpg header file
*/

#ifndef CHARACTER_H_
    #define CHARACTER_H_

    #define NB_STATS 5
    #define NB_CLASSES 2

    #define BASE_WAR_STR 10
    #define BASE_WAR_DEF 5
    #define BASE_WAR_VIT 100
    #define BASE_WAR_SPD 100
    #define BASE_WAR_DEX 5

    #define BASE_MAGE_STR 5
    #define BASE_MAGE_DEF 3
    #define BASE_MAGE_VIT 75
    #define BASE_MAGE_DEX 10
    #define BASE_MAGE_SPD 100

typedef struct stats_s {
    char *name;
    unsigned int amount;
} stats_t;

typedef struct character_s {
    char *name;
    char *class_name;
    unsigned int unspent;
    stats_t **stats;
    unsigned int level;
    unsigned int current_exp;
    unsigned int exp_required;
    unsigned int hp;
    unsigned int max_hp;
    unsigned int mp;
    unsigned int max_mp;
    inventory_t *inventory;
} character_t;

#endif