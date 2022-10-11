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
	env->map->zoom_factor = 10;
	env->map->alt_factor = 5;
	env->map->angle_z = 0.785;
	env->map->angle_x = 1.047;
	env->map->angle_y = 0;
	env->map->width = 0;
	env->map->height = 0;
	env->map->is_flipped = 1;
	env->map->offset_x = 0;// get center;
	env->map->offset_y = 0;// get center;
	env->map->center = ce;
	env->map->tab = read_map_v2(env, file);
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
}
