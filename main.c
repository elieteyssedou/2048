/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eteyssed <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/27 20:20:46 by eteyssed          #+#    #+#             */
/*   Updated: 2015/02/27 22:25:35 by ahua             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "head.h"

int main(int ac, char **av)
{
	int ch;

	initscr();
	start_color();
	noecho();
	raw();

	int tab[4][4] = {	{2, 2, 0, 0},
						{2, 2, 4, 4},
						{0, 2, 2, 0},
						{2, 2, 2, 2} };

	while (ch != 32)
	{
		show_tab(tab);
		ch = getch(); /* Wait for user input */
		if (ch == 68)
			move_left(tab);
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
			attron(COLOR_RED);
			if (tab[y][x] == 0)
				mvprintw(y * 5, x * 10, "0");
			else
				mvprintw(y * 5, x * 10, "%d", tab[y][x]);
			attroff(COLOR_RED);	
		}
	}
}
