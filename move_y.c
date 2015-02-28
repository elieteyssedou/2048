/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_y.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eteyssed <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/27 23:20:26 by eteyssed          #+#    #+#             */
/*   Updated: 2015/02/28 17:57:06 by ahua             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "head.h"

void	move_up(int tab[4][4])
{
	int x;
	int y;

	x = -1;
	while (++x < 4)
	{
		y = -1;
		while (++y < 4)
		{
			if (y != 3 && tab[y][x] == tab[y + 1][x])
			{
				tab[y][x] *= 2;
				tab[y + 1][x] = 0;
			}
		}
		move_u(tab, x), move_u(tab, x), move_u(tab, x);
		add_num(tab, rand_num(), rand_24());
	}
}

void	move_u(int tab[4][4], int x)
{
	int y;

	y = 0;
	while (++y < 4)
	{
		if (tab[y - 1][x] == 0)
		{
			tab[y - 1][x] = tab[y][x];
			tab[y][x] = 0;
		}
	}
}

void	move_down(int tab[4][4])
{
	int x;
	int y;

	x = -1;
	while (++x < 4)
	{
		y = 4;
		while (--y > -1)
			if (y != 0 && tab[y][x] == tab[y - 1][x])
				tab[y][x] *= 2, tab[y - 1][x] = 0;
		move_d(tab, x), move_d(tab, x), move_d(tab, x);
		add_num(tab, rand_num(), rand_24());
	}
}

void	move_d(int tab[4][4], int x)
{
	int y;

	y = 3;
	while (--y > -1)
		if (tab[y + 1][x] == 0)
			tab[y + 1][x] = tab[y][x], tab[y][x] = 0;
}

