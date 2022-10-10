#ifndef FDF_H
# define FDF_H

#include "../libft/gnl/get_next_line.h"
#include "../libft/ft_printf/ft_printf.h"
#include "../minilibx-linux-master/mlx_int.h"
#include "../minilibx-linux-master/mlx.h"
#include <math.h>
#include <stdio.h>

# define K_UP 65362
# define K_DWN 65364
# define K_LFT 65361
# define K_RGT 65363
# define K_ESC 65307
# define K_PLUS 61
# define K_MINUS 45
# define K_A 97
# define K_B 98
# define K_C 99
# define K_D 100
# define K_E 101
# define K_F 102
# define K_G 103
# define K_H 104
# define K_I 105
# define K_J 106
# define K_K 107
# define K_L 108
# define K_M 109
# define K_N 110
# define K_O 111
# define K_P 112
# define K_Q 113
# define K_R 114
# define K_S 115
# define K_T 116
# define K_U 117
# define K_V 118
# define K_W 119
# define K_X 120
# define K_Y 121
# define K_Z 122

typedef struct	s_brm
{
}				t_brm;

typedef struct	s_point
{
	float		prev_x;
	float		prev_y;
	float		prev_z;
	int			x;
	int			y;
	int			z;
	int			bres_x; // a changer
	int			bres_y; // a changer
	int			color;
}				t_point;

typedef struct	s_map
{
	int			width;
	int			height;
	int			max;
	int			min;
	float		zoom_factor;
	float		alt_factor;
	float		angle_x;
	float		angle_y;
	float		angle_z;
	int			is_flipped;
	int			offset_x;
	int			offset_y;
	int			**tab;
	t_point		*center;
}				t_map;

typedef struct	s_env 
{
	void		*mlx;
	void		*mlx_win;
	void		*img;
	char		*addr;
	char		*file_name;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
	int			theme;
	t_point		*pt1;
	t_point		*pt2;
	t_map		*map;
}				t_env;

//	init
int		**read_map_v2(t_env *env, int file);
void	ft_init(int file, t_env *env);

//	hooks
void	ft_switch_colors(t_env *env, int keycode);
void	ft_switch_views(t_env *env, int keycode);
void	ft_rotate_view(t_env *env, int keycode);
void	ft_move_view(t_env *env, int keycode);

//	display
void	put_pixel_to_img(t_env *env, int x, int y, int color);
void	ft_rev_display_v2(t_env *env);
void	ft_display_v2(t_env *env);

//	calculate_points
void	get_cur_line_v3(t_env *env, int x, int y);
void	get_cur_collumn_v3(t_env *env, int x, int y);

//	draw_lines
void	check_if_flipped(t_env* env);
void	plot_line_v2(t_env *env);

//	animate
float	get_step(float target, float angle);
void	ft_animate(float target_x, float target_z, t_env *env);

//	calculate_colors
int			get_gradient(t_env *env, int x, int y, int i);
int			get_color(t_env *env, int alt);

//	color_themes
int			get_elevation_theme(t_env *env, int alt);
int			get_rb_theme(t_env *env, int alt);
int			get_realist_theme(t_env *env, int alt);
int			get_purple_theme(t_env *env, int alt);
int			get_frozen_theme(t_env *env, int alt);
int			get_matrix_theme(t_env *env, int alt);

#endif
