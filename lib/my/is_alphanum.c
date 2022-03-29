/*
** EPITECH PROJECT, 2021
** is_alphanum
** File description:
** Check if a character is alphanumeric
*/

int is_anum(char const str)
{
    int is_num = (str >= '0' && '9' >= str);
    int is_alpha = (str >= 'a' && 'z' >= str) || (str >= 'A' && 'Z' >= str);

    return (is_alpha || is_num);
}
