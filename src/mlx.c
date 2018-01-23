
#include "../includes/fdf.h"

/*you need to pass mlx and win here, figure out how */
int 		key_function(int keycode, t_env *base)
{

}

void		mlx(t_env *base)
{
	/* mlx init returns a pointer which serves identifier for the conneciton to the graphic server
	 * allow other functions to use the same conncetion to the server
	 * */
	base->mlx.mlx = mlx_init();

	/* mlx_new_window creates a new window using the sizes in the parameters,
	 * setting title onto the title bar. 
	 * */
	base->mlx.win = mlx_new_window(base->mlx.mlx, WIDTH, HEIGHT, "TITLE");

	mlx_key_hook(base->mlx.win, key_function, fdf);
	mlx_loop_hook(fdf->mlx.init, fdf_draw, base);

	/* loops deals with events, takes the connection identifier as parameter,
	 * will be useful to give mac back the control of the graphic system
	 * mlx_loop will manage events and draw the pixels
	 * */
	mlx_loop(fdf->mlx.init);
}