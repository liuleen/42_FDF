/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rliu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/28 19:41:42 by rliu              #+#    #+#             */
/*   Updated: 2018/01/29 16:04:01 by rliu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int		reg_key_events(int keycode, t_env *base)  
{
	printf("key event %d\n", keycode); 
	/*mlx_pixel_put(mlx, win, 300, 300, 0xFF00FF);*/
	if (keycode == ESCAPE)
		exit(1);
	// else if (keycode == UP)
	// {

	// }
	// else if (keycode == DOWN)
	// else if (keycode == LEFT)
	// else if (keycode == RIGHT)
	// else if (keycode == ZOOMIN)
	// else if (keycode == ZOOMOUT)
	return (0);
}

// int 	cool_key_events(int keycode, t_env *env)
// {
// 	//color, isometric, 
// }

void		mlx(t_env *base)
{
	/* int		x;
	 * int		y;
	 *	environment(base);	
	 */

	t_pxlpt		**pxlpt;

	base->mlx.mlx = mlx_init();
	base->mlx.win = mlx_new_window(base->mlx.mlx, WIDTH, HEIGHT, "FDF");
	base->pxlpt = pxlpts(base);
	//loop and plot all the points 
	//transform theta --> radians (radians = degrees × π / 180°) --> key event
				//M_PI == pi

	fdf(base);
	mlx_key_hook(base->mlx.win, reg_key_events, base->mlx.mlx);
	//create_fdf(base);
	/*	mlx_key_hook(base->mlx.win, 2, 3, cool_key_events, base);
	 *	mlx_loop_hook(base->mlx.mlx, create_fdf, base);
	 * */
	mlx_loop(base->mlx.mlx);
}
