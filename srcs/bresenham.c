/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bresenham_v2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znogueir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 02:03:38 by znogueir          #+#    #+#             */
/*   Updated: 2022/10/11 02:07:57 by znogueir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	plot_line_low_v2(t_env *env, t_point *pt1, t_point *pt2, int i)
{
	env->brm->x = pt1->x;
	env->brm->y = pt1->y;
	env->brm->dx = pt2->x - pt1->x;
	env->brm->dy = pt2->y - pt1->y;
	env->brm->yi = 1;
	if (env->brm->dy < 0)
	{
		env->brm->yi = -1;
		env->brm->dy = -env->brm->dy;
	}
	env->brm->delta = (2 * env->brm->dy) - env->brm->dx;
	while (env->brm->x < pt2->x)
	{
		put_pixel_to_img(env, env->brm->x, env->brm->y, \
		get_gradient(env, env->brm->x, env->brm->y, i));
		if (env->brm->delta > 0)
		{
			env->brm->y = env->brm->y + env->brm->yi;
			env->brm->delta = env->brm->delta + (2 * \
			(env->brm->dy - env->brm->dx));
		}
		else
			env->brm->delta = env->brm->delta + 2 * env->brm->dy;
		env->brm->x++;
	}
}

void	plot_line_high_v2(t_env *env, t_point *pt1, t_point *pt2, int i)
{
	env->brm->x = pt1->x;
	env->brm->y = pt1->y;
	env->brm->dx = pt2->x - pt1->x;
	env->brm->dy = pt2->y - pt1->y;
	env->brm->xi = 1;
	if (env->brm->dx < 0)
	{
		env->brm->xi = -1;
		env->brm->dx = -env->brm->dx;
	}
	env->brm->delta = (2 * env->brm->dx) - env->brm->dy;
	while (env->brm->y < pt2->y)
	{
		put_pixel_to_img(env, env->brm->x, env->brm->y, \
		get_gradient(env, env->brm->x, env->brm->y, i));
		if (env->brm->delta > 0)
		{
			env->brm->x = env->brm->x + env->brm->xi;
			env->brm->delta = env->brm->delta + (2 * \
			(env->brm->dx - env->brm->dy));
		}
		else
			env->brm->delta = env->brm->delta + 2 * env->brm->dx;
		env->brm->y++;
	}
}

void	plot_line_v2(t_env *env)
{
	if (abs(env->pt2->y - env->pt1->y) < \
	abs(env->pt2->x - env->pt1->x))
	{
		if (env->pt1->x > env->pt2->x)
			plot_line_low_v2(env, env->pt2, env->pt1, 1);
		else
			plot_line_low_v2(env, env->pt1, env->pt2, -1);
	}	
	else
	{
		if (env->pt1->y > env->pt2->y)
			plot_line_high_v2(env, env->pt2, env->pt1, 1);
		else
			plot_line_high_v2(env, env->pt1, env->pt2, -1);
	}
}
