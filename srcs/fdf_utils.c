#include "../includes/fdf.h"

void	get_min(t_env *env)
{
	int	x;
	int	y;
	int	min;

	min = env->map->tab[0][0];
	y = 0;
	while (y < env->map->height)
	{
		x = 0;
		while (x < env->map->width)
		{
			if (env->map->tab[y][x] < min)
				min = env->map->tab[y][x];
			x++;
		}
		y++;
	}
	env->map->min = min;
}

void	get_max(t_env *env)
{
	int	x;
	int	y;
	int	max;

	max = env->map->tab[0][0];
	y = 0;
	while (y < env->map->height)
	{
		x = 0;
		while (x < env->map->width)
		{
			if (env->map->tab[y][x] > max)
				max = env->map->tab[y][x];
			x++;
		}
		y++;
	}
	env->map->max = max;
}

void	rotate_point(t_env *env, t_point *point)
{
	float	x;
	float	y;
	float	z;

	x = point->prev_x * cos(env->map->angle_z) - point->prev_y * sin(env->map->angle_z);// + env->map->offset_x;
	y = point->prev_x * sin(env->map->angle_z) + point->prev_y * cos(env->map->angle_z);// + env->map->offset_y;
	z = point->prev_z;
	point->prev_z = z * cos(env->map->angle_y) - x * sin(env->map->angle_y);
	point->prev_x = z * sin(env->map->angle_y) + x * cos(env->map->angle_y);
	point->prev_y = y;
	point->y = point->prev_y * cos(env->map->angle_x) - point->prev_z * sin(env->map->angle_x);
	point->z = point->prev_y * sin(env->map->angle_x) + point->prev_z * cos(env->map->angle_x);
	point->x = point->prev_x;
	point->x += env->map->offset_x;// - (point->x - point->prev_x) / 2;
	point->y += env->map->offset_y;// - (point->y - point->prev_y) / 2;
}

void	get_to_origin(t_env *env, t_point *point)
{
	env->center->prev_x = (env->map->width - 1) * env->map->zoom_factor / 2 + env->map->offset_x;
	env->center->prev_y = (env->map->height - 1) * env->map->zoom_factor / 2 + env->map->offset_y;
	env->center->prev_z = env->map->min + (abs(env->map->max - env->map->min) / 2.);
	point->prev_x = (point->prev_x - env->center->prev_x);
	point->prev_y = (point->prev_y - env->center->prev_y);
	point->prev_z = (point->prev_z - env->center->prev_z);
	//printf("x : %f, y : %f, z : %f;\n", point->prev_x, point->prev_y, point->prev_z);
	rotate_point(env, point);
	point->x = env->center->prev_x + (point->x - env->map->offset_x);
	point->y = env->center->prev_y + (point->y - env->map->offset_y);
	//printf("x : %f, y : %f;\n", point->x, point->y);
}

void	get_cur_line_rev(t_env *env, int x, int y)
{
	env->point1->prev_x = x * env->map->zoom_factor + env->map->offset_x;
	env->point1->prev_y = y * env->map->zoom_factor + env->map->offset_y;
	env->point1->prev_z = env->map->tab[y][x] * env->map->alt_factor;
	env->point2->prev_x = (x - 1) * env->map->zoom_factor + env->map->offset_x;
	env->point2->prev_y = y * env->map->zoom_factor + env->map->offset_y;
	env->point2->prev_z = env->map->tab[y][x - 1] * env->map->alt_factor;
	get_to_origin(env, env->point1);
	get_to_origin(env, env->point2);
	if (x == 0 && y == 0)
		env->point1->color = 0xFF0000;
	else if (x == env->map->width - 1)
		env->point1->color = 0xFF0000;
	else
		env->point1->color = get_color(env, env->map->tab[y][x]);
	env->point2->color = get_color(env, env->map->tab[y][x - 1]);
}

void	get_cur_collumn_rev(t_env *env, int x, int y)
{
	env->point1->prev_x = x * env->map->zoom_factor + env->map->offset_x;
	env->point1->prev_y = y * env->map->zoom_factor + env->map->offset_y;
	env->point1->prev_z = env->map->tab[y][x] * env->map->alt_factor;
	env->point2->prev_x = x * env->map->zoom_factor + env->map->offset_x;
	env->point2->prev_y = (y - 1) * env->map->zoom_factor + env->map->offset_y;
	env->point2->prev_z = env->map->tab[y - 1][x] * env->map->alt_factor;
	get_to_origin(env, env->point1);
	get_to_origin(env, env->point2);
	if (x == 0 && y == 0)
		env->point1->color = 0xFF0000;
	else if (x == env->map->width - 1)
		env->point1->color = 0xFF0000;
	else
		env->point1->color = get_color(env, env->map->tab[y][x]);
	env->point2->color = get_color(env, env->map->tab[y - 1][x]);
}

void	get_cur_line_v3(t_env *env, int x, int y)
{
	env->point1->prev_x = x * env->map->zoom_factor + env->map->offset_x;
	env->point1->prev_y = y * env->map->zoom_factor + env->map->offset_y;
	env->point1->prev_z = env->map->tab[y][x] * env->map->alt_factor;
	env->point2->prev_x = (x + 1) * env->map->zoom_factor + env->map->offset_x;
	env->point2->prev_y = y * env->map->zoom_factor + env->map->offset_y;
	env->point2->prev_z = env->map->tab[y][x + 1] * env->map->alt_factor;
	get_to_origin(env, env->point1);
	get_to_origin(env, env->point2);
	// if (x == 0 && y == 0)
	// 	env->point1->color = 0xFF0000;
	// else if (x == env->map->width - 1)
	// 	env->point1->color = 0xFF0000;
	// else
	env->point1->color = get_color(env, env->map->tab[y][x]);
	env->point2->color = get_color(env, env->map->tab[y][x + 1]);
}

void	get_cur_collumn_v3(t_env *env, int x, int y)
{
	env->point1->prev_x = x * env->map->zoom_factor + env->map->offset_x;
	env->point1->prev_y = y * env->map->zoom_factor + env->map->offset_y;
	env->point1->prev_z = env->map->tab[y][x] * env->map->alt_factor;
	env->point2->prev_x = x * env->map->zoom_factor + env->map->offset_x;
	env->point2->prev_y = (y + 1) * env->map->zoom_factor + env->map->offset_y;
	env->point2->prev_z = env->map->tab[y + 1][x] * env->map->alt_factor;
	get_to_origin(env, env->point1);
	get_to_origin(env, env->point2);
	// if (x == 0 && y == 0)
	// 	env->point1->color = 0xFF0000;
	// else if (x == env->map->width - 1)
	// 	env->point1->color = 0xFF0000;
	// else
	env->point1->color = get_color(env, env->map->tab[y][x]);
	env->point2->color = get_color(env, env->map->tab[y + 1][x]);
}

void	put_pixel_to_img(t_env *env, int x, int y, int color)
{
	char	*dst;

	if (x > 0 && x < 1920 && y > 0 && y < 1080)
	{
		dst = env->addr + (y * env->line_length + x * (env->bits_per_pixel / 8));
		*(unsigned int*)dst = color;
	}
}

/*
void	ft_lstadd_back_y(t_lst_points *lst, t_lst_points *new)
{
	t_lst_points	*p;

	if (lst)
	{
		p = lst;
		while (p->nexty)
			p = p->nexty;
		p->nexty = new;
	}
}*/
