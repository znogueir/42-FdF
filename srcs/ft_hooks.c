/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hooks.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znogueir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 01:58:34 by znogueir          #+#    #+#             */
/*   Updated: 2022/10/11 01:59:16 by znogueir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

// void	ft_close_hook(t_env *env, int keycode)
// {
// }

void	ft_switch_colors(t_env *env, int keycode)
{
	if (keycode == K_MINUS)
	{
		if (env->theme > 0)
			env->theme--;
		else
			env->theme = 6;
	}
	if (keycode == K_PLUS)
	{
		if (env->theme < 6)
			env->theme++;
		else
			env->theme = 0;
	}
}

void	ft_switch_views(t_env *env, int keycode)
{
	if (keycode == K_Z)
		env->map->angle_z = 0;
	if (keycode == K_X)
		env->map->angle_x = 0;
	if (keycode == K_I)
	{
		ft_animate(1.047, 0.785, env);
		env->map->angle_x = 1.047;
		env->map->angle_z = 0.785;
		env->map->is_flipped = 1;
	}
	if (keycode == K_P)
	{
		ft_animate(1.047, 0, env);
		env->map->angle_x = 1.047;
		env->map->angle_z = 0;
		env->map->is_flipped = 1;
	}
}

void	ft_rotate_view(t_env *env, int keycode)
{
	if (keycode == K_G)
		env->map->angle_z += 0.1;
	if (keycode == K_J)
		env->map->angle_z -= 0.1;
	if (keycode == K_H)
		env->map->angle_x += 0.1;
	if (keycode == K_Y)
		env->map->angle_x -= 0.1;
	if (env->map->angle_x >= 6.283)
		env->map->angle_x -= 6.283;
	if (env->map->angle_x < 0)
		env->map->angle_x += 6.283;
	if (env->map->angle_y >= 6.283)
		env->map->angle_y -= 6.283;
	if (env->map->angle_y < 0)
		env->map->angle_y += 6.283;
	if (env->map->angle_z >= 6.283)
		env->map->angle_z -= 6.283;
	if (env->map->angle_z < 0)
		env->map->angle_z += 6.283;
	check_if_flipped(env);
}

void	ft_move_view(t_env *env, int keycode)
{
	if (keycode == K_W)
		env->map->offset_y -= 15;
	if (keycode == K_A)
		env->map->offset_x -= 15;
	if (keycode == K_S)
		env->map->offset_y += 15;
	if (keycode == K_D)
		env->map->offset_x += 15;
	if (keycode == K_UP)
		env->map->zoom_factor += 1;
	if (keycode == K_DWN)
		env->map->zoom_factor -= 1;
	if (keycode == K_LFT)
		env->map->alt_factor -= 1;
	if (keycode == K_RGT)
		env->map->alt_factor += 1;
}
