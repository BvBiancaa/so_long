/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmuni <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 17:50:32 by bmuni             #+#    #+#             */
/*   Updated: 2022/12/08 21:17:31 by bmuni            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_print_map2(t_stru *princ, int x, int y)
{
	if (princ->map[y][x] == '0')
		mlx_put_image_to_window(princ->mlx, princ->window,
			princ->image.floor, princ->size.x, princ->size.y);
	if (princ->map[y][x] == '1')
		mlx_put_image_to_window(princ->mlx, princ->window,
			princ->image.wall, princ->size.x, princ->size.y);
	if (princ->map[y][x] == 'C')
		mlx_put_image_to_window(princ->mlx, princ->window,
			princ->image.coll, princ->size.x, princ->size.y);
	if (princ->map[y][x] == 'E')
		mlx_put_image_to_window(princ->mlx, princ->window,
			princ->image.door_c, princ->size.x, princ->size.y);
	if (princ->map[y][x] == 'P')
	{
		princ->player.pos.x = x;
		princ->player.pos.y = y;
		mlx_put_image_to_window(princ->mlx, princ->window,
			princ->image.hero_1, princ->size.x, princ->size.y);
		princ->map[y][x] = '0';
	}
	if (princ->map[y][x] == 'M')
		mlx_put_image_to_window(princ->mlx, princ->window,
			princ->image.enemy_f, princ->size.x, princ->size.y);
}

void	ft_print_map(t_stru *princ)
{
	int	x;
	int	y;

	y = 0;
	princ->size.y = 0;
	while (princ->map[y])
	{
		x = 0;
		princ->size.x = 0;
		while (princ->map[y][x])
		{
			ft_print_map2(princ, x, y);
			x++;
			princ->size.x += 64;
		}
		y++;
		princ->size.y += 64;
	}
}

void	ft_assign_img2(t_stru *princ)
{
	princ->image.floor = mlx_xpm_file_to_image(princ->mlx,
			"images/floor/floor.xpm", &princ->img_size.x, &princ->img_size.y);
	princ->image.coll = mlx_xpm_file_to_image(princ->mlx,
			"images/collect/beer.xpm", &princ->img_size.x, &princ->img_size.y);
	princ->image.door_c = mlx_xpm_file_to_image(princ->mlx,
			"images/door/closed.xpm", &princ->img_size.x, &princ->img_size.y);
	princ->image.door_o = mlx_xpm_file_to_image(princ->mlx,
			"images/door/open.xpm", &princ->img_size.x, &princ->img_size.y);
	princ->image.enemy_f = mlx_xpm_file_to_image(princ->mlx,
			"images/enemy/fall.xpm", &princ->img_size.x, &princ->img_size.y);
	princ->image.enemy_g = mlx_xpm_file_to_image(princ->mlx,
			"images/enemy/ground.xpm", &princ->img_size.x, &princ->img_size.y);
	princ->image.enemy_j = mlx_xpm_file_to_image(princ->mlx,
			"images/enemy/jump.xpm", &princ->img_size.x, &princ->img_size.y);
	princ->image.hero_1 = mlx_xpm_file_to_image(princ->mlx,
			"images/hero/pig0.xpm", &princ->img_size.x, &princ->img_size.y);
	princ->image.hero_2 = mlx_xpm_file_to_image(princ->mlx,
			"images/hero/pig1.xpm", &princ->img_size.x, &princ->img_size.y);
	princ->image.hero_3 = mlx_xpm_file_to_image(princ->mlx,
			"images/hero/pig2.xpm", &princ->img_size.x, &princ->img_size.y);
	princ->image.wall = mlx_xpm_file_to_image(princ->mlx,
			"images/wall/wall.xpm", &princ->img_size.x, &princ->img_size.y);
	princ->image.move0 = mlx_xpm_file_to_image(princ->mlx,
			"images/num/move0.xpm", &princ->img_size.x, &princ->img_size.y);
}

void	ft_assign_img(t_stru *princ)
{
	princ->image.move1 = mlx_xpm_file_to_image(princ->mlx,
			"images/num/move1.xpm", &princ->img_size.x, &princ->img_size.y);
	princ->image.move2 = mlx_xpm_file_to_image(princ->mlx,
			"images/num/move2.xpm", &princ->img_size.x, &princ->img_size.y);
	princ->image.move3 = mlx_xpm_file_to_image(princ->mlx,
			"images/num/move3.xpm", &princ->img_size.x, &princ->img_size.y);
	princ->image.move4 = mlx_xpm_file_to_image(princ->mlx,
			"images/num/move4.xpm", &princ->img_size.x, &princ->img_size.y);
	princ->image.move5 = mlx_xpm_file_to_image(princ->mlx,
			"images/num/move5.xpm", &princ->img_size.x, &princ->img_size.y);
	princ->image.move6 = mlx_xpm_file_to_image(princ->mlx,
			"images/num/move6.xpm", &princ->img_size.x, &princ->img_size.y);
	princ->image.move7 = mlx_xpm_file_to_image(princ->mlx,
			"images/num/move7.xpm", &princ->img_size.x, &princ->img_size.y);
	princ->image.move8 = mlx_xpm_file_to_image(princ->mlx,
			"images/num/move8.xpm", &princ->img_size.x, &princ->img_size.y);
	princ->image.move9 = mlx_xpm_file_to_image(princ->mlx,
			"images/num/move9.xpm", &princ->img_size.x, &princ->img_size.y);
	ft_assign_img2(princ);
}

void	game_init(t_stru *princ, char *s)
{
	princ->mlx = mlx_init();
	princ->window = mlx_new_window(princ->mlx,
			(ft_strlen(princ->map[0]) - 1) * 64,
			(ft_map_lines(s) - 1) * 64, "so_long");
	princ->moves = 0;
	princ->collected = 0;
	princ->collects = 0;
	ft_count_collects(princ);
	ft_assign_img(princ);
	ft_print_map(princ);
	ft_print_coll(princ->collected, princ);
	ft_print_moves(princ, princ->moves);
}
