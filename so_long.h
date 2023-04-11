/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmuni <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 11:44:23 by bmuni             #+#    #+#             */
/*   Updated: 2022/12/09 16:48:11 by bmuni            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# define IMG_SIZE 64

# include "minilibx-linux/mlx.h"
# include "libftprintf/ft_printf.h"
# include <stdio.h>
//# include <curses.h>

typedef struct s_vector
{
	int	x;
	int	y;
}	t_vector;

typedef struct s_images
{
	void	*floor;
	void	*wall;
	void	*coll;
	void	*door_o;
	void	*door_c;
	void	*hero_1;
	void	*hero_2;
	void	*hero_3;
	void	*enemy_g;
	void	*enemy_f;
	void	*enemy_j;
	void	*move0;
	void	*move1;
	void	*move2;
	void	*move3;
	void	*move4;
	void	*move5;
	void	*move6;
	void	*move7;
	void	*move8;
	void	*move9;
}	t_images;

typedef struct s_player
{
	t_vector	pos;
	t_vector	old_pos;
}	t_player;

typedef struct s_map
{
	int	zero;
	int	one;
	int	c;
	int	e;
	int	p;
	int	m;
}	t_map;

typedef struct s_game
{
	void			*mlx;
	void			*window;
	int				collected;
	int				collects;
	int				moves;
	t_images		image;
	t_vector		size;
	t_vector		img_size;
	char			**map;
	t_map			map_components;
	t_player		player;
	t_vector		door_pos;
	int				text_col;
}	t_stru;

void	ft_free_double(char **s);
void	game_init(t_stru *princ, char *s);
char	**ft_alloc_map(char *s);
int		ft_map_lines(char *s);
int		ft_input(int in, t_stru *princ);
int		ft_check_map_components(char *s, t_stru *princ);
int		ft_anim(t_stru *princ);
int		ft_check_walls(char **map, char *s);
void	ft_free_t_image(t_stru *princ);
int		ft_quit(t_stru *princ);
char	**ft_read_map(char *argv);
void	ft_print_moves(t_stru *princ, int nb);
void	ft_print_coll(int nb, t_stru *princ);
void	ft_print_coll1(int nb, t_stru *princ);
void	ft_count_collects(t_stru *princ);
int		ft_find_enemy_x(int en, t_stru *princ);
int		ft_find_enemy_y(int en, t_stru *princ);

#endif
