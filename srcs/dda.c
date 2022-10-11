#include "../includes/fdf.h"

void	plot_line_v2(t_env *env)
{
	float	dx;
	float	dy;
	float	x;
	float	y;
	int		i;
	float	step;

	dx = (env->pt2->x - env->pt1->x);
	dy = (env->pt2->y - env->pt1->y);
	if (fabs(dx) >= fabs(dy))
    	step = fabs(dx);
  	else
    	step = fabs(dy);
  	dx = dx / step;
  	dy = dy / step;
  	x = env->pt1->x;
  	y = env->pt1->y;
  	i = 1;
  	while (i <= step) {
    	put_pixel_to_img(env, x, y, get_gradient(env, x, y, i));
    	x = x + dx;
    	y = y + dy;
    	i = i + 1;
	}
}