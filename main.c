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

int	main(void)
{
	t_max	max;
	int		ch;
	int		w;
	int		otab[4][4];
	int		tab[4][4];

	w = 0;
	all_init(tab);
	getmaxyx(stdscr, max.max_y, max.max_x);
	while (ch != 27)
	{
		print_box(max.max_x, max.max_y, tab, 0);
		dup_tab(tab, otab);
		loose(tab, otab, &max, &ch);
		ch = getch();
		moves(ch, tab);
		win(tab, &max, &ch, &w);
		if (ch != 27 && comp_tab(tab, otab))
			add_num(tab, rand_num(), rand_24());
	}
	endwin();
	return (0);
}

void	loose(int tab[4][4], int otab[4][4], t_max *max, int *ch)
{
	if (*ch != 27 && !comp_tab(tab, otab) && !test_zero(tab)
		&& !test_move(tab, otab))
	{
		print_box(max->max_x, max->max_y, tab, 2);
		*ch = getch();
		while (*ch != 27)
			*ch = getch(), print_box(max->max_x, max->max_y, tab, 2);
		endwin();
		exit(0);
	}
}

void	win(int tab[4][4], t_max *max, int *ch, int *w)
{
	if (!(*w) && test_win(tab))
	{
		print_box(max->max_x, max->max_y, tab, 1);
		*ch = getch();
		while (*ch != 32 && *ch != 27)
			*ch = getch(), print_box(max->max_x, max->max_y, tab, 1);
		*w = 1;
	}
}

void	moves(int ch, int tab[4][4])
{
	if (ch == 260)
		move_left(tab);
	else if (ch == 261)
		move_right(tab);
	else if (ch == 259)
		move_up(tab);
	else if (ch == 258)
		move_down(tab);
}

void	ft_exit_power(void)
{
	if (!WIN_VALUE || (WIN_VALUE & (WIN_VALUE - 1) || WIN_VALUE == 1))
	{
		ft_putstr("WIN VALUE is not a 2 power\n");
		exit (0);
	}
}

int		test_win(int tab[4][4])
{
	int	x;
	int	y;

	y = -1;
	while (++y < 4)
	{
		x = -1;
		while (++x < 4)
		{
			if (tab[y][x] == WIN_VALUE)
			{
				return (1);
			}
		}
	}
	return (0);
}

int test_move(int tab[4][4], int otab[4][4])
{
	int i;

	i = 0;
	move_down(tab);
	if (comp_tab(tab, otab))
		dup_tab(otab, tab), i = 1;
	dup_tab(otab, tab), move_up(tab);
	if (comp_tab(tab, otab))
		dup_tab(otab, tab), i = 1;
	dup_tab(otab, tab), move_left(tab);
	if (comp_tab(tab, otab))
		dup_tab(otab, tab), i = 1;
	dup_tab(otab, tab), move_right(tab);
	if (comp_tab(tab, otab))
		dup_tab(otab, tab), i = 1;
	dup_tab(otab, tab);
	return (i = 1 ? 1 : 0);
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
		if (y == 3 && index == 1)
			y = -1;
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
