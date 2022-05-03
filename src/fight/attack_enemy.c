/*
** EPITECH PROJECT, 2021
** create_map.c
** File description:
** attacks enemy during fight
*/

#include <stdbool.h>
#include <stdlib.h>
#include "my_rpg.h"
#include "structs.h"

void attack_enemy(character_t *player, enemy_t *enemy, attack_t *attack)
{
    unsigned int dmg = player->stats->strength + attack->dmg;

    enemy->hp -= dmg;
}
