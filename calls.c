/*
** EPITECH PROJECT, 2017
** 
** File description:
** calls main fonctions of hunter
*/

#include "include/hunter.h"

void set_texture(sfTexture *texture, sfSprite *back, sfTexture *tt, sfSprite *duck)
{
	sfSprite_setTexture(back, texture, sfTrue);
	sfSprite_setTexture(duck, tt, sfTrue);
}

void display_window(sfRenderWindow *window, sfSprite *back, sfSprite *duck)
{
	sfRenderWindow_clear(window, sfBlack);
	sfRenderWindow_drawSprite(window, back, NULL);
	sfRenderWindow_drawSprite(window, duck, NULL);
	sfRenderWindow_display(window);
}

void destroy_ressources(sfMusic *music, sfTexture *texture, sfSprite *duck, sfSprite *back)
{
	sfMusic_destroy(music);
	sfTexture_destroy(texture);
	sfSprite_destroy(duck);
	sfSprite_destroy(back);
}
