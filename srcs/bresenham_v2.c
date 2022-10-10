#include "../includes/fdf.h"

void	plot_line_low_v2(t_env *env, t_point *pt1, t_point *pt2, int i)
{
	int	dx;
	int	dy;
	int	yi;
	int	delta;

	dx = pt2->x - pt1->x;
    dy = pt2->y - pt1->y;
	yi = 1;
	if (dy < 0)
	{
		yi = -1;
		dy = -dy;
	}
	delta = (2 * dy) - dx;
	while (pt1->bres_x < pt2->x)
	{
		put_pixel_to_img(env, pt1->bres_x, pt1->bres_y, get_gradient(env, pt1->bres_x, pt1->bres_y, i));
		if (delta > 0)
		{
			pt1->bres_y = pt1->bres_y + yi;
			delta = delta + (2 * (dy - dx));
		}
		else
			delta = delta + 2*dy;
		pt1->bres_x++;
	}
}

void    plot_line_high_v2(t_env *env, t_point *pt1, t_point *pt2, int i)
{
        int     dx;
        int     dy;
        int     xi;
        int     delta;

        dx = pt2->x - pt1->x;
        dy = pt2->y - pt1->y;
        xi = 1;
        if (dx < 0)
        {
            xi = -1;
            dx = -dx;
        }
        delta = (2 * dx) - dy;
        while (pt1->bres_y < pt2->y)
        {
            put_pixel_to_img(env, pt1->bres_x, pt1->bres_y, get_gradient(env, pt1->bres_x, pt1->bres_y, i));
            if (delta > 0)
            {
                pt1->bres_x = pt1->bres_x + xi;
                delta = delta + (2 * (dx - dy));
            }
            else
                delta = delta + 2*dx;
            pt1->bres_y++;
        }
}

void	plot_line_v2(t_env *env)
{
	if (abs(env->pt2->y - env->pt1->y) < \
	abs(env->pt2->x - env->pt1->x))
	{
		if (env->pt1->x > env->pt2->x)
			plot_line_low_v2(env, env->pt2, env->pt1, 1);
		else
			plot_line_low_v2(env, env->pt1, env->pt2, -1);
	}	
	else
	{
		if (env->pt1->y > env->pt2->y)
			plot_line_high_v2(env, env->pt2, env->pt1, 1);
		else
			plot_line_high_v2(env, env->pt1, env->pt2, -1);
	}
}