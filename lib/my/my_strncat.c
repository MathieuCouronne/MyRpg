/*
** EPITECH PROJECT, 2021
** my_strncat
** File description:
** Concatenate two strings
*/

int my_strlen(char const *str);

char *my_strncat(char *dest, char const *src, int nb)
{
    int dest_length = my_strlen(dest);
    unsigned int size = nb;
    int j = 0;

    for (int i = 0; i < dest_length + size; i++) {
        if (i >= dest_length) {
            dest[i] = src[j];
            j++;
        }
    }
    return dest;
}
