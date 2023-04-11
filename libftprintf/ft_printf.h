/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmuni <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/23 18:56:23 by bmuni             #+#    #+#             */
/*   Updated: 2022/11/11 13:59:05 by bmuni            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H

# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdint.h>
# include "libft/libft.h"
# include "getnextline/get_next_line_bonus.h"

int		ft_printf(const char *s, ...);
int		ft_checkletter(const char *s, int i, va_list a);
int		ft_putstr(char *s, int fd);
int		ft_putchar(int a, int fd);
int		ft_nbrlen_printf(long int a);
int		ft_putnbr(int a, int fd);
int		ft_putunbr(unsigned int a, int fd);
int		ft_puthex(unsigned long int a, int fd, char c);
char	ft_assign(long unsigned int a, char c);
int		ft_putvoid(uintptr_t p, int fd);

#endif
