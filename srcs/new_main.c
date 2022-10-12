/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_main.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znogueir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 23:15:01 by znogueir          #+#    #+#             */
/*   Updated: 2022/10/11 02:20:48 by znogueir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

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

int	**read_map_p2(t_env *env, int **result, int file2, char *line)
{
	char	**clean_line;
	int		i;

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
		ft_free_split(clean_line);
		line = get_next_line(file2);
		if (line)
			clean_line = ft_split(line, ' ');
		i++;
	}
	close(file2);
	return (result);
}

int	**read_map_v2(t_env *env, int file)
{
	int		**result;
	char	*line;
	int		file2;

	line = get_next_line(file);
	if (!line)
		return (NULL);
	while (line)
	{
		free(line);
		line = get_next_line(file);
		env->map->height++;
	}
	free(line);
	close(file);
	file2 = open(env->file_name, O_RDONLY);
	if (!file2)
		return (0);
	result = malloc(sizeof(int *) * env->map->height);
	return (read_map_p2(env, result, file2, line));
}

int	main(int ac, char **av)
{
	int		file;
	t_env	*env;

	if (ac == 2)
	{
		file = open(av[1], O_RDONLY);
		if (!file)
			return (0);
		env = malloc(sizeof(t_env));
		env->file_name = av[1];
		ft_init(file, env);
		ft_display_v2(env);
		mlx_hook(env->mlx_win, 2, 1, ft_key_hook, env);
		mlx_hook(env->mlx_win, 17, 0, ft_close, env);
		mlx_loop(env->mlx);
	}
	return (0);
}
