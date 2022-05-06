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

char const *quest1[3][5] = {
    {
        "Hey lad ! Come here ! I need help..." \
        "I'm getting old, as you can see around you, some trolls took control" \
        "of the western part of the village.",
        "I would be grateful if you could please get rid of them and" \
        "bring me 5 of their fangs so I can brew some potions please ?",
        NULL
    },
    {
        "-Oh here you are already ! Have you done what I asked ?"
        "......",
        "I can see you collected thoses fangs ! Thank you very much for" \
        "your help... But I have something else to ask...",
        "I accidentally dropped my book behind the Church... Could you bring" \
        "it to me ? I'm kind of scared to go there... Who knows what could" \
        "happen to an old man like me...",
        NULL
    },
    {
        "Thank you young man ! I really appreciate what you've done for me.",
        "! Now that I think about it, I think you could give a hand near the" \
        "burnt land, go there and you'll meet a friend of mine.",
        "Everybody here calls him Uo, you should also ask him for some food," \
        "he is a really good chief, but... don't be in a hurry...",
        "He is pretty slow at cooking... Anyways !" \
        "You're free to go ! Thank you again my friend.",
        NULL
    }
};
