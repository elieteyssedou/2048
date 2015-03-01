/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   head.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eteyssed <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/27 20:21:02 by eteyssed          #+#    #+#             */
/*   Updated: 2015/02/28 22:24:01 by ahua             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEAD_H
# define HEAD_H

# include "libft.h"
# include <ncurses.h>
# include <stdlib.h>
# include <time.h>

typedef struct	s_max
{
	int			max_x;
	int			max_y;
}				t_max;

enum e_const
{
	WIN_VALUE = 32
};

void	move_left(int tab[4][4]);
//int		my_rand(void);
int		rand_24(void);
int		rand_num(void);
int		add_num(int tab[4][4], int r, int num);

void	move_right(int tab[4][4]);

void	move_up(int tab[4][4]);

void	move_down(int tab[4][4]);

int 	comp_tab(int tab[4][4], int otab[4][4]);
void	dup_tab(int tab[4][4], int otab[4][4]);

int test_move(int tab[4][4], int otab[4][4]);
int test_zero(int tab[4][4]);

int		test_win(int tab[4][4]);
void	print_box(int max_x, int max_y, int tab[4][4], int p);

void	ft_exit_power(void);
void	moves(int ch, int tab[4][4]);
void	all_init(int tab[4][4]);
void	win(int tab[4][4], t_max *max, int *ch, int *w);
void	loose(int tab[4][4], int otab[4][4], t_max *max, int *ch);

#endif
