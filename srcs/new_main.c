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
		env->map->is_flipped++;
	if (env->map->angle_y >= 2.44 && env->map->angle_y <= 5.57)
		env->map->is_flipped++;
	if (env->map->angle_z > 1.59 && env->map->angle_z <= 4.712)
		env->map->is_flipped++;
	if (env->map->is_flipped && env->map->is_flipped % 2 != 0)
		env->map->is_flipped = 1;
	else
		env->map->is_flipped = 0;
}

void	ft_colors_hook(t_env *env, int keycode)
{
	if (keycode == K_MINUS)
	{
		if (env->theme > 0)
			env->theme--;
		else
			env->theme = 6;
	}
	if (keycode == K_PLUS)
	{
		if (env->theme < 6)
			env->theme++;
		else
			env->theme = 0;
	}
}

int	ft_rotation_hook(t_env *env, int keycode)
{
	if (keycode == K_U)
	{
		env->map->angle_z -= 0.1;
		// env->map->angle_x = env->map->angle_z - env->map->angle_x;
		// env->map->angle_y = env->map->angle_z - env->map->angle_y;
		// env->map->z_changed = 1;
		// env->map->x_changed = 0;
		// env->map->y_changed = 0;
	}
	if (keycode == K_O)
	{
		env->map->angle_z += 0.1;
		// env->map->angle_x = env->map->angle_z - env->map->angle_x;
		// env->map->angle_y = env->map->angle_z - env->map->angle_y;
		// env->map->z_changed = 1;
		// env->map->x_changed = 0;
		// env->map->y_changed = 0;
	}
	if (keycode == K_J)
	{
		env->map->angle_y += 0.1;
		// env->map->y_changed = 1;
		// env->map->z_changed = 0;
		// env->map->x_changed = 0;
	}
	if (keycode == K_L)
	{
		env->map->angle_y -= 0.1;
		// env->map->y_changed = 1;
		// env->map->z_changed = 0;
		// env->map->x_changed = 0;
	}
	if (keycode == K_K)
	{
		env->map->angle_x += 0.1;
		// env->map->x_changed = 1;
		// env->map->z_changed = 0;
		// env->map->y_changed = 0;
	}
	if (keycode == K_I)
	{
		env->map->angle_x -= 0.1;
		// env->map->x_changed = 1;
		// env->map->z_changed = 0;
		// env->map->y_changed = 0;
	}
	if(env->map->angle_x >= 6.283)
		env->map->angle_x -= 6.283;
	if (env->map->angle_x < 0)
		env->map->angle_x += 6.283;
	if(env->map->angle_y >= 6.283)
		env->map->angle_y -= 6.283;
	if (env->map->angle_y < 0)
		env->map->angle_y += 6.283;
	if(env->map->angle_z >= 6.283)
		env->map->angle_z -= 6.283;
	if (env->map->angle_z < 0)
		env->map->angle_z += 6.283;
	check_if_flipped(env);
}

// void	ft_close_hook(t_env *env, int keycode)
// {
// }

int	ft_key_hook(int keycode, void *param)
{
	t_env	*env;

	env = (t_env *)param;
	if (keycode == K_W)
		env->map->offset_y -= 15;
	if (keycode == K_A)
		env->map->offset_x -= 15;
	if (keycode == K_S)
		env->map->offset_y += 15;
	if (keycode == K_D)
		env->map->offset_x += 15;
	if (keycode == K_UP)
		env->map->zoom_factor += 0.1;
	if (keycode == K_DWN)
		env->map->zoom_factor -= 0.1;
	if (keycode == K_LFT)
		env->map->alt_factor -= 0.025;
	if (keycode == K_RGT)
		env->map->alt_factor += 0.025;
	ft_colors_hook(env, keycode);
	ft_rotation_hook(env, keycode);
	// if (env->map->is_flipped)
	// 	ft_rev_display_v2(env);
	// else
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

void	project(t_env *env, int x, int y, int rev)
{
	if (rev)
	{
		if (x > 0)
		{
			get_cur_line_rev(env, x, y);
			plot_line_v2(env);
		}
		if (y > 0)
		{
			get_cur_collumn_rev(env, x, y);
			plot_line_v2(env);
		}
	}
	else
	{
		if (x < env->map->width - 1)
		{
			get_cur_line_v3(env, x, y);
			plot_line_v2(env);
		}
		if (y < env->map->height - 1)
		{
			get_cur_collumn_v3(env, x, y);
			plot_line_v2(env);
		}
	}
}

void	ft_rev_display_v2(t_env *env)
{
	int	x;
	int	y;

	env->img = mlx_new_image(env->mlx, 1920, 1080);
	env->addr = mlx_get_data_addr(env->img, &env->bits_per_pixel, \
	&env->line_length, &env->endian);
	y = env->map->height - 1;
	while (y >= 0)
	{
		x = env->map->width - 1;
		while (x >= 0)
		{
			project(env, x, y, 1);
			x--;
		}
		y--;
	}
	printf("[rev] x : %f, y : %f, z : %f\n", env->map->angle_x, env->map->angle_y, env->map->angle_z);
	mlx_put_image_to_window(env->mlx, env->mlx_win, env->img, 0, 0);
	mlx_destroy_image(env->mlx, env->img);
	env->map->is_flipped = 0;
}
void	ft_display_v2(t_env *env)
{
	int	x;
	int	y;

	env->img = mlx_new_image(env->mlx, 1920, 1080);
	env->addr = mlx_get_data_addr(env->img, &env->bits_per_pixel, \
	&env->line_length, &env->endian);
	y = 0;
	while (y < env->map->height)
	{
		x = 0;
		while (x < env->map->width)
		{
			project(env, x, y, 0);
			x++;
		}
		y++;
	}
	printf("x : %f, y : %f, z : %f\n", env->map->angle_x, env->map->angle_y, env->map->angle_z);
	mlx_put_image_to_window(env->mlx, env->mlx_win, env->img, 0, 0);
	mlx_destroy_image(env->mlx, env->img);
	// env->map->x_changed = 0;
	// env->map->y_changed = 0;
	// env->map->z_changed = 0;
}

void	ft_init(int file, t_env *env)
{
	t_map		*imap;
	t_points	*points;
	t_point 	*pointa;
	t_point		*pointb;
	t_point		*ce;

	imap = malloc(sizeof(t_map));
	points = malloc(sizeof(t_points));
	pointa = malloc(sizeof(t_point));
	pointb = malloc(sizeof(t_point));
	ce = malloc(sizeof(t_point));
	env->map = imap;
	env->cur_points = points;
	env->point1 = pointa;
	env->point2 = pointb;
	env->center = ce;
	env->theme = 0;
	env->map->zoom_factor = 1;
    env->map->alt_factor = 0.1;
	env->map->angle_z = 0;
	env->map->angle_x = 0;
	env->map->angle_y = 0;
	env->map->width = 0;
	env->map->height = 0;
	env->map->is_flipped = 0;
	// env->map->x_changed = 0;
	// env->map->y_changed = 0;
	// env->map->z_changed = 1;
	env->mlx = mlx_init();
	env->mlx_win = mlx_new_window(env->mlx, 1920, 1080, "Fdf");
	env->map->tab = read_map_v2(env, file);
	env->map->offset_x = 0;// 960 - env->map->height / 2 * env->map->zoom_factor;
	env->map->offset_y = 0;
	get_min(env);
	get_max(env);
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
