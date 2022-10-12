/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_hud.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znogueir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 23:04:54 by znogueir          #+#    #+#             */
/*   Updated: 2022/10/12 23:04:55 by znogueir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	draw_box(t_env *env)
{
	int	x;
	int	y;

	x = WIN_W - 265;
	while (x <= WIN_W)
	{
		y = 0;
		while (y <= 210)
		{
			if (x == WIN_W - 265 || y == 210)
				put_pixel_to_img(env, x, y, 0xFFFFFF);
			else
				put_pixel_to_img(env, x, y, 0x1E1E1E);
			y++;
		}
		x++;
	}
}

void	display_hud(t_env *env)
{
	mlx_string_put(env->mlx, env->mlx_win, WIN_W - 160, 20, 0xFFFFFF, \
	"Controls : ");
	mlx_string_put(env->mlx, env->mlx_win, WIN_W - 245, 50, 0xFFFFFF, \
	"Move :               W A S D");
	mlx_string_put(env->mlx, env->mlx_win, WIN_W - 245, 70, 0xFFFFFF, \
	"Rotate :             Y G H J");
	mlx_string_put(env->mlx, env->mlx_win, WIN_W - 245, 90, 0xFFFFFF, \
	"Zoom +/- :           Arrow up / down");
	mlx_string_put(env->mlx, env->mlx_win, WIN_W - 245, 110, 0xFFFFFF, \
	"Alt factor +/- :     Arrow left / right");
	mlx_string_put(env->mlx, env->mlx_win, WIN_W - 245, 130, 0xFFFFFF, \
	"Change theme :       + / -");
	mlx_string_put(env->mlx, env->mlx_win, WIN_W - 245, 150, 0xFFFFFF, \
	"Set z/x to 0 :       Z / X");
	mlx_string_put(env->mlx, env->mlx_win, WIN_W - 245, 170, 0xFFFFFF, \
	"Reset to isometric : I");
	mlx_string_put(env->mlx, env->mlx_win, WIN_W - 245, 190, 0xFFFFFF, \
	"Reset to parallel :  P");
}
