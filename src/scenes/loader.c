/*
** EPITECH PROJECT, 2021
** handling.c
** File description:
** Game arrow keys events handling
*/

#include <stdbool.h>
#include "my_rpg.h"
#include "macros.h"
#include "structs.h"

static void event_handling(loader_t *loader)
{
    while (sfRenderWindow_pollEvent(loader->window, &loader->event)) {
        continue;
    }
}

bool display_loader(loader_t *loader, int total)
{
    float percent = 0;
    sfIntRect rect = {0, 0, 439, 78};

    if (!loader || !loader->window || !loader->fill || !loader->bar)
        return false;
    event_handling(loader);
    percent = total == -1 ? 1 : (float) total / ASSETS_AMOUNT;
    rect.width = (int) (439 * percent);
    sfSprite_setTextureRect(loader->fill->sprite, rect);
    sfRenderWindow_drawSprite(loader->window, loader->bar->sprite, NULL);
    sfRenderWindow_drawSprite(loader->window, loader->fill->sprite, NULL);
    return true;
}
