/*
** EPITECH PROJECT, 2022
** open_file.c
** File description:
** Open file
*/

unsigned int get_2d_array_length(char **array)
{
    unsigned int length = 0;

    if (!array)
        return 0;
    for (unsigned int i = 0; array[i]; i++)
        length++;
    return length;
}
