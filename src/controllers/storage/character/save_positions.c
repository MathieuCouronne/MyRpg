/*
** EPITECH PROJECT, 2022
** save_positions.c
** File description:
** Save character positions into the config file
*/

#include "my_rpg.h"
#include "my.h"

static void save_position(FILE *file, const char *key, sfVector2f position)
{
    char *x = NULL;
    char *y = NULL;

    if (!file || !key)
        return;
    x = itoa((unsigned int) position.x);
    y = itoa((unsigned int) position.y);
    fwrite(key, my_strlen(key), 1, file);
    fwrite(" ", 1, 1, file);
    fwrite(x, my_strlen(x), 1, file);
    fwrite(" ", 1, 1, file);
    fwrite(y, my_strlen(y), 1, file);
    fwrite("\n", 1, 1, file);
}

void save_characters_positions(FILE *file, character_t *character)
{
    if (!character)
        return;
    save_position(file, "PLAYER", character->player);
    save_position(file, "CAMERA", character->camera);
}
