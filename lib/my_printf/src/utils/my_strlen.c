/*
** EPITECH PROJECT, 2021
** my_strlen
** File description:
** Count length of character
*/

int my_strlen(char const *str)
{
    int length = 0;
    for (int i = 0; str[i] != '\0'; i++) {
        length++;
    }
    return length;
}
