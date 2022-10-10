#include "../includes/fdf.h"

float	get_step(float target, float angle)
{
	float	med;

	med = 3.142 + target;
	if (angle > med)
		return (6.283 - angle + target);
	return (target - angle);
}

void	ft_animate(float target_x, float target_z, t_env *env)
{
	float	step_x;
	float	step_z;
	int		i;

	i = 0;
	if (env->map->angle_x == target_x && env->map->angle_z == target_z)
		return ;
	step_x = get_step(target_x, env->map->angle_x) / 25;
	step_z = get_step(target_z, env->map->angle_z) / 25;
	while (i < 25)
	{
		env->map->angle_x += step_x;
		env->map->angle_z += step_z;
		check_if_flipped(env);
		if (env->map->is_flipped == -1)
			ft_rev_display_v2(env);
		else
			ft_display_v2(env);
		i++;
	}
}

//void	animate reset()
//{}