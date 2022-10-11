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
		return (0xFFFFFF); // blanc
	else if (alt > env->map->max - 2 * tenth)
		return (0xFF1700); // rouge
	else if (alt > env->map->max - 3 * tenth)
		return (0xFF9E00); // orange
	else if (alt > env->map->max - 4 * tenth)
		return (0xECFF00); // jaune
	else if (alt > env->map->max - 5 * tenth)
		return (0x00FF0C); // vert
	else if (alt > env->map->max - 6 * tenth)
		return (0x00FFC5); // turquoise
	else if (alt > env->map->max - 7 * tenth)
		return (0x00D1FF); // bleu clair
	else if (alt > env->map->max - 8 * tenth)
		return (0x0093FF); // bleu
	else if (alt > env->map->max - 9 * tenth)
		return (0x000FFF); // bleu fonce
	else if (alt >= env->map->min)
		return (0x7400FF); // violet
}

int	get_rb_theme(t_env *env, int alt)
{
	int	tenth;

	tenth = (env->map->max - env->map->min) / 10;
	if (alt > env->map->max - tenth)
		return (0xFF0000); // rouge
	else if (alt > env->map->max - 2 * tenth)
		return (0xFF4D00); // rouge orange
	else if (alt > env->map->max - 3 * tenth)
		return (0xFF8F00); // orange
	else if (alt > env->map->max - 4 * tenth)
		return (0xFFD500); // jaune
	else if (alt > env->map->max - 5 * tenth)
		return (0xC1FF00); // lime
	else if (alt > env->map->max - 6 * tenth)
		return (0x00FFC5); // turquoise
	else if (alt > env->map->max - 7 * tenth)
		return (0x00D1FF); // bleu clair
	else if (alt > env->map->max - 8 * tenth)
		return (0x0093FF); // bleu
	else if (alt > env->map->max - 9 * tenth)
		return (0x000FFF); // bleu fonce
	else if (alt >= env->map->min)
		return (0x7400FF); // violet
}

int	get_realist_theme(t_env *env, int alt)
{
	int	tenth;

	tenth = (env->map->max - env->map->min) / 10;
	if (alt > env->map->max - tenth)
		return (0xFFFFFF); // blanc
	else if (alt > env->map->max - 2 * tenth)
		return (0xCBBBA3); // gris
	else if (alt > env->map->max - 3 * tenth)
		return (0xEA9007); // marron/orange
	else if (alt > env->map->max - 4 * tenth)
		return (0x40DD00); // vert
	else if (alt > env->map->max - 5 * tenth)
		return (0xFFDC65); // beige
	else if (alt > env->map->max - 6 * tenth)
		return (0x00FFC5); // turquoise
	else if (alt > env->map->max - 7 * tenth)
		return (0x00D1FF); // bleu clair
	else if (alt > env->map->max - 8 * tenth)
		return (0x0093FF); // bleu
	else if (alt > env->map->max - 9 * tenth)
		return (0x000FFF); // bleu fonce
	else if (alt >= env->map->min)
		return (0x7400FF); // violet
}
