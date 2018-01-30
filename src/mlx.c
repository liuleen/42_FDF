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
	{
		mlx_destroy_window(base->mlx.mlx, base->mlx.win);
		exit(0);
	}
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

	t_pxlpt		**cartpts;

	cartpts = pxlpts(base);
	base->mlx.mlx = mlx_init();
	base->mlx.win = mlx_new_window(base->mlx.mlx, WIDTH, HEIGHT, "FDF");
	mlx_pixel_put(base->mlx.mlx, base->mlx.win, 350, 350, 0xff0000);
	//fdf_draw(base, cartpts);
	mlx_key_hook(base->mlx.win, reg_key_events, base->mlx.mlx);
	//create_fdf(base);
	/*	mlx_hook(base->mlx.win, 2, 3, cool_key_events, base);
	 *	mlx_loop_hook(base->mlx.mlx, create_fdf, base);
	 * */
	mlx_loop(base->mlx.mlx);
}
