/*
** EPITECH PROJECT, 2022
** RPG
** File description:
** Download assets from FTP
*/

#include <SFML/Network.h>
#include <stdlib.h>
#include "my_rpg.h"
#include "my.h"
#include "menu.h"
#include "messages.h"

static char *directories[] = {
    "fonts", "sounds", "images/characters", "images/fight",
    "images/main_menu", "images/maps", "images/misc",
    "images/settings", "images/pause", "images/saves", NULL
};

static int display_status(char *str, int status)
{
    my_putstr(str);
    return status;
}

static char *concat(char *str)
{
    char *base = "assets/";
    size_t len = my_strlen(base) + my_strlen(str);
    char *new = malloc(sizeof(char) * (len + 1));
    size_t pos = 0;

    if (!new)
        return NULL;
    for (size_t i = 0; base[i] != '\0'; i++)
        new[pos++] = base[i];
    for (size_t i = 0; str[i] != '\0'; i++)
        new[pos++] = str[i];
    new[len] = '\0';
    return new;
}

static bool download_file(sfFtp *ftp, char *folder, sfFtpListingResponse *list,
size_t i)
{
    sfFtpResponse *res = NULL;
    char const *name = sfFtpListingResponse_getName(list, i);

    if (!name)
        return display_status(FTP_FILE_DOWNLOAD_FAILED, 0);
    res = sfFtp_download(ftp, name, concat(folder), sfFtpBinary);
    if (!sfFtpResponse_isOk(res)) {
        my_printf(FTP_FILE_DOWNLOAD_FAILED, name);
        return false;
    }
    my_printf(FTP_FILE_DOWNLOADED, name);
    return true;
}

static bool download_folder(sfFtp *ftp, char *folder)
{
    sfFtpListingResponse *list = sfFtp_getDirectoryListing(ftp, concat(folder));
    size_t size = 0;

    my_printf(FTP_STARTS_DOWNLOAD, folder);
    if (!sfFtpListingResponse_isOk(list))
        return display_status(FTP_WRONG_IDS, 0);
    size = sfFtpListingResponse_getCount(list);
    for (size_t i = 0; i < size; i++) {
        if (!download_file(ftp, folder, list, i))
            return display_status(FTP_DOWNLOAD_FAILED, false);
    }
    return display_status(FTP_DOWNLOAD_SUCCESSFUL, true);
}

bool download_assets(void)
{
    sfIpAddress ip = (sfIpAddress) {"185.31.40.91"};
    sfFtp *ftp = sfFtp_create();
    sfFtpResponse *res = sfFtp_connect(ftp, ip, 21, sfSeconds(5));
    bool status = true;

    if (!sfFtpResponse_isOk(res))
        return display_status(FTP_NO_CONNECTION, false);
    res = sfFtp_login(ftp, "rpg", "rpg_password");
    if (!sfFtpResponse_isOk(res))
        return display_status(FTP_WRONG_IDS, false);
    for (unsigned short i = 0; directories[i]; i++) {
        if (!download_folder(ftp, directories[i])) {
            status = false;
            break;
        }
    }
    if (ftp)
        sfFtp_disconnect(ftp);
    return status;
}
