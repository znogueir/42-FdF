/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znogueir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 02:13:10 by znogueir          #+#    #+#             */
/*   Updated: 2022/10/11 02:13:58 by znogueir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	get_initial_zoom(t_env *env)
{
	float	zoom_w;
	float	zoom_h;

	zoom_w = WIN_W / (env->map->width * 1.5);
	zoom_h = WIN_H / (env->map->height * 0.75);
	if (zoom_w > zoom_h)
		env->map->initial_zoom = zoom_h;
	else
	env->map->initial_zoom = zoom_w;
	env->map->zoom_factor = env->map->initial_zoom;
	if (env->map->height < 100 && env->map->width < 100)
		env->map->initial_alt = 20;
	else
	{
		if (env->map->height > env->map->width)
			env->map->initial_alt = env->map->height / \
			fabs(env->map->max - env->map->min);
		else
			env->map->initial_alt = env->map->width / \
			fabs(env->map->max - env->map->min);
	}
	env->map->alt_factor = env->map->initial_alt;
}

void	get_min(t_env *env)
{
	int	x;
	int	y;
	int	min;

	min = env->map->tab[0][0];
	y = 0;
	while (y < env->map->height)
	{
		x = 0;
		while (x < env->map->width)
		{
			if (env->map->tab[y][x] < min)
				min = env->map->tab[y][x];
			x++;
		}
		y++;
	}
	env->map->min = min;
}

void	get_max(t_env *env)
{
	int	x;
	int	y;
	int	max;

	max = env->map->tab[0][0];
	y = 0;
	while (y < env->map->height)
	{
		x = 0;
		while (x < env->map->width)
		{
			if (env->map->tab[y][x] > max)
				max = env->map->tab[y][x];
			x++;
		}
		y++;
	}
	env->map->max = max;
}

void	ft_init_map(t_env *env, int file)
{
	t_point		*ce;

	ce = malloc(sizeof(t_point));
	env->map->center = ce;
	env->map->angle_z = 0.785;
	env->map->angle_x = 1.047;
	env->map->angle_y = 0;
	env->map->width = 0;
	env->map->height = 0;
	env->map->is_flipped = 1;
	env->map->offset_x = 960;
	env->map->offset_y = 540;
	env->map->tab = read_map_v2(env, file);
}

void	ft_init(int file, t_env *env)
{
	t_map	*alloc_map;
	t_point	*point1;
	t_point	*point2;
	t_brm	*br;

	alloc_map = malloc(sizeof(t_map));
	point1 = malloc(sizeof(t_point));
	point2 = malloc(sizeof(t_point));
	br = malloc(sizeof(t_brm));
	env->map = alloc_map;
	env->pt1 = point1;
	env->pt2 = point2;
	env->theme = 2;
	env->brm = br;
	ft_init_map(env, file);
	env->mlx = mlx_init();
	env->mlx_win = mlx_new_window(env->mlx, WIN_W, WIN_H, \
	"Fdf #UwU#");
	env->img = mlx_new_image(env->mlx, WIN_W, WIN_H);
	get_min(env);
	get_max(env);
	get_center(env);
	get_initial_zoom(env);
}
