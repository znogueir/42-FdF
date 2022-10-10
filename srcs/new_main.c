/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_main.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znogueir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 23:15:01 by znogueir          #+#    #+#             */
/*   Updated: 2022/10/04 23:20:18 by znogueir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	check_if_flipped(t_env* env)
{
	if (env->map->angle_x >= 3.142 && env->map->angle_x <= 6.283)
		env->map->is_flipped *= -1;
	if (env->map->angle_z > 1.585 && env->map->angle_z <= 4.712)
		env->map->is_flipped *= -1;
}

int	ft_key_hook(int keycode, void *param)
{
	t_env	*env;

	env = (t_env *)param;
	ft_move_view(env, keycode);
	ft_rotate_view(env, keycode);
	ft_switch_views(env, keycode);
	ft_switch_colors(env, keycode);
	if (env->map->is_flipped == -1)
		ft_rev_display_v2(env);
	else
	ft_display_v2(env);
//	ft_close_hook(env, keycode);
	return (0);
}

int	*create_line(char **clean_line, t_env *env)
{
	int		*line;
	int		i;

	i = 0;
	line = malloc(sizeof(int) * env->map->width);
	if (!line)
		return (NULL);
	i = 0;
	while (i < env->map->width)
	{
		line[i] = ft_atoi(clean_line[i]);
		i++;
	}
	return (line);
}

int	**read_map_v2(t_env *env, int file)
{
	int		**result;
	int		i;
	char	*line;
	int		file2;
	char	**clean_line;

	line = get_next_line(file);
	if (!line)
		return (NULL);
	while (line)
	{
		free(line);
		line = get_next_line(file);
		env->map->height++;
	}
	close(file);
	file2 = open(env->file_name, O_RDONLY);
	if (!file2)
		return (0);
	result = malloc(sizeof(int *) * env->map->height);
	i = 0;
	line = get_next_line(file2);
	clean_line = ft_split(line, ' ');
	while (clean_line[i])
	{
		env->map->width++;
		i++;
	}
	i = 0;
	while (line)
	{
		result[i] = create_line(clean_line, env);
		free(line);
		line = get_next_line(file2);
		if (line)
			clean_line = ft_split(line, ' ');
		i++;
	}
	close(file2);
	return (result);
}

int	main(int ac, char **av)
{
	int		file;
	t_env	env;

	if (ac == 2)
	{
		file = open(av[1], O_RDONLY);
		if (!file)
			return (0);
		env.file_name = av[1];
		ft_init(file, &env);
		ft_display_v2(&env);
		mlx_key_hook(env.mlx_win, &ft_key_hook, &env);
		mlx_loop(env.mlx);
	}
	return (0);
}
