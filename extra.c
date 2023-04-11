/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extra.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmuni <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 23:44:21 by bmuni             #+#    #+#             */
/*   Updated: 2022/12/08 23:44:23 by bmuni            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_path_check(char **map)
{
	int	x;
	int	y;

	y = -1;
	while (map[++y])
	{
		x = -1;
		while (map[y][++x])
		{
			if (map[y][x] != '1' && map[y][x] != '\n')
				return (0);
		}
	}
	return (1);
}

int	ft_check_valid_path(char **m_check, int x, int y)
{
	if (m_check[y][x] != '1')
		m_check[y][x] = '1';
	if (m_check[y][x + 1] != '1')
		ft_check_valid_path(m_check, x + 1, y);
	if (m_check[y][x - 1] != '1')
		ft_check_valid_path(m_check, x - 1, y);
	if (m_check[y + 1][x] != '1')
		ft_check_valid_path(m_check, x, y + 1);
	if (m_check[y - 1][x] != '1')
		ft_check_valid_path(m_check, x, y - 1);
	return (ft_path_check(m_check));
}

int	ft_check_walls(char **map, char *s)
{
	int	x;
	int	y;
	int	len;

	y = -1;
	len = ft_strlen(map[0]);
	while (map[++y])
	{
		x = -1;
		if (ft_strlen(map[y]) != len && (y < ft_map_lines(s) - 1))
			return (0);
		while (map[y][++x])
		{
			if (y == 0 && map[y][x] != '1' && x != ft_strlen(map[0]) - 1)
				return (0);
			else if ((y == ft_map_lines(s) - 1) && map[y][x] != '1')
				return (0);
			else if ((x == 0 || x == ft_strlen(map[1])) && map[y][x] != '1')
				return (0);
		}
	}
	return (ft_check_valid_path(map, ft_strlen(map[0]) / 2,
			ft_map_lines(s) / 2));
}

int	ft_find_enemy_x(int en, t_stru *princ)
{
	int	x;
	int	y;

	y = 0;
	while (princ->map[y])
	{
		x = 0;
		while (princ->map[y][x])
		{
			if (princ->map[y][x] == 'M')
				en--;
			if (en < 0)
				return (x);
			x++;
		}
		y++;
	}
	return (-1);
}

int	ft_find_enemy_y(int en, t_stru *princ)
{
	int	x;
	int	y;

	y = 0;
	while (princ->map[y])
	{
		x = 0;
		while (princ->map[y][x])
		{
			if (princ->map[y][x] == 'M')
				en--;
			if (en < 0)
				return (y);
			x++;
		}
		y++;
	}
	return (-1);
}
