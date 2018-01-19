
#include "../includes/fdf.h"

void		mlx(t_env *base)
{
	base->mlx.mlx = mlx_init();
	base->mlx.win = mlx_new_window(base->mlx.mlx, HEIGHT, WIDTH, TITLE);

}