/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eteyssed <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/27 20:20:46 by eteyssed          #+#    #+#             */
/*   Updated: 2015/02/27 23:37:49 by ahua             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "head.h"

int main(int ac, char **av)
{
	int ch;

	initscr();
	//start_color();
	noecho();
	raw();

	int tab[4][4] = {	{2, 2, 0, 0},
						{2, 2, 4, 4},
						{0, 2, 2, 0},
						{2, 2, 2, 2} };

	start_color();
	init_color(COLOR_RED, 238, 228, 217);
	init_color(4, 243, 178, 116);
	init_color(8, 247, 149, 93);
	init_color(16, 248, 124, 90);
	init_color(32, 249, 93, 50);
	init_color(64, 238, 208, 107);
	init_color(128, 238, 205, 88);
	init_color(256, 237, 200, 67);
	init_color(512, 238, 198, 44);
	init_color(1024, 237, 195, 9);
	//init_color(2048, );
	while (ch != 32)
	{
		//attron(COLOR_PAIR(1));
		show_tab(tab);
		//attroff(COLOR_PAIR(1));
		ch = getch(); /* Wait for user input */
		if (ch == 68)
		{
			//attron(COLOR_PAIR(1));
			move_left(tab);
			//attroff(COLOR_PAIR(1));
		}
		refresh();
	}
	endwin();
}

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
}

void	move_right(int tab[4][4])
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
}

void	show_tab(int tab[4][4])
{
	int x;
	int y;

	y = -1;
	while (++y < 4)
	{
		x = -1;
		while (++x < 4)
		{
			if (tab[y][x] == 0)
				mvprintw(y * 5, x * 10, "0");
			else
			{
				if (tab[y][x] == 2)
				{
					attron(512);
					mvprintw(y * 5, x * 10, "%d", tab[y][x]);
					attroff(512);
				}
			}	
		}
	}
}
