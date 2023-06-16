/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmuni <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 11:43:34 by bmuni             #+#    #+#             */
/*   Updated: 2022/12/08 23:57:17 by bmuni            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_count_collects(t_stru *princ)
{
	int	x;
	int	y;

	y = 0;
	while (princ->map[y])
	{
		x = 0;
		while (princ->map[y][x])
		{
			if (princ->map[y][x] == 'E')
			{
				princ->door_pos.x = x;
				princ->door_pos.y = y;
			}
			if (princ->map[y][x] == 'C')
				princ->collects++;
			x++;
		}
		y++;
	}
}

char	**ft_read_map(char *argv)
{
	char	**map;
	int		i;
	int		fd;

	fd = open(argv, O_RDONLY);
	i = -1;
	map = ft_alloc_map(argv);
	while (1)
	{
		map[++i] = get_next_line(fd);
		if (map[i] == NULL)
			break ;
	}
	close (fd);
	return (map);
}

char	**ft_map_setup(int argc, char **argv, t_stru *princ)
{
	char	**map;
	char	**map1;

	if (ft_check_map_components(argv[1], princ) == 0)
		return (NULL);
	map = ft_read_map(argv[1]);
	if (!map)
		return (NULL);
	map1 = ft_read_map(argv[1]);
	if (!map1)
		return (NULL);
	if (ft_check_walls(map1, argv[1]) == 0)
	{
		ft_free_double(map);
		ft_free_double(map1);
		return (NULL);
	}
	ft_free_double(map1);
	return (map);
}

int	ft_setup(t_stru *princ, int argc, char **argv)
{
	princ->moves = 0;
	princ->map_components.c = 0;
	princ->map_components.zero = 0;
	princ->text_col = 0xFF0000;
	princ->map_components.e = 0;
	princ->map_components.p = 0;
	princ->map_components.m = 0;
	princ->img_size.x = 64;
	princ->img_size.y = 64;
	princ->map_components.one = 0;
	princ->moves = 0;
	princ->map = ft_map_setup(argc, argv, princ);
	if (princ->map == NULL)
		return (ft_printf("Error\n"));
	game_init(princ, argv[1]);
	return (0);
}

int	main(int argc, char **argv)
{
	t_stru	princ;

	if (ft_setup(&princ, argc, argv) != 0)
		exit(0);
	mlx_hook(princ.window, 2, (1l << 0), ft_input, &princ);
	mlx_hook(princ.window, 17, 0, ft_quit, &princ);
	mlx_loop_hook(princ.mlx, ft_anim, &princ);
	mlx_loop(princ.mlx);
}
