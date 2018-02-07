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
	
	if (keycode == ESCAPE)
		exit(1);
	// else if (keycode == UP)
	// 	base->bresen.degrees.x += 20;
	// else if (keycode == DOWN)
	// 	base->bresen.degrees.x -= 20;
	// else if (keycode == LEFT)
	// 	base->bresen.degrees.y -= 20;
	// else if (keycode == RIGHT)
	// 	base->bresen.degrees.y += 20;
	// else if (keycode == ZOOMIN)
	// 	base->bresen.degrees.z -= 20;
	// else if (keycode == ZOOMOUT)
	// 	base->bresen.degrees.z += 20;
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
	rotate(base);
	translate_image(base);
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