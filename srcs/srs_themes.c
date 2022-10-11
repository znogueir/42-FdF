/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   srs_themes.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znogueir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 02:15:20 by znogueir          #+#    #+#             */
/*   Updated: 2022/10/11 02:15:22 by znogueir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int	get_elevation_theme(t_env *env, int alt)
{
	int	tenth;

	tenth = (env->map->max - env->map->min) / 10;
	if (alt > env->map->max - tenth)
		return (0xFFFFFF);
	else if (alt > env->map->max - 2 * tenth)
		return (0xFF1700);
	else if (alt > env->map->max - 3 * tenth)
		return (0xFF9E00);
	else if (alt > env->map->max - 4 * tenth)
		return (0xECFF00);
	else if (alt > env->map->max - 5 * tenth)
		return (0x00FF0C);
	else if (alt > env->map->max - 6 * tenth)
		return (0x00FFC5);
	else if (alt > env->map->max - 7 * tenth)
		return (0x00D1FF);
	else if (alt > env->map->max - 8 * tenth)
		return (0x0093FF);
	else if (alt > env->map->max - 9 * tenth)
		return (0x000FFF);
	else
		return (0x7400FF);
}

int	get_rb_theme(t_env *env, int alt)
{
	int	tenth;

	tenth = (env->map->max - env->map->min) / 10;
	if (alt > env->map->max - tenth)
		return (0xFF0000);
	else if (alt > env->map->max - 2 * tenth)
		return (0xFF4D00);
	else if (alt > env->map->max - 3 * tenth)
		return (0xFF8F00);
	else if (alt > env->map->max - 4 * tenth)
		return (0xFFD500);
	else if (alt > env->map->max - 5 * tenth)
		return (0xC1FF00);
	else if (alt > env->map->max - 6 * tenth)
		return (0x00FFC5);
	else if (alt > env->map->max - 7 * tenth)
		return (0x00D1FF);
	else if (alt > env->map->max - 8 * tenth)
		return (0x0093FF);
	else if (alt > env->map->max - 9 * tenth)
		return (0x000FFF);
	else
		return (0x7400FF);
}

int	get_realist_theme(t_env *env, int alt)
{
	int	tenth;

	tenth = (env->map->max - env->map->min) / 10;
	if (alt > env->map->max - tenth)
		return (0xFFFFFF);
	else if (alt > env->map->max - 2 * tenth)
		return (0xCBBBA3);
	else if (alt > env->map->max - 3 * tenth)
		return (0xEA9007);
	else if (alt > env->map->max - 4 * tenth)
		return (0x2CA124);
	else if (alt > env->map->max - 5 * tenth)
		return (0xFFDC65); //beige
	else if (alt > env->map->max - 6 * tenth)
		return (0x0CB4CB);
	else if (alt > env->map->max - 7 * tenth)
		return (0x057BD1);
	else if (alt > env->map->max - 8 * tenth)
		return (0x1B37B6);
	else if (alt > env->map->max - 9 * tenth)
		return (0x1A2383);
	else
		return (0x0B1254);
}
