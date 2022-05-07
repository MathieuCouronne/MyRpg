/*
** EPITECH PROJECT, 2021
** create_map.c
** File description:
** create_map main game
*/

#include <stdbool.h>
#include <string.h>
#include "my_rpg.h"
#include "structs.h"
#include "my.h"

bool create_text_enemy(enemy_t *enemy, fight_t *fight)
{
    int hp_len = my_strlen(itoa(enemy->hp));
    int max_hp_len = my_strlen(itoa(enemy->max_hp));
    int enemy_hp_len = hp_len + max_hp_len + 1;
    char *enemy_hp = malloc(sizeof(char) * (enemy_hp_len + 1));

    memset(enemy_hp, '\0', enemy_hp_len);
    my_strcat(enemy_hp, itoa(enemy->hp));
    my_strcat(enemy_hp, "/");
    my_strcat(enemy_hp, itoa(enemy->max_hp));
    sfText_setString(fight->text_enemy_hp, enemy_hp);
    return true;
}

bool create_text_player(character_t *player, fight_t *fight)
{
    int vitality_len = my_strlen(itoa(player->stats->vitality));
    int hp_len = my_strlen(itoa(player->hp));
    int player_hp_len = hp_len + vitality_len + 1;
    char *player_hp = malloc(sizeof(char) * (player_hp_len + 1));

    memset(player_hp, '\0', player_hp_len);
    my_strcat(player_hp, itoa(player->hp));
    my_strcat(player_hp, "/");
    my_strcat(player_hp, itoa(player->stats->vitality));
    sfText_setString(fight->text_player_hp, player_hp);
    return true;
}
