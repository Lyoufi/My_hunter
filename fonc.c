/*
** EPITECH PROJECT, 2017
** 
** File description:
** 2 printable fonctions
*/

#include "include/hunter.h"

void my_putchar(char c)
{
	write(1, &c, 1);
}

int my_put_nbr(int nb)
{
	if (nb < 0) {
		my_putchar('-');
		nb = -nb;
	} else if (nb >= 9){
		my_put_nbr(nb / 10);
		my_putchar(nb % 10 + 48);
	} else
		my_putchar(nb + 48);
	return (0);
}
