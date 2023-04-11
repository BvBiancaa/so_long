/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_input.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmuni <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 20:46:16 by bmuni             #+#    #+#             */
/*   Updated: 2022/12/09 17:20:05 by bmuni            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_print_anim(t_stru *princ, int i, int en)
{
	if (i < 1500)
		mlx_put_image_to_window(princ->mlx, princ->window,
			princ->image.enemy_f, ft_find_enemy_x(en, princ) * 64,
			ft_find_enemy_y(en, princ) * 64);
	else if (i < 3000)
		mlx_put_image_to_window(princ->mlx, princ->window,
			princ->image.enemy_g, ft_find_enemy_x(en, princ) * 64,
			ft_find_enemy_y(en, princ) * 64);
	else if (i < 4500)
		mlx_put_image_to_window(princ->mlx, princ->window,
			princ->image.enemy_j, ft_find_enemy_x(en, princ) * 64,
			ft_find_enemy_y(en, princ) * 64);
}

int	ft_anim(t_stru *princ)
{
	static int	i;
	int			en;

	en = 0;
	if (i < 1500)
		mlx_put_image_to_window(princ->mlx, princ->window, princ->image.hero_1,
			princ->player.pos.x * 64, princ->player.pos.y * 64);
	else if (i < 3000)
		mlx_put_image_to_window(princ->mlx, princ->window, princ->image.hero_2,
			princ->player.pos.x * 64, princ->player.pos.y * 64);
	else if (i < 4500)
		mlx_put_image_to_window(princ->mlx, princ->window, princ->image.hero_3,
			princ->player.pos.x * 64, princ->player.pos.y * 64);
	while (ft_find_enemy_x(en, princ) != -1 && ft_find_enemy_y(en, princ) != -1)
	{
		ft_print_anim(princ, i, en);
		en++;
	}
	i++;
	if (i == 4500)
		i = 0;
	return (0);
}

int	ft_update_map(t_stru *princ)
{
	princ->moves++;
	if (princ->map[princ->player.pos.y][princ->player.pos.x] == 'O')
		ft_quit(princ);
	if (princ->map[princ->player.pos.y][princ->player.pos.x] == 'M')
		ft_quit(princ);
	mlx_put_image_to_window(princ->mlx, princ->window, princ->image.floor,
		princ->player.old_pos.x * 64, princ->player.old_pos.y * 64);
	mlx_put_image_to_window(princ->mlx, princ->window, princ->image.hero_1,
		princ->player.pos.x * 64, princ->player.pos.y * 64);
	if (princ->collected == princ->collects)
	{
		mlx_put_image_to_window(princ->mlx, princ->window, princ->image.door_o,
			princ->door_pos.x * 64, princ->door_pos.y * 64);
		princ->map[princ->door_pos.y][princ->door_pos.x] = 'O';
	}
	ft_print_moves(princ, princ->moves);
	ft_print_coll(princ->collected, princ);
	return (0);
}

void	ft_move_player(int in, t_stru *princ, int x, int y)
{
	if (in == 65307)
		ft_quit(princ);
	else if (in == 97 && (princ->map[y][x - 1] != 49
		&& princ->map[y][x - 1] != 'E'))
		princ->player.pos.x = x - 1;
	else if (in == 119 && (princ->map[y - 1][x] != 49
		&& princ->map[y - 1][x] != 'E'))
		princ->player.pos.y = y - 1;
	else if (in == 115 && (princ->map[y + 1][x] != 49
		&& princ->map[y + 1][x] != 'E'))
		princ->player.pos.y = y + 1;
	else if (in == 100 && (princ->map[y][x + 1] != 49
		&& princ->map[y][x + 1] != 'E'))
		princ->player.pos.x = x + 1;
}

int	ft_input(int in, t_stru *princ)
{
	int	x;
	int	y;

	princ->player.old_pos.x = princ->player.pos.x;
	princ->player.old_pos.y = princ->player.pos.y;
	x = princ->player.old_pos.x;
	y = princ->player.old_pos.y;
	ft_move_player(in, princ, x, y);
	if (princ->map[princ->player.pos.y][princ->player.pos.x] == 'C')
	{
		princ->collected += 1;
		princ->map[princ->player.pos.y][princ->player.pos.x] = '0';
	}
	return (ft_update_map(princ));
}
