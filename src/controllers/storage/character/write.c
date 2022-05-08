/*
** EPITECH PROJECT, 2022
** write.c
** File description:
** Write character into a file
*/

#include <stdio.h>
#include "my_rpg.h"
#include "character.h"
#include "my.h"

void write_player_name(FILE *file, char *name)
{
    fwrite("PLAYER_NAME", my_strlen("PLAYER_NAME"), 1, file);
    fwrite(" ", 1, 1, file);
    fwrite(name, my_strlen(name), 1, file);
    fwrite("\n", 1, 1, file);
}

static void write_separator(FILE *file, char *title)
{
    fwrite("\n", 1, 1, file);
    fwrite(title, my_strlen(title), 1, file);
    fwrite("\n", 1, 1, file);
}

bool write_character(game_t *game, char const *filename, unsigned int i)
{
    FILE *file = fopen(filename, "w");
    character_t *character = NULL;

    if (!file || !game) {
        if (file)
            fclose(file);
        return false;
    }
    character = game->saves[i];
    write_player_name(file, character->name);
    save_characters_infos(file, character);
    write_separator(file, "## STATS");
    save_characters_stats(file, character);
    write_separator(file, "## INVENTORY");
    save_characters_inventory(file, character);
    write_separator(file, "## POSITIONS");
    save_characters_positions(file, character, game);
    fclose(file);
    return true;
}
