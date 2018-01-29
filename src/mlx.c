
#include "../includes/fdf.h"

int		my_key_funct(int keycode)  /*you need to pass mlx and win here, figure out how */
{
	printf("key event %d\n", keycode); 
	//mlx_pixel_put(mlx, win, 300, 300, 0xFF00FF);
	return (0);
}

/*you need to pass mlx and win here, figure out how */
void		mlx(t_env *base)
{
	// int		x;
	// int		y;
	/* mlx init returns a pointer which serves identifier for the conneciton to the graphic server
	 * allow other functions to use the same conncetion to the server
	 * */
	//reset_map(base);
	base->mlx.mlx = mlx_init();

	/* mlx_new_window creates a new window using the sizes in the parameters,
	 * setting title onto the title bar. 
	 * */
	base->mlx.win = mlx_new_window(base->mlx.mlx, WIDTH, HEIGHT, "FDF");
	mlx_key_hook(base->mlx.win, my_key_funct, base->mlx.mlx);
	//create_fdf(base);
	//mlx_hook(base->mlx.win, 2, 3, my_key_funct, base);
	//mlx_loop_hook(base->mlx.mlx, create_fdf, base);
	/* loops deals with events, takes the connection identifier as parameter,
	 * will be useful to give mac back the control of the graphic system
	 * mlx_loop will manage events and draw the pixels
	 * This function never returns. It is an infinite loop that waits for an event, and then calls 
	 * a user-defined function associated with this event. 
	 * */
	mlx_loop(base->mlx.mlx);
}