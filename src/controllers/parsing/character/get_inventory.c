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

static void update_character_inventory(character_t *character, char **array)
{
    unsigned int id = my_getnbr(array[0]);
    unsigned int quantity = my_getnbr(array[1]);
    unsigned int x = my_getnbr(array[2]);
    unsigned int y = my_getnbr(array[3]);
    slot_t *slot = character->inventory->content[y][x];

    if (!slot || !is_array_num(array))
        return;
    slot->id = id;
    slot->quantity = quantity;
    slot->pos.x = x;
    slot->pos.y = y;
}

void get_player_inventory(character_t *character, FILE *file, char **line)
{
    size_t size = 0;
    char **array = NULL;

    while (getline(line, &size, file) != -1) {
        clear_str(*line, '\n');
        array = my_str_to_word_array(*line, " ");
        if (my_strcmp(*line, "## POSITIONS") == 0)
            return;
        if (get_2d_array_length(array) != 4)
            continue;
        if (my_strcmp(array[0], "PLAYER_NAME") == 0)
            character->name = array[1];
        else
            update_character_inventory(character, array);
    }
}
