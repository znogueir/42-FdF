// #include "../includes/fdf.h"

// void	plot_line_low(t_env *env, int x1, int y1, int x2, int y2)
// {
// 	int	dx;
// 	int	dy;
// 	int	yi;
// 	int	y;
// 	int	x;
// 	int	D;

// 	dx = x2 - x1;
// 	dy = y2 - y1;
// 	yi = 1;
// 	if (dy < 0)
// 	{
// 		yi = -1;
// 		dy = -dy;
// 	}
// 	D = (2 * dy) - dx;
// 	y = y1;
// 	x = x1;
// 	while (x < x2)
// 	{
// 		put_pixel_to_img(env, x, y, env->cur_points->color1);
// 		if (D > 0)
// 		{
// 			y = y + yi;
// 			D = D + (2 * (dy - dx));
// 		}
// 		else
// 			D = D + 2*dy;
// 		x++;
// 	}
// }

// void    plot_line_high(t_env *env, int x1, int y1, int x2, int y2)
// {
//         int     dx;
//         int     dy;
//         int     xi;
//         int     y;
//         int     x;
//         int     D;

//         dx = x2 - x1;
//         dy = y2 - y1;
//         xi = 1;
//         if (dx < 0)
//         {
//                 xi = -1;
//                 dx = -dx;
//         }
//         D = (2 * dx) - dy;
//         y = y1;
//         x = x1;
//         while (y < y2)
//         {
//             put_pixel_to_img(env, x, y, env->cur_points->color1);
//             if (D > 0)
//             {
//                  x = x + xi;
//                 D = D + (2 * (dx - dy));
//             }
//             else
//                 D = D + 2*dx;
//             y++;
//         }
// }

// void	plot_line(t_env *env)
// {
// 	if (abs(env->cur_points->y2 - env->cur_points->y1) < \
// 	abs(env->cur_points->x2 - env->cur_points->x1))
// 	{
// 		if (env->cur_points->x1 > env->cur_points->x2)
// 			plot_line_low(env, env->cur_points->x2, env->cur_points->y2, env->cur_points->x1, env->cur_points->y1);
// 		else
// 			plot_line_low(env, env->cur_points->x1, env->cur_points->y1, env->cur_points->x2, env->cur_points->y2);
// 	}	
// 	else
// 	{
// 		if (env->cur_points->y1 > env->cur_points->y2)
// 			plot_line_high(env, env->cur_points->x2, env->cur_points->y2, env->cur_points->x1, env->cur_points->y1);
// 		else
// 			plot_line_high(env, env->cur_points->x1, env->cur_points->y1, env->cur_points->x2, env->cur_points->y2);
// 	}
// }