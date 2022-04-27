/*
** EPITECH PROJECT, 2021
** game.c
** File description:
** Game initializer
*/

#include <stdlib.h>
#include "menu.h"
#include "structs.h"
#include "scenes.h"
#include "fight.h"
#include "my_rpg.h"
#include "my.h"

char *string_info(fight_t *fight)
{
    char *str = malloc(sizeof(char) * (my_strlen(fight->player->name) + 19));

    str = my_strcpy(str, fight->player->name);
    str = my_strcat(str, " your turn to play\n");
    return str;
}

char *string_info_enemy(fight_t *fight)
{
    char *str = malloc(sizeof(char) * 20);

    str = "enemy turn to play.\n";
    return str;
}
