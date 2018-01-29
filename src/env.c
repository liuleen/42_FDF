#include "../includes/fdf.h"

void		environment(t_en *env, char **argv)
{
	int fd;

	if ((fd = open(argv[1], O_RDONLY)) < 0)
	{
		perror("Invalid file\n");
		exit(-1);
	}
	env->row_count = 0;
	env->col_count = 0;
	env->map = NULL;
	ft_getmap(env, fd);
	env->screen_width = 2500;
	env->screen_height = 1300;
	env->spacing = calc_pixel_size(*env);
	env->cart_points = get_plot(*env, env->map);
	env->degrees.x = 0;
	env->degrees.y = 0;
	env->degrees.z = 0;
	env->degrees.s = 1;
}