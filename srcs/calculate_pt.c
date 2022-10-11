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
	pt->x += env->map->offset_x;
	pt->y += env->map->offset_y;
}

void	get_to_origin(t_env *env, t_point *pt)
{
	env->map->center->prev_x = (env->map->width - 1) \
	* env->map->zoom_factor / 2 + env->map->offset_x;
	env->map->center->prev_y = (env->map->height - 1) \
	* env->map->zoom_factor / 2 + env->map->offset_y;
	env->map->center->prev_z = env->map->min + \
	(abs(env->map->max - env->map->min) / 2.);
	pt->prev_x = (pt->prev_x - env->map->center->prev_x);
	pt->prev_y = (pt->prev_y - env->map->center->prev_y);
	pt->prev_z = (pt->prev_z - env->map->center->prev_z);
	rotate_point(env, pt);
	pt->x = env->map->center->prev_x + (pt->x - env->map->offset_x);
	pt->y = env->map->center->prev_y + (pt->y - env->map->offset_y);
	pt->bres_x = pt->x;
	pt->bres_y = pt->y;
}

void	get_cur_line_v3(t_env *env, int x, int y)
{
	env->pt1->prev_x = x * env->map->zoom_factor + env->map->offset_x;
	env->pt1->prev_y = y * env->map->zoom_factor + env->map->offset_y;
	env->pt1->prev_z = env->map->tab[y][x] * env->map->alt_factor;
	env->pt2->prev_x = (x + 1) * env->map->zoom_factor + env->map->offset_x;
	env->pt2->prev_y = y * env->map->zoom_factor + env->map->offset_y;
	env->pt2->prev_z = env->map->tab[y][x + 1] * env->map->alt_factor;
	get_to_origin(env, env->pt1);
	get_to_origin(env, env->pt2);
	env->pt1->color = get_color(env, env->map->tab[y][x]);
	env->pt2->color = get_color(env, env->map->tab[y][x + 1]);
}

void	get_cur_collumn_v3(t_env *env, int x, int y)
{
	env->pt1->prev_x = x * env->map->zoom_factor + env->map->offset_x;
	env->pt1->prev_y = y * env->map->zoom_factor + env->map->offset_y;
	env->pt1->prev_z = env->map->tab[y][x] * env->map->alt_factor;
	env->pt2->prev_x = x * env->map->zoom_factor + env->map->offset_x;
	env->pt2->prev_y = (y + 1) * env->map->zoom_factor + env->map->offset_y;
	env->pt2->prev_z = env->map->tab[y + 1][x] * env->map->alt_factor;
	get_to_origin(env, env->pt1);
	get_to_origin(env, env->pt2);
	env->pt1->color = get_color(env, env->map->tab[y][x]);
	env->pt2->color = get_color(env, env->map->tab[y + 1][x]);
}
