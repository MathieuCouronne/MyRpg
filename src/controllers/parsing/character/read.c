/*
** EPITECH PROJECT, 2022
** open_file.c
** File description:
** Open file
*/

#include <stdio.h>
#include "my.h"
#include "my_rpg.h"
#include "character.h"

void update_character(data_parsing_match_t matches[], char **array)
{
    for (unsigned int i = 0; matches[i].key; i++) {
        if (my_strcmp(matches[i].key, array[0]) == 0) {
            *(matches[i].value) = my_getnbr(array[1]);
            break;
        }
    }
}

character_t *get_character_save(char const *filename)
{
    char *line = NULL;
    FILE *file = fopen(filename, "r");
    character_t *character = create_character();

    if (!file || !character) {
        if (file)
            fclose(file);
        return NULL;
    }
    get_player_data(character, file, &line);
    get_player_stats(character, file, &line);
    get_player_inventory(character, file, &line);
    get_player_positions(character, file, &line);
    fclose(file);
    return character;
}
