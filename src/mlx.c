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
	
	keycode == ESCAPE ? exit (1) : 0;
	keycode == UP ? base->bresen.shift_y -= 50 : 0;
	keycode == DOWN ? base->bresen.shift_y += 50 : 0;
	keycode == LEFT ? base->bresen.shift_x -= 50 : 0;
	keycode == RIGHT ? base->bresen.shift_x += 50 : 0;
	keycode == ZOOMIN ? base->bresen.zoom += 10 : 0;
	keycode == ZOOMIN ? base->bresen.zoom -= 10 : 0;
	return (0);
}

void		user_message(t_env *base)
{
	mlx_string_put(base->mlx.mlx, base->mlx.win, 5, 5, YELLOW, "Arrows : Move");
	mlx_string_put(base->mlx.mlx, base->mlx.win, 5, 10, YELLOW, "{+, -} : Zoom In/Out");
	mlx_string_put(base->mlx.mlx, base->mlx.win, 5, 15, YELLOW, "{1, 2} : Rotate x");
	mlx_string_put(base->mlx.mlx, base->mlx.win, 5, 20, YELLOW, "{3, 4} : Rotate y");
	mlx_string_put(base->mlx.mlx, base->mlx.win, 5, 25, YELLOW, "{5, 6} : Rotate z");
	mlx_string_put(base->mlx.mlx, base->mlx.win, 5, 30, YELLOW, "{space, delete} : Altitude");
	mlx_string_put(base->mlx.mlx, base->mlx.win, 5, 35, YELLOW, "{space, delete} : Altitude");
	mlx_string_put(base->mlx.mlx, base->mlx.win, 5, 40, YELLOW, "{return} : reset");
}
void		translate_image(t_env *base)
{
	int x;
	int y;

	y = -1;
	while (++y < base->map.height)
	{
		x = -1;
		while (++x < base->map.width)
		{
			base->pxlpt[y][x].y += HEIGHT / 2;
			base->pxlpt[y][x].x += WIDTH / 2;
		}
	}
}

// int			color_image(t_env *base)
// {
	
// }

void		mlx(t_env *base)
{

	t_pxlpt		**pxlpt;

	reset(base);
	base->mlx.mlx = mlx_init();
	base->mlx.win = mlx_new_window(base->mlx.mlx, WIDTH, HEIGHT, "FDF");
	base->pxlpt = pxlpts(base);
	rotate(base);
	translate_image(base);
	fdf(base);
	//user_message(base);
	//mlx_key_hook(base->mlx.win, reg_key_events, base->mlx.mlx);
	mlx_hook(base->mlx.win, 2, 3, reg_key_events, base);
	 /*	mlx_loop_hook(base->mlx.mlx, create_fdf, base);
	 * */
	mlx_expose_hook(base->mlx.win, expose, base);
	mlx_loop(base->mlx.mlx);
}