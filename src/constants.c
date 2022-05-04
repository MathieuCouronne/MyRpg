/*
** EPITECH PROJECT, 2021
** constants.h
** File description:
** my_rpg constants
*/

#include <SFML/Network.h>
#include "macros.h"

const char *class_names[] = {
    "Warrior", "Mage", "DogWarrior"
};

const char *class_textures[] = {
    WARRIOR_PATH, MAGE_PATH, DOGWARRIOR_PATH
};

const sfIpAddress FTP_IP = (sfIpAddress) {"185.31.40.91"};
const char *FTP_USER = "rpg";
const char *FTP_PWD = "rpg_password";
