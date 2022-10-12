/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animate.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znogueir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 02:03:13 by znogueir          #+#    #+#             */
/*   Updated: 2022/10/11 02:03:24 by znogueir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

float	get_step(float target, float angle)
{
	float	med;

	med = 3.142 + target;
	if (angle > med)
		return (6.283 - angle + target);
	return (target - angle);
}

void	ft_animate_view(float target_x, float target_z, t_env *env)
{
	float	step_x;
	float	step_z;
	int		i;

	i = 0;
	if (env->map->angle_x == target_x && env->map->angle_z == target_z)
		return ;
	step_x = get_step(target_x, env->map->angle_x) / 35;
	step_z = get_step(target_z, env->map->angle_z) / 35;
	while (i < 35)
	{
		env->map->angle_x += step_x;
		env->map->angle_z += step_z;
		check_if_flipped(env);
		if (env->map->is_flipped == -1)
			ft_rev_display_v2(env);
		else
			ft_display_v2(env);
		i++;
	}
	env->map->angle_x = target_x;
	env->map->angle_z = target_z;
}

void	ft_animate_center(t_env *env)
{
	int	i;

	i = 0;
	if (env->map->offset_x == WIN_W / 2 && env->map->offset_y == WIN_H \
	/ 2 && env->map->zoom_factor == env->map->initial_zoom && \
	env->map->alt_factor == env->map->initial_alt)
		return ;
	env->step_x = (960 - env->map->offset_x) / 35;
	env->step_y = (540 - env->map->offset_y) / 35;
	env->step_zoom = (env->map->initial_zoom - env->map->zoom_factor) / 35;
	env->step_alt = (env->map->initial_alt - env->map->alt_factor) / 35;
	while (i < 35)
	{
		env->map->offset_x += env->step_x;
		env->map->offset_y += env->step_y;
		env->map->zoom_factor += env->step_zoom;
		env->map->alt_factor += env->step_alt;
		check_if_flipped(env);
		if (env->map->is_flipped == -1)
			ft_rev_display_v2(env);
		else
			ft_display_v2(env);
		i++;
	}
	check_if_flipped(env);
}
