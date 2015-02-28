/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_y.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eteyssed <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/27 23:20:26 by eteyssed          #+#    #+#             */
/*   Updated: 2015/02/27 23:25:26 by eteyssed         ###   ########.fr       */
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
			if (y != 3 && tab[y + 1][x] == 0 && tab[y + 2][x] == 0 && tab[y][x] == tab[y + 3][x])
				tab[y][x] *= 2, tab[y + 3][x] = 0;
			else if (y < 2 && tab[y + 1][x] == 0 && tab[y][x] == tab[y + 2][x])
				tab[y][x] *= 2, tab[y + 2][x] = 0;
			else if (y < 1 && tab[y][x] == tab[y + 1][x])
				tab[y][x] *= 2, tab[y + 1][x] = 0;
		}
		move_u(tab, x), move_u(tab, x), move_u(tab, x);
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

	x = 0;
	while (x < 4)
	{
		y = 4;
		while (--y > -1)
			if (y > 2 && tab[y - 1][x] == 0 && tab[y - 2][x] == 0 && tab[y][x] == tab[y - 3][x])
				tab[y][x] *= 2, tab[y - 3][x] = 0;
			else if (y > 1 && tab[y - 1][x] == 0 && tab[y][x] == tab[y - 2][x])
				tab[y][x] *= 2, tab[y - 2][x] = 0;
			else if (y != 0 && tab[y][x] == tab[y - 1][x])
				tab[y][x] *= 2, tab[y - 1][x] = 0;
			
		move_d(tab, x), move_d(tab, x), move_d(tab, x);
		x++;
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

