/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eteyssed <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/27 20:20:46 by eteyssed          #+#    #+#             */
/*   Updated: 2015/02/28 22:42:38 by ahua             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "head.h"

int main()
{
	//int	x;
	//int	y;
	int ch;
	int	max_y;
	int	max_x;

	initscr();
	//start_color();
	noecho();
	//raw();
	int otab[4][4];
	int	tab[4][4];

	//x = 5;
	//y = 5;
	initab(tab);
	//start_color();

	// init_color(COLOR_RED, 238, 228, 217);
	// init_color(4, 243, 178, 116);
	// init_color(8, 247, 149, 93);
	// init_color(16, 248, 124, 90);
	// init_color(32, 249, 93, 50);
	// init_color(64, 238, 208, 107);
	// init_color(128, 238, 205, 88);
	// init_color(256, 237, 200, 67);
	// init_color(512, 238, 198, 44);
	// init_color(1024, 237, 195, 9);
	//init_color(2048, );
	getmaxyx(stdscr, max_y, max_x);
	while (ch != 113)
	{
		getmaxyx(stdscr, max_y, max_x);
		//mvwhline(stdscr, (max_y / 4) * 1, 1, 0, max_x - 1);
		//mvwhline(stdscr, (max_y / 4) * 2, 1, 0, max_x - 1);
		//mvwhline(stdscr, (max_y / 4) * 3, 1, 0, max_x - 1);
		wclear(stdscr);
		box(stdscr, 0, 0);
		mvwhline(stdscr, (max_y / 4) * 1, 1, 0, max_x - 2);
		mvwhline(stdscr, (max_y / 4) * 2, 1, 0, max_x - 2);
		mvwhline(stdscr, (max_y / 4) * 3, 1, 0, max_x - 2);
		mvwvline(stdscr, 1, (max_x / 4) * 1, 0, max_y - 2);
		mvwvline(stdscr, 1, (max_x / 4) * 2, 0, max_y - 2);
		mvwvline(stdscr, 1, (max_x / 4) * 3, 0, max_y - 2);
		//attron(COLOR_PAIR(4));
		//attron(COLOR_PAIR(1));
		//wclear(stdscr);
		show_tab(tab, max_x / 8, max_y / 8);
		//attroff(COLOR_PAIR(1));
		dup_tab(tab, otab);
		ch = getch();
		if (ch == 68)
			move_left(tab);
		else if (ch == 67)
			move_right(tab);
		else if (ch == 65)
			move_up(tab);
		else if (ch == 66)
			move_down(tab);
		if (comp_tab(tab, otab))
			add_num(tab, rand_num(), rand_24());
		else if (!comp_tab(tab, otab) && !test_zero(tab) && !test_move(tab, otab))
		{
			//wclear(stdscr);
			mvprintw(max_y / 2, max_x / 2, "YOU LOSE !");
			mvprintw(max_y / 2 + 1, max_x / 2, "Press \"Q\" to exit.");
			break;
		}
		//refresh();
	}
	while (ch != 113)
		ch = getch();
	endwin();
	return (0);
}

int test_move(int tab[4][4], int otab[4][4])
{
	move_down(tab);
	if (comp_tab(tab, otab))
	{
		dup_tab(tab, otab);
		return (1);
	}
	dup_tab(tab, otab);
	move_up(tab);
	if (comp_tab(tab, otab))
	{
		dup_tab(tab, otab);
		return (1);
	}
	dup_tab(tab, otab);
	move_left(tab);
	if (comp_tab(tab, otab))
	{
		dup_tab(tab, otab);
		return (1);
	}
	dup_tab(tab, otab);
	move_right(tab);
	if (comp_tab(tab, otab))
	{
		dup_tab(tab, otab);
		return (1);
	}
	dup_tab(tab, otab);
	return (0);
}

void	initab(int tab[4][4])
{
	int x;
	int	y;

	y = -1;
	while (++y < 4)
	{
		x = -1;
		while (++x < 4)
			tab[y][x] = 0;
	}
	srand(time(NULL));
	tab[rand() % 4][rand() % 4] = 2;
	add_num(tab, rand_num(), rand_24());
}

int comp_tab(int tab[4][4], int otab[4][4])
{
	int y;
	int x;

	y = -1;
	while (++y < 4)
	{
		x = -1;
		while (++x < 4)
		{
			if (tab[y][x] != otab[y][x])
				return (1);
		}
	}
	return (0);
}

void dup_tab(int tab[4][4], int otab[4][4])
{
	int y;
	int x;

	y = -1;
	while (++y < 4)
	{
		x = -1;
		while (++x < 4)
			otab[y][x] = tab[y][x];
	}
}

void	show_tab(int tab[4][4], int max_x, int max_y)
{
	int x;
	int y;

	y = -1;
	while (++y < 4)
	{
		x = -1;
		while (++x < 4)
		{
			if (tab[y][x])
				mvprintw((y * 2 + 1) * max_y, (x * 2 + 1) * max_x, "%d", tab[y][x]);
			// else
			// {
			// 	mvprintw(y * 5, x * 10, "%d", tab[y][x]);
			// }	
		}
	}
}

int		rand_24(void)
{
	int	r;
	srand(time(NULL));
	r = rand() % 100;
	if (r <= 10)
		return (4);
	return (2);
}

int		rand_num(void)
{
	srand(time(NULL));
	return (rand() % 24);
}

int		add_num(int tab[4][4], int r, int num)
{
	int	x;
	int	y;
	int	index;

	index = 0;
	y = -1;
	while (++y < 4)
	{
		x = -1;
		while (++x < 4)
		{
			if (tab[y][x] == 0)
			{
				index = 1;
				if (r > 0)
					r--;
				else
				{
					tab[y][x] = num;
					return (1);
				}
			}
		}
		if (y == 3 && index == 1)
		{
			y = -1;
			x = -1;
		}
	}
	return (0);
}

int test_zero(int tab[4][4])
{
	int y;
	int x;

	y = -1;
	while (++y < 4)
	{
		x = -1;
		while (++x < 4)
		{
			if (tab[y][x] == 0)
				return (1);
		}
	}
	return (0);
}
/*int my_rand(void)
{
	static int tab[N];
	static int first = 0;
	int index;
	int rn;

	if (first == 0)
	{
		int i;

		srand(time(NULL));
		i = 0;
		while (i++ < N)
			tab[i] = rand();
		first = 1;
	}
	index = (int)(rand() / RAND_MAX * (N - 1));
	rn = tab[index];
	tab[index] = rand();
	ft_putnbr(rn);
	return (rn);
}*/
