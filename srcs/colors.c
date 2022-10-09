#include "../includes/fdf.h"

int	get_color(t_env *env, int alt)
{
	if (env->theme == 0)
		return (0xFFFFFF);
	else if (env->theme == 1)
		return (get_elevation_theme(env, alt));
	else if (env->theme == 2)
		return (get_rb_theme(env, alt));
	else if (env->theme == 3)
		return (get_realist_theme(env, alt));
	else if (env->theme == 4)
		return (get_purple_theme(env, alt));
	else if (env->theme == 5)
		return (get_frozen_theme(env, alt));
	else if (env->theme == 6)
		return (get_matrix_theme(env, alt));
}

void	decimal_to_rgb(int c, int *rgb)
{
	int	g;
	int	r;

	rgb[2] = c % 256;
	g = (c % 65536 - rgb[2]);
	r = c - g - rgb[3];
	rgb[1] = g / 256;
	rgb[0] = r / 65536;
}

int get_distance(int x1, int y1, int x2, int y2)
{
	if (abs(x2 - x1) >= abs(y2 - y1))
		return (abs(x2 - x1));
	else
		return (abs(y2 - y1));
}

int	get_gradient(t_env *env, int x, int y, int i)
{
	float		diff;
	int		rgb1[3];
	int		rgb2[3];
	int		rgb[3];
	float	percentage;

	if (env->point1->color == env->point2->color)
		return (env->point1->color);
	decimal_to_rgb(env->point1->color, rgb1);
	decimal_to_rgb(env->point2->color, rgb2);
	diff = get_distance(env->point1->x, env->point1->y, env->point2->x, env->point2->y);
	if (i < 0)
	{
		percentage = get_distance(x, y, env->point1->x, env->point1->y) * 100. / diff;
		rgb[0] = rgb1[0] + (rgb2[0] - rgb1[0]) * (percentage / 100.);
		rgb[1] = rgb1[1] + (rgb2[1] - rgb1[1]) * (percentage / 100.);
		rgb[2] = rgb1[2] + (rgb2[2] - rgb1[2]) * (percentage / 100.);
	}
	else
	{
		percentage = get_distance(x, y, env->point2->x, env->point2->y) * 100. / diff;
		rgb[0] = rgb2[0] + (rgb1[0] - rgb2[0]) * (percentage / 100.);
		rgb[1] = rgb2[1] + (rgb1[1] - rgb2[1]) * (percentage / 100.);
		rgb[2] = rgb2[2] + (rgb1[2] - rgb2[2]) * (percentage / 100.);
	}
 	return (rgb[0] * (256*256) + rgb[1] * 256 + rgb[2]);
}