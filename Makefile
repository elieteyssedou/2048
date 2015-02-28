# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: eteyssed <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/02/20 14:09:51 by eteyssed          #+#    #+#              #
#    Updated: 2015/02/20 14:09:52 by eteyssed         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	ft_minishell1
SRC		=	main.c move_x.c move_y.c
OBJ		=	$(SRC:.c=.o)
HDR		=	libft/
FLAGS	=	-Wall -Wextra -Werror -lncurses
CC		=	gcc

all: $(NAME)

%.o: %.c
	@$(CC) -O3 $(FLAGS) -I $(HDR) -I . -o $@ -c $?

$(NAME): $(OBJ)
	@make -C libft/ fclean
	@make -C libft/
	@$(CC) -O3 $(FLAGS) -o $(NAME) $(OBJ) libft/libft.a
	@echo "Sucess: Program compiled." 

clean:
	@rm -f $(OBJ)

fclean: clean
	@rm -f $(NAME)

re: fclean all
