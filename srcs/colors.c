/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znogueir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 01:59:49 by znogueir          #+#    #+#             */
/*   Updated: 2022/10/11 02:02:34 by znogueir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int	get_color(t_env *env, int alt)
{
	if (env->theme == 0)
		return (0xFFFFFF);
	else if (env->theme == 1)
		return (get_elevation_theme(env, alt));
	else if (env->theme == 2)
		return (get_rb_theme(env, alt));
	else if (env->theme == 3)
		return (get_realist_theme(env, alt));
	else if (env->theme == 4)
		return (get_purple_theme(env, alt));
	else if (env->theme == 5)
		return (get_frozen_theme(env, alt));
	else
		return (get_matrix_theme(env, alt));
}

void	decimal_to_rgb(int c, int *rgb)
{
	int	g;
	int	r;

	rgb[2] = c % 256;
	g = (c % 65536 - rgb[2]);
	r = c - g - rgb[3];
	rgb[1] = g / 256;
	rgb[0] = r / 65536;
}

int	get_distance(int x1, int y1, int x2, int y2)
{
	if (abs(x2 - x1) >= abs(y2 - y1))
		return (abs(x2 - x1));
	else
		return (abs(y2 - y1));
}

void	calculate_rgb(int *rgb, int *rgb1, int *rgb2, int p)
{
	rgb[0] = rgb2[0] + (rgb1[0] - rgb2[0]) * (p / 100.);
	rgb[1] = rgb2[1] + (rgb1[1] - rgb2[1]) * (p / 100.);
	rgb[2] = rgb2[2] + (rgb1[2] - rgb2[2]) * (p / 100.);
}

int	get_gradient(t_env *env, int x, int y, int i)
{
	float	diff;
	int		rgb1[3];
	int		rgb2[3];
	int		rgb[3];
	float	p;

	if (env->pt1->color == env->pt2->color)
		return (env->pt1->color);
	decimal_to_rgb(env->pt1->color, rgb1);
	decimal_to_rgb(env->pt2->color, rgb2);
	diff = get_distance(env->pt1->x, env->pt1->y, env->pt2->x, env->pt2->y);
	if (i < 0)
	{
		p = get_distance(x, y, env->pt1->x, env->pt1->y) * 100. / diff;
		calculate_rgb(rgb, rgb2, rgb1, p);
	}
	else
	{
		p = get_distance(x, y, env->pt2->x, env->pt2->y) * 100. / diff;
		calculate_rgb(rgb, rgb1, rgb2, p);
	}
	return (rgb[0] * (256 * 256) + rgb[1] * 256 + rgb[2]);
}
