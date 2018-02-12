/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rliu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/28 19:41:42 by rliu              #+#    #+#             */
/*   Updated: 2018/02/09 05:17:58 by rliu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int				reg_key_events(int keycode, t_env *b)
{
	keycode == ESCAPE ? exit(1) : 0;
	keycode == UP ? b->bresen.shift_y -= 10 : 0;
	keycode == DOWN ? b->bresen.shift_y += 10 : 0;
	keycode == LEFT ? b->bresen.shift_x -= 10 : 0;
	keycode == RIGHT ? b->bresen.shift_x += 10 : 0;
	keycode == ZOOMIN ? b->bresen.zoom += 0.015 : 0;
	keycode == ZOOMOUT ? b->bresen.zoom -= 0.015 : 0;
	keycode == TURNLEFT ? b->bresen.angle_z -= M_PI / 30 : 0;
	keycode == TURNRIGHT ? b->bresen.angle_z += M_PI / 30 : 0;
	keycode == ROTATERIGHT ? b->bresen.angle_y += M_PI / 30 : 0;
	keycode == ROTATELEFT ? b->bresen.angle_y -= M_PI / 30 : 0;
	keycode == ROTATEUP ? b->bresen.angle_x -= M_PI / 30 : 0;
	keycode == ROTATEDOWN ? b->bresen.angle_x += M_PI / 30 : 0;
	keycode == OUT ? b->bresen.z += .50 : 0;
	keycode == IN ? b->bresen.z -= .50 : 0;
	keycode == RESET ? reset(b) : 0;
	mlx_clear_window(b->mlx.mlx, b->mlx.win);
	mlx(b);
	return (0);
}

void			translate_image(t_env *b)
{
	int x;
	int y;

	y = -1;
	while (++y < b->map.height)
	{
		x = -1;
		while (++x < b->map.width)
		{
			b->pxlpt[y][x].y += HEIGHT / 2;
			b->pxlpt[y][x].x += WIDTH / 2;
		}
	}
}

void			color(t_env *b, int x, int y)
{
	if (b->map.z[y][x] == b->map.z[y][x + 1])
		b->bresen.color = CYAN;
	else if (b->map.z[y][x] > b->map.z[y][x + 1])
		b->bresen.color = RED;
	else if (b->map.z[y][x] < b->map.z[y][x + 1])
		b->bresen.color = MAROON;
}

void			mlx(t_env *b)
{
	t_pxlpt		**pxlpt;

	b->map.pixel_gap = b->map.width > b->map.height ? \
		((WIDTH / 2) / b->map.width) : ((HEIGHT / 2) / b->map.height);
	b->pxlpt = pxlpts(b);
	rotate(b);
	translate_image(b);
	fdf(b);
	mlx_hook(b->mlx.win, 2, 3, reg_key_events, b);
	mlx_hook(b->mlx.win, 12, 2, expose, b);
	mlx_expose_hook(b->mlx.win, expose, b);
	mlx_loop(b->mlx.mlx);
}

void			window(t_env *b)
{
	b->mlx.mlx = mlx_init();
	b->mlx.win = mlx_new_window(b->mlx.mlx, WIDTH, HEIGHT, "FDF");
}
