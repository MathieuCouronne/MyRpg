/*
** EPITECH PROJECT, 2022
** open_file.c
** File description:
** Open file
*/

#include <fcntl.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <unistd.h>
#include "my_rpg.h"
#include "my.h"

bool write_file(char const *filename, config_t *config)
{
    int fd = open(filename, O_WRONLY);
    struct stat stats = {};

    if (fd == -1)
        return false;
    write(fd, config->assets_loaded->key,
    my_strlen(config->assets_loaded->key));
    write(fd, "=", 1);
    write(fd, config->assets_loaded->value,
    my_strlen(config->assets_loaded->value));
    write(fd, "\n", 1);
    return true;
}