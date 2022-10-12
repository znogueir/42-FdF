/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculate_pt.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znogueir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 02:08:10 by znogueir          #+#    #+#             */
/*   Updated: 2022/10/11 02:09:42 by znogueir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	get_center(t_env *env)
{
	env->map->center->prev_x = (env->map->width - 1) / 2;
	env->map->center->prev_y = (env->map->height - 1) / 2;
	env->map->center->prev_z = env->map->min + \
	(fabs(env->map->max - env->map->min) / 2.);
}

void	rotate_point(t_env *env, t_point *pt)
{
	float	x;
	float	y;
	float	z;

	x = pt->prev_x * cos(env->map->angle_z) - \
	pt->prev_y * sin(env->map->angle_z);
	y = pt->prev_x * sin(env->map->angle_z) + \
	pt->prev_y * cos(env->map->angle_z);
	z = pt->prev_z;
	pt->prev_z = z * cos(env->map->angle_y) - x * sin(env->map->angle_y);
	pt->prev_x = z * sin(env->map->angle_y) + x * cos(env->map->angle_y);
	pt->prev_y = y;
	pt->y = pt->prev_y * cos(env->map->angle_x) - \
	pt->prev_z * sin(env->map->angle_x);
	pt->z = pt->prev_y * sin(env->map->angle_x) + \
	pt->prev_z * cos(env->map->angle_x);
	pt->x = pt->prev_x;
}

void	zoom_and_rotate(t_env *env, t_point *pt)
{
	get_center(env);
	pt->prev_x = (pt->prev_x) * env->map->zoom_factor;
	pt->prev_y = (pt->prev_y) * env->map->zoom_factor;
	pt->prev_z = pt->prev_z * env->map->alt_factor;
	rotate_point(env, pt);
	pt->x += env->map->offset_x;
	pt->y += env->map->offset_y;
}

void	get_cur_line_v3(t_env *env, int x, int y)
{
	env->pt1->prev_x = x - env->map->center->prev_x;
	env->pt1->prev_y = y - env->map->center->prev_y;
	env->pt1->prev_z = env->map->tab[y][x];
	env->pt2->prev_x = (x + 1) - env->map->center->prev_x;
	env->pt2->prev_y = y - env->map->center->prev_y;
	env->pt2->prev_z = env->map->tab[y][x + 1];
	zoom_and_rotate(env, env->pt1);
	zoom_and_rotate(env, env->pt2);
	env->pt1->color = get_color(env, env->map->tab[y][x]);
	env->pt2->color = get_color(env, env->map->tab[y][x + 1]);
}

void	get_cur_collumn_v3(t_env *env, int x, int y)
{
	env->pt1->prev_x = x - env->map->center->prev_x;
	env->pt1->prev_y = y - env->map->center->prev_y;
	env->pt1->prev_z = env->map->tab[y][x];
	env->pt2->prev_x = x - env->map->center->prev_x;
	env->pt2->prev_y = (y + 1) - env->map->center->prev_y;
	env->pt2->prev_z = env->map->tab[y + 1][x];
	zoom_and_rotate(env, env->pt1);
	zoom_and_rotate(env, env->pt2);
	env->pt1->color = get_color(env, env->map->tab[y][x]);
	env->pt2->color = get_color(env, env->map->tab[y + 1][x]);
}
