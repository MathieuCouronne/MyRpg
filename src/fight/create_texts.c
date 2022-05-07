/*
** EPITECH PROJECT, 2021
** create_map.c
** File description:
** create_map main game
*/

#include <stdbool.h>
#include "my_rpg.h"
#include "structs.h"

bool create_text_enemy(enemy_t *enemy, fight_t *fight)
{
    int enemy_hp_len = my_strlen(itoa(enemy->hp)) + my_strlen(itoa(enemy->max_hp)) + 1;
    char *enemy_hp = malloc(sizeof(char) * (enemy_hp_len + 1));

    enemy_hp[0] = '\0';
    enemy_hp[enemy_hp_len] = '\0';
    my_strcat(enemy_hp, itoa(enemy->hp));
    enemy_hp[my_strlen(itoa(enemy->hp))] = '\0';
    my_strcat(enemy_hp, "/");
    enemy_hp[my_strlen(itoa(enemy->hp)) + 2] = '\0';
    my_strcat(enemy_hp, itoa(enemy->max_hp));
    enemy_hp[enemy_hp_len] = '\0';
    sfText_setString(fight->text_enemy_hp, enemy_hp);
    return true;
}

bool create_text_player(character_t *player, fight_t *fight)
{
    int player_hp_len = my_strlen(itoa(player->hp)) + my_strlen(itoa(player->stats->vitality)) + 1;
    char *player_hp = malloc(sizeof(char) * (player_hp_len + 1));

    player_hp[0] = '\0';
    player_hp[player_hp_len] = '\0';
    my_strcat(player_hp, itoa(player->hp));
    player_hp[my_strlen(itoa(player->hp))] = '\0';
    my_strcat(player_hp, "/");
    player_hp[my_strlen(itoa(player->hp)) + 2] = '\0';
    my_strcat(player_hp, itoa(player->stats->vitality));
    player_hp[player_hp_len] = '\0';
    sfText_setString(fight->text_player_hp, player_hp);
    return true;
}