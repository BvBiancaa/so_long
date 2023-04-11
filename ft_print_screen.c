/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_screen.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmuni <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 21:25:40 by bmuni             #+#    #+#             */
/*   Updated: 2022/12/08 21:27:13 by bmuni            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_put2(int nb, t_stru *princ, int x, int y)
{
	if (nb % 10 == 5)
		mlx_put_image_to_window(princ->mlx,
			princ->window, princ->image.move5, x, y);
	else if (nb % 10 == 6)
		mlx_put_image_to_window(princ->mlx,
			princ->window, princ->image.move6, x, y);
	else if (nb % 10 == 7)
		mlx_put_image_to_window(princ->mlx,
			princ->window, princ->image.move7, x, y);
	else if (nb % 10 == 8)
		mlx_put_image_to_window(princ->mlx,
			princ->window, princ->image.move8, x, y);
	else if (nb % 10 == 9)
		mlx_put_image_to_window(princ->mlx,
			princ->window, princ->image.move9, x, y);
}

void	ft_put(int nb, t_stru *princ, int x, int y)
{
	if (nb % 10 == 0)
		mlx_put_image_to_window(princ->mlx,
			princ->window, princ->image.move0, x, y);
	else if (nb % 10 == 1)
		mlx_put_image_to_window(princ->mlx,
			princ->window, princ->image.move1, x, y);
	else if (nb % 10 == 2)
		mlx_put_image_to_window(princ->mlx,
			princ->window, princ->image.move2, x, y);
	else if (nb % 10 == 3)
		mlx_put_image_to_window(princ->mlx,
			princ->window, princ->image.move3, x, y);
	else if (nb % 10 == 4)
		mlx_put_image_to_window(princ->mlx,
			princ->window, princ->image.move4, x, y);
	else
		ft_put2(nb, princ, x, y);
}

void	ft_print_coll(int nb, t_stru *princ)
{
	static int	i;

	i++;
	if (i <= 2)
		ft_put(nb, princ, (3 - i) * 64, 0);
	if (i == 3)
	{
		i = 0;
		return ;
	}
	else
		ft_print_coll(nb / 10, princ);
}

void	ft_print_moves(t_stru *princ, int nb)
{
	static int	i;

	i++;
	if (i <= 4)
		ft_put(nb, princ, (ft_strlen(princ->map[0]) - (2 + i)) * 64, 0);
	if (i == 5)
	{
		i = 0;
		return ;
	}
	else
		ft_print_moves(princ, nb / 10);
}
