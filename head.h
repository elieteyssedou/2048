/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   head.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eteyssed <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/27 20:21:02 by eteyssed          #+#    #+#             */
/*   Updated: 2015/02/27 20:21:05 by eteyssed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEAD_H
# define HEAD_H

# include "libft/libft.h"
# include <ncurses.h>


void	show_tab(int tab[4][4]);

void	move_left(int tab[4][4]);
void	move_l(int tab[4][4], int y);

void	move_right(int tab[4][4]);
void	move_r(int tab[4][4], int y);

void	move_up(int tab[4][4]);
void	move_u(int tab[4][4], int x);

void	move_down(int tab[4][4]);
void	move_d(int tab[4][4], int x);

#endif
