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
	printf("key event %d\n", keycode);
	keycode == ESCAPE ? exit(1) : 0;
	keycode == UP ? b->bresen.shift_y -= 50 : 0;
	keycode == DOWN ? b->bresen.shift_y += 50 : 0;
	keycode == LEFT ? b->bresen.shift_x -= 50 : 0;
	keycode == RIGHT ? b->bresen.shift_x += 50 : 0;
	keycode == ZOOMIN ? b->bresen.zoom += 10 : 0;
	keycode == ZOOMIN ? b->bresen.zoom -= 10 : 0;
	// keycode == TURNLEFT ? 
	// keycode == TURNRIGHT ?
	// keycode == ROTATERIGHT ? 
	// keycode == ROTATELEFT ? 
	// keycode == ROTATEUP ?
	// keycode == ROTATEDOWN ?
	// keycode == OUT ?
	// keycode == IN ?
	// keycode == RESET ?      
	return (0);
}

void			user_message(t_env *b)
{
	mlx_string_put(b->mlx.mlx, b->mlx.win, 5, 0, YELLOW, "Arrows : Move");
	mlx_string_put(b->mlx.mlx, b->mlx.win, 5, 15, YELLOW, "{+, -} : Zoom");
	mlx_string_put(b->mlx.mlx, b->mlx.win, 5, 30, YELLOW, "{1, 2} : Rotate x");
	mlx_string_put(b->mlx.mlx, b->mlx.win, 5, 45, YELLOW, "{3, 4} : Rotate y");
	mlx_string_put(b->mlx.mlx, b->mlx.win, 5, 60, YELLOW, "{5, 6} : Rotate z");
	mlx_string_put(b->mlx.mlx, b->mlx.win, 5, 75, YELLOW, "{spce/dlt}: alt");
	mlx_string_put(b->mlx.mlx, b->mlx.win, 5, 90, YELLOW, "{return} : reset");
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

int				color(t_env *b)
{
	int x;
	int y;

	y = -1;
	while (++y < b->map.height)
	{
		x = -1;
		while (++x < b->map.width)
		{
			if (b->map.z[y][x] == b->map.z[y][x + 1])
				return (RED);
			else if (b->map.z[y][x] > b->map.z[y][x + 1])
				return (BLUE);
			else if (b->map.z[y][x] < b->map.z[y][x + 1])
				return (WHITE);
			else if (b->map.z[y][x] == b->map.z[y +  1][x])
				return (CYAN);
			else if (b->map.z[y][x] > b->map.z[y + 1][x])
				return (YELLOW);
			else if (b->map.z[y][x] < b->map.z[y + 1][x])
				return (GRAY);
		}
	}
	return (1);
}

void			mlx(t_env *b)
{
	t_pxlpt		**pxlpt;

	reset(b);
	b->mlx.mlx = mlx_init();
	b->mlx.win = mlx_new_window(b->mlx.mlx, WIDTH, HEIGHT, "FDF");
	b->pxlpt = pxlpts(b);
	rotate(b);
	translate_image(b);
	fdf(b);
	mlx_hook(b->mlx.win, 2, 3, reg_key_events, b);
	mlx_loop_hook(b->mlx.mlx, &fdf, b);
	mlx_expose_hook(b->mlx.win, expose, b);
	mlx_loop(b->mlx.mlx);
}
