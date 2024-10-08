/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gradient_theme.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znogueir <znogueir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 20:45:45 by znogueir          #+#    #+#             */
/*   Updated: 2024/10/08 21:20:20 by znogueir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

// get the amount of blue in the pix col based on its height
// we have mapped the range :
// [ height of lowest point - height of highest point ]
// to the RGB spectrum and the altitude of each point will
// be scaled on this.
int	get_blue(int h)
{
	h += 100;
	if (h <= 255)
		return (h);
	if (h <= 510)
		return (255);
	if (h <= 765)
		return (765 - h);
	return (0);
}

// same for green
int	get_green(int h)
{
	h += 100;
	if (255 < h && h <= 510)
		return (h - 255);
	if (510 < h && h <= 1020)
		return (255);
	if (1020 < h && h <= 1275)
		return (1275 - h);
	return (0);
}

// same for red
int	get_red(int h)
{
	h += 100;
	if (765 < h && h <= 1020)
		return (h - 765);
	if (1020 < h && h <= 1275)
		return (255);
	if (1275 < h && h <= 1430)
		return (1530 - h);
	return (0);
}

// calculate the color of each point in the input file, based on its
// altitude in the range [ lowest point - highest point ]
int	get_perfect_gradient(t_env *env, int alt)
{
	int	color;
	int	index;
	int	delta_alt;

	delta_alt = env->map->max - env->map->min;
	if (delta_alt == 0)
		return (155);
	index = 1330 * (alt - env->map->min) / delta_alt;
	color = get_blue(index);
	color += get_green(index) << 8;
	color += get_red(index) << 16;
	return (color);
}
