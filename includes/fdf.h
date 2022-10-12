/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znogueir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 17:12:50 by znogueir          #+#    #+#             */
/*   Updated: 2022/10/11 17:16:54 by znogueir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "../libs/libft/gnl/get_next_line.h"
# include "../libs/libft/ft_printf/ft_printf.h"
# include "../libs/minilibx-linux/mlx_int.h"
# include "../libs/minilibx-linux/mlx.h"
# include "keys.h"
# include <math.h>
# include <stdio.h>

# define WIN_H 1080
# define WIN_W 1920

typedef struct s_point
{
	float	prev_x;
	float	prev_y;
	float	prev_z;
	int		x;
	int		y;
	int		z;
	int		color;
}			t_point;

typedef struct s_brm
{
	int		x;
	int		y;
	int		dx;
	int		dy;
	int		delta;
	int		xi;
	int		yi;
}			t_brm;

typedef struct s_map
{
	int		width;
	int		height;
	float	max;
	float	min;
	float	zoom_factor;
	float	initial_zoom;
	float	alt_factor;
	float	initial_alt;
	float	angle_x;
	float	angle_y;
	float	angle_z;
	int		is_flipped;
	float	offset_x;
	float	offset_y;
	int		**tab;
	t_point	*center;
}			t_map;

typedef struct s_env
{
	void	*mlx;
	void	*mlx_win;
	void	*img;
	char	*addr;
	char	*file_name;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	int		theme;
	float	step_x;
	float	step_y;
	float	step_zoom;
	float	step_alt;
	t_point	*pt1;
	t_point	*pt2;
	t_map	*map;
	t_brm	*brm;
}			t_env;

//	init
int		**read_map_v2(t_env *env, int file);
void	ft_init(int file, t_env *env);

//	hooks
int		ft_key_hook(int keycode, void *param);
void	ft_switch_colors(t_env *env, int keycode);
void	ft_switch_views(t_env *env, int keycode);
void	ft_rotate_view(t_env *env, int keycode);
void	ft_move_view(t_env *env, int keycode);

//	display
void	check_if_flipped(t_env *env);
void	put_pixel_to_img(t_env *env, int x, int y, int color);
void	ft_rev_display_v2(t_env *env);
void	ft_display_v2(t_env *env);
void	draw_box(t_env *env);
void	display_hud(t_env *env);

//	calculate_points
void	get_center(t_env *env);
void	get_cur_line_v3(t_env *env, int x, int y);
void	get_cur_collumn_v3(t_env *env, int x, int y);

//	draw_lines (bresenham)
void	plot_line_v2(t_env *env);

//	animate
float	get_step(float target, float angle);
void	ft_animate_view(float target_x, float target_z, t_env *env);
void	ft_animate_center(t_env *env);

//	calculate_colors
int		get_gradient(t_env *env, int x, int y, int i);
int		get_color(t_env *env, int alt);

//	color_themes
int		get_elevation_theme(t_env *env, int alt);
int		get_rb_theme(t_env *env, int alt);
int		get_realist_theme(t_env *env, int alt);
int		get_purple_theme(t_env *env, int alt);
int		get_frozen_theme(t_env *env, int alt);
int		get_matrix_theme(t_env *env, int alt);

//	free
int		ft_close(t_env *env);
void	ft_free_split(char **str);
void	ft_global_free(t_env *env);

#endif
