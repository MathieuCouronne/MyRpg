/*
** EPITECH PROJECT, 2021
** my_rpg.h
** File description:
** my_rpg header file
*/

#ifndef CHARACTER_H_
    #define CHARACTER_H_

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
    unsigned int exp;
} character_t;

#endif