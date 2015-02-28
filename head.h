/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   head.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eteyssed <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/27 20:21:02 by eteyssed          #+#    #+#             */
/*   Updated: 2015/02/28 18:27:50 by ahua             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEAD_H
# define HEAD_H

# include "libft.h"
# include <ncurses.h>
# include <stdlib.h>
# define N 30


void	show_tab(int tab[4][4]);

void	move_left(int tab[4][4]);
void	move_l(int tab[4][4], int y);
//int		my_rand(void);
int		rand_24(void);
int		rand_num(void);
void	add_num(int tab[4][4], int r, int num);


void	move_right(int tab[4][4]);
void	move_r(int tab[4][4], int y);

void	move_up(int tab[4][4]);
void	move_u(int tab[4][4], int x);

void	move_down(int tab[4][4]);
void	move_d(int tab[4][4], int x);

int comp_tab(int tab[4][4], int otab[4][4]);
void dup_tab(int tab[4][4], int otab[4][4]);

#endif
