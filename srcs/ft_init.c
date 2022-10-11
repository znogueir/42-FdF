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

void	get_center(t_env *env)
{
	env->map->center->prev_x = (env->map->width - 1) \
	* env->map->zoom_factor / 2 + env->map->offset_x;
	env->map->center->prev_y = (env->map->height - 1) \
	* env->map->zoom_factor / 2 + env->map->offset_y;
	env->map->center->prev_z = env->map->min * env->map->alt_factor + \
	(fabs(env->map->max * env->map->alt_factor - env->map->min * env->map->alt_factor) / 2.);
	env->map->offset_x = 960 - env->map->center->prev_x;
	env->map->offset_y = 540 - env->map->center->prev_y;
}

void	get_initial_zoom(t_env *env)
{
	float	zoom_w;
	float	zoom_h;

	zoom_w = 1920 / (env->map->width * 1.5);
	zoom_h = 1080 / (env->map->height * 1.5);
	if (zoom_w > zoom_h)
		env->map->zoom_factor = zoom_h;
	else
		env->map->zoom_factor = zoom_w;
	env->map->alt_factor = env->map->zoom_factor / 2;
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
	env->map->offset_x = 0;// get center;
	env->map->offset_y = 0;// get center;
	env->map->tab = read_map_v2(env, file);
	get_initial_zoom(env);
}

void	ft_init(int file, t_env *env)
{
	t_map	*alloc_map;
	t_point	*point1;
	t_point	*point2;

	alloc_map = malloc(sizeof(t_map));
	point1 = malloc(sizeof(t_point));
	point2 = malloc(sizeof(t_point));
	env->map = alloc_map;
	env->pt1 = point1;
	env->pt2 = point2;
	env->theme = 2;
	ft_init_map(env, file);
	env->mlx = mlx_init();
	env->mlx_win = mlx_new_window(env->mlx, 1920, 1080, "Fdf #UwU#");
	get_min(env);
	get_max(env);
	get_center(env);
}
