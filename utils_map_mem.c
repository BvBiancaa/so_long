/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_map_mem.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmuni <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 17:26:01 by bmuni             #+#    #+#             */
/*   Updated: 2022/12/08 21:18:49 by bmuni            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_free_double(char **s)
{
	int	y;

	y = -1;
	while (s[++y])
		free(s[y]);
	free(s);
}

int	ft_map_lines(char *s)
{
	int		fd;
	int		lines;
	int		nb;
	char	c;

	lines = 0;
	fd = open(s, O_RDONLY);
	if (!fd || fd < 0 || fd > 1024)
		return (-1);
	while (1)
	{
		nb = read(fd, &c, 1);
		if (c == '\n')
			lines++;
		if (nb == 0)
			break ;
		if (nb < 0)
			return (-1);
	}
	close (fd);
	return (lines);
}

char	**ft_alloc_map(char *s)
{
	int		lines;
	char	**map;

	lines = ft_map_lines(s);
	if (lines <= 0)
	{
		ft_printf("La mappa inserita ha troppe poche linee");
		return (NULL);
	}
	map = malloc(sizeof(char *) * (lines + 1));
	if (!map)
	{
		ft_printf("Errore di allocazione nella mappa");
		return (NULL);
	}
	return (map);
}

void	ft_free_image(t_stru *princ)
{
	mlx_destroy_image(princ->mlx, princ->image.door_c);
	mlx_destroy_image(princ->mlx, princ->image.door_o);
	mlx_destroy_image(princ->mlx, princ->image.enemy_f);
	mlx_destroy_image(princ->mlx, princ->image.enemy_g);
	mlx_destroy_image(princ->mlx, princ->image.enemy_j);
	mlx_destroy_image(princ->mlx, princ->image.floor);
	mlx_destroy_image(princ->mlx, princ->image.hero_1);
	mlx_destroy_image(princ->mlx, princ->image.hero_2);
	mlx_destroy_image(princ->mlx, princ->image.hero_3);
	mlx_destroy_image(princ->mlx, princ->image.wall);
	mlx_destroy_image(princ->mlx, princ->image.coll);
	mlx_destroy_image(princ->mlx, princ->image.move0);
	mlx_destroy_image(princ->mlx, princ->image.move1);
	mlx_destroy_image(princ->mlx, princ->image.move2);
	ft_free_double(princ->map);
}

int	ft_quit(t_stru *princ)
{
	mlx_destroy_image(princ->mlx, princ->image.move3);
	mlx_destroy_image(princ->mlx, princ->image.move4);
	mlx_destroy_image(princ->mlx, princ->image.move5);
	mlx_destroy_image(princ->mlx, princ->image.move6);
	mlx_destroy_image(princ->mlx, princ->image.move7);
	mlx_destroy_image(princ->mlx, princ->image.move8);
	mlx_destroy_image(princ->mlx, princ->image.move9);
	ft_free_image(princ);
	mlx_destroy_window(princ->mlx, princ->window);
	mlx_destroy_display(princ->mlx);
	free(princ->mlx);
	exit(0);
}
