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
#include "my.h"

// "config/game.config"
char **read_file(char const *filename)
{
    int fd = open(filename, O_RDONLY);
    struct stat stats = {};
    char *content = NULL;

    if (stat(filename, &stats) == -1 || fd == -1)
        return NULL;
    content = malloc(sizeof(char) * (stats.st_size));
    if (!content)
        return NULL;
    if (read(fd, content, stats.st_size) == -1)
        return NULL;
    return my_str_to_word_array(content, "\n");
}