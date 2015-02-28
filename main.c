/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eteyssed <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/27 20:20:46 by eteyssed          #+#    #+#             */
/*   Updated: 2015/02/27 23:40:24 by ahua             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "head.h"

int main()
{
	int ch;

	initscr();
	//start_color();
	noecho();
	raw();

	int tab[4][4] = {	{2, 2, 0, 2},
						{2, 0, 4, 4},
						{0, 2, 0, 2},
						{2, 2, 2, 2} };

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
	while (ch != 32)
	{
		//attron(COLOR_PAIR(1));
		wclear(stdscr);
		show_tab(tab);
		//attroff(COLOR_PAIR(1));
		dup_tab(tab, otab);
		ch = getch(); /* Wait for user input */
		if (ch == 68)
			move_left(tab);
		else if (ch == 67)
			move_right(tab);
		else if (ch == 65)
			move_up(tab);
		else if (ch == 66)
			move_down(tab);
		comp_tab(tab, otab); // SI COMP TAB RENVOIS 1 ALORS ON FAIS ADD NUM, CONDITION A RAJOUTER !!!!
		refresh();
	}
	endwin();
	return (0);
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
			otab[y][x] == tab[y][x]
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
