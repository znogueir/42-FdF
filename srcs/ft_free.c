/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znogueir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 16:26:29 by znogueir          #+#    #+#             */
/*   Updated: 2022/10/12 16:27:15 by znogueir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int	ft_close(t_env *env)
{
	ft_global_free(env);
	free(env);
	exit(0);
}

void	ft_free_split(char **str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
}

void	ft_global_free(t_env *env)
{
	int	i;

	i = 0;
	while (i < env->map->height)
	{
		free(env->map->tab[i]);
		i++;
	}
	free(env->map->tab);
	free(env->map->center);
	free(env->map);
	free(env->pt1);
	free(env->pt2);
	free(env->brm);
	mlx_destroy_image(env->mlx, env->img);
	mlx_destroy_window(env->mlx, env->mlx_win);
	mlx_destroy_display(env->mlx);
	free(env->mlx);
}
