/*
** EPITECH PROJECT, 2022
** get_inventory.c
** File description:
** Parse player inventory
*/

#include <stddef.h>
#include <stdio.h>
#include "character.h"
#include "my_rpg.h"
#include "my.h"

static bool is_array_num(char **array)
{
    for (unsigned int i = 0; array[i]; i++) {
        if (!my_str_isnum(array[i]))
            return false;
    }
    return true;
}

static void update_positions(game_t *game, char **array)
{
    sfVector2f pos = {(float) my_getnbr(array[1]), (float) my_getnbr(array[2])};

    if (!is_array_num(array + 1))
        return;
    if (my_strcmp(array[0], "PLAYER") == 0) {
        printf("PLAYER: x: %f y: %f\n", pos.x, pos.y);
        game->player->position = &pos;
    } else if (my_strcmp(array[0], "CAMERA") == 0) {
        printf("CAMERA: x: %f y: %f\n", pos.x, pos.y);
        sfView_setCenter(game->view, pos);
    }
}

void get_player_positions(game_t *game, character_t *character, FILE *file,
char **line)
{
    size_t size = 0;
    char **array = NULL;

    while (getline(line, &size, file) != -1) {
        clear_str(*line, '\n');
        array = my_str_to_word_array(*line, " ");
        if (get_2d_array_length(array) != 3)
            continue;
        if (my_strcmp(array[0], "PLAYER_NAME") == 0)
            character->name = array[0];
        else
            update_positions(game, array);
    }
}
