/*
** EPITECH PROJECT, 2021
** my_strcat
** File description:
** Concatenate two strings
*/

int my_strlen(char const *str);

char *my_strcat(char *dest, char const *src)
{
    int dest_length = my_strlen(dest);
    int src_length = my_strlen(src);
    int j = 0;

    for (int i = 0; i < dest_length + src_length; i++) {
        if (i >= dest_length) {
            dest[i] = src[j];
            j++;
        }
    }
    return dest;
}
