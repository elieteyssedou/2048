/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eteyssed <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/27 20:20:46 by eteyssed          #+#    #+#             */
/*   Updated: 2015/02/28 18:25:54 by ahua             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "head.h"

int main()
{
	int ch;
	int	max_y;
	int	max_x;
	int	oldx;
	int	oldy;

	initscr();
	//start_color();
	noecho();
	raw();

	int tab[4][4] = {	{0, 2, 0, 2},
						{0, 2, 4, 4},
						{2, 0, 0, 2},
						{0, 2, 2, 2} };

	start_color();

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
	while (ch != 32)
	{
		oldx = max_x;
		oldy = max_y;
		getmaxyx(stdscr, max_y, max_x);
		box(stdscr, 0, 0);
		if (oldx != max_x || oldy != max_y)
			wclear(stdscr);
		
		
			
		
		//attron(COLOR_PAIR(4));
		//attron(COLOR_PAIR(1));
		wclear(stdscr);
		show_tab(tab);
		//attroff(COLOR_PAIR(4));
		ch = getch(); /* Wait for user input */
		if (ch == 68)
			move_left(tab);
		}
		else if (ch == 67)
			move_right(tab);
		else if (ch == 65)
			move_up(tab);
		else if (ch == 66)
			move_down(tab);

		//printw("KEYCODE = %d\n", ch);
		refresh();
	}
	endwin();
	return (0);
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

				// if (tab[y][x] == 2)
				// {
					//attron(512);
					mvprintw(y * 5, x * 10, "%d", tab[y][x]);
					//attroff(512);
				// }
			}	
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
	else if (r > 10)
		return (2);
}

int		rand_num(void)
{
	srand(time(NULL));
	return (rand() % 20);
}

void	add_num(int tab[4][4], int r, int num)
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
					return ;
				}
			}
		}
		if (y == 3 && index == 1)
		{
			y = -1;
			x = -1;
		}
	}
	if (index == 0)
		return ;
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
