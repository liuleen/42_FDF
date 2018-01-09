/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rliu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/30 00:39:37 by rliu              #+#    #+#             */
/*   Updated: 2017/12/01 04:48:55 by rliu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <stdio.h>
#include <unistd.h>

int		my_key_funct(int keycode)  /*you need to pass mlx and win here, figure out how */
{
	printf("key event %d\n", keycode); 
	//mlx_pixel_put(mlx, win, 300, 300, 0xFF00FF);
	return (0);
}

int		main()
{
	void	*mlx;
	void	*win;
	int		x;
	int		y;

	/* mlx init returns a pointer which serves identifier for the conneciton to the graphic server
	 * allow other functions to use the same conncetion to the server
	 * */
	mlx = mlx_init();

	/* mlx_new_window creates a new window using the sizes in the parameters,
	 * setting title onto the title bar. 
	 * */
	win = mlx_new_window(mlx, 400, 400, "mlx 42");
	sleep(1);
	y = 50;
	while (y < 150)
	{
		x = 50;
		while (x < 150)
		{

			/* pixel_put draws a pixel in the window with the x and y coords from
	 		* parameter, 00 --> most significant bit
			* mlx_pixel_put doesnt draw in the window
	 		* */
			mlx_pixel_put(mlx, win, x, y, 0x00FFFFFF);
			usleep(1);
			x++;
		}
		y++;
	}
	

	/* loops deals with events, takes the connection identifier as parameter,
	 * will be useful to give mac back the control of the graphic system
	 * mlx_loop will manage events and draw the pixels
	 * */
	sleep(5);
	mlx_key_hook(win, my_key_funct, mlx);
	mlx_loop(mlx);
	return(0);
}
