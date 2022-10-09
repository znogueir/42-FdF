#include "../includes/fdf.h"

int	get_purple_theme(t_env *env, int alt)
{
	int	tenth;

	tenth = (env->map->max - env->map->min) / 10;
	if (alt > env->map->max - tenth)
		return (0xFFC500); // jaune
	else if (alt > env->map->max - 2 * tenth)
		return (0xFF8F00); // orange
	else if (alt > env->map->max - 3 * tenth)
		return (0xFF4D00); // rouge-orange
	else if (alt > env->map->max - 4 * tenth)
		return (0xFF0000); // rouge
	else if (alt > env->map->max - 5 * tenth)
		return (0xFF008F); // magenta
	else if (alt > env->map->max - 6 * tenth)
		return (0xFF00F0); // rose
	else if (alt > env->map->max - 7 * tenth)
		return (0xCD00FF); // fuschia
	else if (alt > env->map->max - 8 * tenth)
		return (0x9300FF); // violet
	else if (alt > env->map->max - 9 * tenth)
		return (0x5D00FF); // violet fonce
	else if (alt >= env->map->min)
		return (0x2A00FF); // bleu fonce
}

int	get_frozen_theme(t_env *env, int alt)
{
	int	tenth;

	tenth = (env->map->max - env->map->min) / 10;
	if (alt > env->map->max - tenth)
		return (0xFFFFFF); // blanc
	else if (alt > env->map->max - 2 * tenth)
		return (0x00FFC9); // turquoise
	else if (alt > env->map->max - 3 * tenth)
		return (0x00FFF7); // bleu ciel
	else if (alt > env->map->max - 4 * tenth)
		return (0x00BDFF); // bleu clair
	else if (alt > env->map->max - 5 * tenth)
		return (0x0074FF); // bleu
	else if (alt > env->map->max - 6 * tenth)
		return (0x0800FF); // bleu fonce
	else if (alt > env->map->max - 7 * tenth)
		return (0x6800FF); // violet fonce
	else if (alt > env->map->max - 8 * tenth)
		return (0xBD00FF); // violet
	else if (alt > env->map->max - 9 * tenth)
		return (0xF700FF); // fuschia
	else if (alt >= env->map->min)
		return (0xFF00BD); // rose
}

int	get_matrix_theme(t_env *env, int alt)
{
	int	tenth;

	tenth = (env->map->max - env->map->min) / 10;
	if (alt > env->map->max - tenth)
		return (0xFFFFFF); // blanc
	else if (alt > env->map->max - 2 * tenth)
		return (0xFFFD98); // jaune clair
	else if (alt > env->map->max - 3 * tenth)
		return (0xFFFA00); // jaune
	else if (alt > env->map->max - 4 * tenth)
		return (0xBDFF00); // vert citron
	else if (alt > env->map->max - 5 * tenth)
		return (0x25CC00); // vert vibrant
	else if (alt > env->map->max - 6 * tenth)
		return (0x1B9500); // vert 
	else if (alt > env->map->max - 7 * tenth)
		return (0x157300); // vert fonce
	else if (alt > env->map->max - 8 * tenth)
		return (0x0F5300); // vert profond
	else if (alt > env->map->min - 9 * tenth)
		return (0x093300); // vert abyssal
	else if (alt >= env->map->min)
		return (0x082A00); // vert noir
}