/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znogueir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 02:11:45 by znogueir          #+#    #+#             */
/*   Updated: 2022/10/11 02:21:21 by znogueir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	check_if_flipped(t_env *env)
{
	if (env->map->angle_x >= 3.142 && env->map->angle_x <= 6.283)
		env->map->is_flipped *= -1;
	if (env->map->angle_z > 1.585 && env->map->angle_z <= 4.712)
		env->map->is_flipped *= -1;
}

void	put_pixel_to_img(t_env *env, int x, int y, int color)
{
	char	*dst;

	if (x > 0 && x < 1920 && y > 0 && y < 1080)
	{
		dst = env->addr + (y * env->line_length + x \
		* (env->bits_per_pixel / 8));
		*(unsigned int *)dst = color;
	}
}

void	project(t_env *env, int x, int y, int rev)
{
	if (x < env->map->width - 1)
	{
		get_cur_line_v3(env, x, y);
		plot_line_v2(env);
	}
	if (y < env->map->height - 1)
	{
		get_cur_collumn_v3(env, x, y);
		plot_line_v2(env);
	}
}

void	ft_rev_display_v2(t_env *env)
{
	int	x;
	int	y;

	env->img = mlx_new_image(env->mlx, 1920, 1080);
	env->addr = mlx_get_data_addr(env->img, &env->bits_per_pixel, \
	&env->line_length, &env->endian);
	y = env->map->height - 1;
	while (y >= 0)
	{
		x = env->map->width - 1;
		while (x >= 0)
		{
			project(env, x, y, 1);
			put_pixel_to_img(env, x, y, 0xFF0000);
			x--;
		}
		y--;
	}
	mlx_put_image_to_window(env->mlx, env->mlx_win, env->img, 0, 0);
	mlx_destroy_image(env->mlx, env->img);
	env->map->is_flipped = 1;
}

void	ft_display_v2(t_env *env)
{
	int	x;
	int	y;

	env->img = mlx_new_image(env->mlx, 1920, 1080);
	env->addr = mlx_get_data_addr(env->img, &env->bits_per_pixel, \
	&env->line_length, &env->endian);
	y = 0;
	while (y < env->map->height)
	{
		x = 0;
		while (x < env->map->width)
		{
			project(env, x, y, 0);
			put_pixel_to_img(env, x, y, 0xFF0000);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(env->mlx, env->mlx_win, env->img, 0, 0);
	mlx_destroy_image(env->mlx, env->img);
}
