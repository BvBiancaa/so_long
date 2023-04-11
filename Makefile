# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bmuni <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/07 22:00:25 by bmuni             #+#    #+#              #
#    Updated: 2022/12/08 23:55:32 by bmuni            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

all: so_long

so_long:
	make -C libftprintf
	gcc -g main.c ft_input.c extra.c ft_print_screen.c map_checks.c utils_map.c utils_map_mem.c libftprintf/libftprintf.a minilibx-linux/libmlx.a -lm -lX11 -lXext -o so_long

clean:
	make -C libftprintf clean
	rm -f *.o

fclean: clean
	make -C libftprintf fclean
	rm -f so_long

re: fclean all

.PHONY: all, clean, fclean, re

