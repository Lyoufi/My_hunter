/*
** EPITECH PROJECT, 2017
** 
** File description:
**
*/

#ifndef HUNTER_H
#define HUNTER_H_

#include <SFML/Graphics.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <SFML/Audio.h>
#include <stdbool.h>

void	my_putchar(char c);
int	my_put_nbr(int nb);
void	set_texture(sfTexture *texture, sfSprite *back, sfTexture *tt, sfSprite *duck);
void	display_window(sfRenderWindow *window, sfSprite *back, sfSprite *duck);
void	destroy_ressources(sfMusic *music, sfTexture *texture, sfSprite *duck, sfSprite *back);

#endif	/* HUNTER_H_ */
