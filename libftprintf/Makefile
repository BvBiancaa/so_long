# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bmuni <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/23 19:14:06 by bmuni             #+#    #+#              #
#    Updated: 2022/11/06 12:53:13 by bmuni            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=libftprintf.a

all: $(NAME)

$(NAME):
	make bonus -C libft
	make bonus -C getnextline
	gcc -Wall -Wextra -Werror -c ft_printf.c ft_printf_nbr.c
	ar -rc $(NAME) *.o libft/*.o getnextline/*.o
	ranlib $(NAME)

clean:
	rm -f *.o
	rm -f libft/*.o
	rm -f getnextline/*.o

fclean: clean
	rm -f $(NAME)
	rm -f libft/libft.a
	rm -f getnextline/getnextline.a

re: fclean all

.PHONY: all, clean, fclean, re
