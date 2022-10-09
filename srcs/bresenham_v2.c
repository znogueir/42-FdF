#include "../includes/fdf.h"

void	plot_line_low_v2(t_env *env, t_point *point1, t_point *point2, int i)
{
	int	dx;
	int	dy;
	int	yi;
	int	y;
	int	x;
	int	D;

	dx = point2->x - point1->x;
    dy = point2->y - point1->y;
	yi = 1;
	if (dy < 0)
	{
		yi = -1;
		dy = -dy;
	}
	D = (2 * dy) - dx;
	y = point1->y;
    x = point1->x;
	while (x < point2->x)
	{
		put_pixel_to_img(env, x, y, get_gradient(env, x, y, i));
		if (D > 0)
		{
			y = y + yi;
			D = D + (2 * (dy - dx));
		}
		else
			D = D + 2*dy;
		x++;
	}
}

void    plot_line_high_v2(t_env *env, t_point *point1, t_point *point2, int i)
{
        int     dx;
        int     dy;
        int     xi;
        int     y;
        int     x;
        int     D;

        dx = point2->x - point1->x;
        dy = point2->y - point1->y;
        xi = 1;
        if (dx < 0)
        {
                xi = -1;
                dx = -dx;
        }
        D = (2 * dx) - dy;
        y = point1->y;
        x = point1->x;
        while (y < point2->y)
        {
            put_pixel_to_img(env, x, y, get_gradient(env, x, y, i));
            if (D > 0)
            {
                x = x + xi;
                D = D + (2 * (dx - dy));
            }
            else
                D = D + 2*dx;
            y++;
        }
}

void	plot_line_v2(t_env *env)
{
	if (abs(env->point2->y - env->point1->y) < \
	abs(env->point2->x - env->point1->x))
	{
		if (env->point1->x > env->point2->x)
			plot_line_low_v2(env, env->point2, env->point1, 1);
		else
			plot_line_low_v2(env, env->point1, env->point2, -1);
	}	
	else
	{
		if (env->point1->y > env->point2->y)
			plot_line_high_v2(env, env->point2, env->point1, 1);
		else
			plot_line_high_v2(env, env->point1, env->point2, -1);
	}
}