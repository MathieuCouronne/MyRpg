/*
** EPITECH PROJECT, 2022
** RPG
** File description:
** Download assets from FTP
*/

#include <SFML/Network.h>
#include <stdio.h>
#include <stdlib.h>
#include "my_rpg.h"
#include "my.h"
#include "menu.h"
#include "display.h"

static char *directories[] = {
    "fonts", "sounds", "images/characters", "images/fight",
    "images/main_menu", "images/maps", "images/misc",
    "images/settings", "images/pause", NULL
};

static int display_status(char *str, int status)
{
    my_putstr(str);
    return status;
}

static char *concat(char *str2)
{
    char *str1 = "assets/";
    size_t len = my_strlen(str1) + my_strlen(str2);
    char *new = malloc(sizeof(char) * (len + 1));
    size_t pos = 0;

    if (!new)
        return NULL;
    for (size_t i = 0; str1[i] != '\0'; i++)
        new[pos++] = str1[i];
    for (size_t i = 0; str2[i] != '\0'; i++)
        new[pos++] = str2[i];
    new[len] = '\0';
    return new;
}

static bool download_folder(sfFtp *ftp, char *folder)
{
    sfFtpResponse *res = NULL;
    sfFtpListingResponse *list = sfFtp_getDirectoryListing(ftp, concat(folder));
    size_t size = 0;
    char *dest_path = NULL;

    my_printf("Starts downloading assets from folder '%s'.\n", folder);
    if (!sfFtpListingResponse_isOk(list))
        return display_status("", 0);
    size = sfFtpListingResponse_getCount(list);
    for (size_t i = 0; i < size; i++) {
        char const *name = sfFtpListingResponse_getName(list, i);
        if (!name)
            return display_status("Download failed.\n", 0);
        dest_path = concat(folder);
        res = sfFtp_download(ftp, name, dest_path, sfFtpBinary);
        if (!sfFtpResponse_isOk(res)) {
            printf("Error here: %s", sfFtpResponse_getMessage(res));
            return display_status("Download failed.\n", 0);
        }
        my_printf("\tAssets '%s' downloaded.\n", name);
    }
    return display_status("Download successfull.\n", 1);
}

bool download_assets(void)
{
    sfIpAddress ip = (sfIpAddress) {"185.31.40.91"};
    sfFtp *ftp = sfFtp_create();
    sfFtpResponse *res = sfFtp_connect(ftp, ip, 21, sfSeconds(5));

    if (!sfFtpResponse_isOk(res))
        return display_status("Server connection failed.\n", false);
    res = sfFtp_login(ftp, "rpg", "rpg_password");
    if (!sfFtpResponse_isOk(res))
        return display_status("Fail to download assets\n", false);
    for (unsigned short i = 0; directories[i]; i++)
        download_folder(ftp, directories[i]);
    return true;
}
