/*
** EPITECH PROJECT, 2021
** constants.h
** File description:
** my_rpg constants
*/

#include <SFML/Network.h>
#include "macros.h"
#include "character.h"
#include "structs.h"

const sfIpAddress FTP_IP = (sfIpAddress) {"185.31.40.91"};
const char *FTP_USER = "rpg";
const char *FTP_PWD = "RaphiMathithouMathissouJoshitou35000?!";

const char *class_names[] = {
    "Warrior", "Mage", "DogWarrior"
};

const char *class_textures[] = {
    WARRIOR_PATH, MAGE_PATH, DOGWARRIOR_PATH
};

const int class_base_data[3][5] = {
    {BASE_WAR_STR, BASE_WAR_DEF, BASE_WAR_VIT, BASE_WAR_SPD, BASE_WAR_DEX},
    {BASE_MAGE_STR, BASE_MAGE_DEF, BASE_MAGE_VIT, BASE_MAGE_SPD, BASE_MAGE_DEX},
    {BASE_DOG_STR, BASE_DOG_DEF, BASE_DOG_VIT, BASE_DOG_SPD, BASE_DOG_DEX}
};
