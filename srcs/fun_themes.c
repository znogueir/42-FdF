/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fun_themes.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znogueir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 02:14:09 by znogueir          #+#    #+#             */
/*   Updated: 2022/10/11 02:14:11 by znogueir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int	get_purple_theme(t_env *env, int alt)
{
	int	tenth;

	tenth = (env->map->max - env->map->min) / 10;
	if (alt > env->map->max - tenth)
		return (0xFFC500);
	else if (alt > env->map->max - 2 * tenth)
		return (0xFF8F00);
	else if (alt > env->map->max - 3 * tenth)
		return (0xFF4D00);
	else if (alt > env->map->max - 4 * tenth)
		return (0xFF0000);
	else if (alt > env->map->max - 5 * tenth)
		return (0xFF008F);
	else if (alt > env->map->max - 6 * tenth)
		return (0xFF00F0);
	else if (alt > env->map->max - 7 * tenth)
		return (0xCD00FF);
	else if (alt > env->map->max - 8 * tenth)
		return (0x9300FF);
	else if (alt > env->map->max - 9 * tenth)
		return (0x5D00FF);
	else
		return (0x2A00FF);
}

int	get_frozen_theme(t_env *env, int alt)
{
	int	tenth;

	tenth = (env->map->max - env->map->min) / 10;
	if (alt > env->map->max - tenth)
		return (0xFFFFFF);
	else if (alt > env->map->max - 2 * tenth)
		return (0x00FFC9);
	else if (alt > env->map->max - 3 * tenth)
		return (0x00FFF7);
	else if (alt > env->map->max - 4 * tenth)
		return (0x00BDFF);
	else if (alt > env->map->max - 5 * tenth)
		return (0x0074FF);
	else if (alt > env->map->max - 6 * tenth)
		return (0x0800FF);
	else if (alt > env->map->max - 7 * tenth)
		return (0x6800FF);
	else if (alt > env->map->max - 8 * tenth)
		return (0xBD00FF);
	else if (alt > env->map->max - 9 * tenth)
		return (0xF700FF);
	else
		return (0xFF00BD);
}

int	get_matrix_theme(t_env *env, int alt)
{
	int	tenth;

	tenth = (env->map->max - env->map->min) / 10;
	if (alt > env->map->max - tenth)
		return (0xFFFFFF);
	else if (alt > env->map->max - 2 * tenth)
		return (0xFFFD98);
	else if (alt > env->map->max - 3 * tenth)
		return (0xFFFA00);
	else if (alt > env->map->max - 4 * tenth)
		return (0xBDFF00);
	else if (alt > env->map->max - 5 * tenth)
		return (0x25CC00);
	else if (alt > env->map->max - 6 * tenth)
		return (0x1B9500);
	else if (alt > env->map->max - 7 * tenth)
		return (0x157300);
	else if (alt > env->map->max - 8 * tenth)
		return (0x0F5300);
	else if (alt > env->map->min - 9 * tenth)
		return (0x093300);
	else
		return (0x082A00);
}
