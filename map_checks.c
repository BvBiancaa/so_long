/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checks.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmuni <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 21:45:13 by bmuni             #+#    #+#             */
/*   Updated: 2022/12/08 21:50:16 by bmuni            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_check_map_ext(char *s, t_stru *princ)
{
	int	i;

	i = -1;
	while (s[++i])
	{
		if (s[i] == '.')
			if (s[i + 1] == 'b')
				if (s[i + 2] == 'e')
					if (s[i + 3] == 'r')
						if (s[i + 4] == '\0')
							return (1);
	}
	if (ft_strlen(princ->map[0]) != ft_map_lines(s))
		return (1);
	return (0);
}

int	ft_check_com_str(char *s, t_stru *princ)
{
	if (princ->map_components.c == 0)
		return (0);
	if (princ->map_components.e != 1)
		return (0);
	if (princ->map_components.p != 1)
		return (0);
	else
		return (ft_check_map_ext(s, princ));
}

int	ft_assign_one(t_stru *princ, char c)
{
	if (c == '0')
		princ->map_components.zero++;
	else if (c == '1')
		princ->map_components.one++;
	else if (c == 'C')
		princ->map_components.c++;
	else if (c == 'E')
		princ->map_components.e++;
	else if (c == 'P')
		princ->map_components.p++;
	else if (c == 'M')
		princ->map_components.m++;
	else if (c != '\n')
		return (0);
	return (1);
}

int	ft_check_map_components(char *s, t_stru *princ)
{
	char	c;
	int		fd;
	int		a;

	fd = open(s, O_RDONLY);
	while (1)
	{
		a = read(fd, &c, 1);
		if (a == 0 || a == -1)
			break ;
		if (ft_assign_one(princ, c) == 0)
			return (0);
	}
	return (ft_check_com_str(s, princ));
}
