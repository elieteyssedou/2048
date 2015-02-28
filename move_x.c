/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_x.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eteyssed <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/27 23:15:54 by eteyssed          #+#    #+#             */
/*   Updated: 2015/02/28 18:01:01 by ahua             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "head.h"

void	move_left(int tab[4][4])
{
	int x;
	int y;

	y = -1;
	while (++y < 4)
	{
		x = -1;
		while (++x < 4)
		{
			if (x != 3 && tab[y][x] == tab[y][x + 1])
			{
				tab[y][x] *= 2;
				tab[y][x + 1] = 0;
			}
		}
		move_l(tab, y), move_l(tab, y), move_l(tab, y);
		add_num(tab, rand_num(), rand_24());
	}
}

void	move_l(int tab[4][4], int y)
{
	int x;

	x = 0;
	while (++x < 4)
	{
		if (tab[y][x - 1] == 0)
		{
			tab[y][x - 1] = tab[y][x];
			tab[y][x] = 0;
		}
	}
}

void	move_right(int tab[4][4])
{
	int x;
	int y;
	int tree;

	y = -1;
	tree = 3;
	while (++y < 4)
	{
		x = 4;
		while (--x > -1)
			if (x != 0 && tab[y][x] == tab[y][x - 1])
				tab[y][x] *= 2, tab[y][x - 1] = 0;
		move_r(tab, y), move_r(tab, y), move_r(tab, y);
		add_num(tab, rand_num(), rand_24());
	}
}

void	move_r(int tab[4][4], int y)
{
	int x;

	x = 3;
	while (--x > -1)
		if (tab[y][x + 1] == 0)
			tab[y][x + 1] = tab[y][x], tab[y][x] = 0;
}
