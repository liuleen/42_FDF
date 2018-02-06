/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rliu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/28 19:41:24 by rliu              #+#    #+#             */
/*   Updated: 2018/01/29 16:05:47 by rliu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"
//bresenham's algorithm

// void		illuminate_pixel()
// {
// }

void	vertical_line(t_env *base)
{
	if (base->bresen.y2 < base->bresen.y1)
	{
		base->bresen.tmpy = base->bresen.y1;
		base->bresen.y1 = base->bresen.y2;
		base->bresen.y2 = base->bresen.tmpy;
	}
	base->bresen.y = base->bresen.y1;
	while (base->bresen.y <= base->bresen.y2)
	{
		mlx_pixel_put(base->mlx.mlx, base->mlx.win, base->bresen.x1, base->bresen.y, WHITE);
		base->bresen.y++;
	}
}

void		bresenham(t_env	*base)
{
	if (!base->bresen.delta_x)
		vertical_line(base);
	else
	{
		base->bresen.slope = base->bresen.delta_y / base->bresen.delta_x;
		base->bresen.adjust = (base->bresen.slope >= 0) ? 1 : -1;
		base->bresen.offset = 0;
		// if (-1 <= base->bresen.slope && base->bresen.slope <= 1)
		// 	run_over_rise(base);
		// else
		// 	rise_over_run(base);
	}
}

void		set_horizontal(t_env *base, int x, int y)
{
	base->bresen.x1 = base->pxlpt[y][x].x + 150;
	base->bresen.y1 = base->pxlpt[y][x].y + 200;
	base->bresen.x2 = base->pxlpt[y][x + 1].x + 150;
	base->bresen.y2 = base->pxlpt[y][x + 1].y + 200;
	base->bresen.delta_y = base->bresen.y2 - base->bresen.y1;
	base->bresen.delta_x = base->bresen.x2 - base->bresen.x1;
	bresenham(base);
}

void		set_vertical(t_env *base, int x, int y)
{
	base->bresen.x1 = base->pxlpt[y][x].x + 150;
	base->bresen.y1 = base->pxlpt[y][x].y + 200;
	base->bresen.x2 = base->pxlpt[y + 1][x].x + 150;
	base->bresen.y2 = base->pxlpt[y + 1][x].y + 200;
	base->bresen.delta_y = base->bresen.y2 - base->bresen.y1;
	base->bresen.delta_x = base->bresen.x2 - base->bresen.x1;
	bresenham(base);
}

void			fdf(t_env *base)
{
	int 	y;
	int 	x;

	y = -1;
	while (++y < base->map.height)
	{
		x = -1;
		while (++x < base->map.width)
		{
			if (x + 1 < base->map.width)
				set_horizontal(base, x, y);
			if (y + 1 < base->map.height)
				set_vertical(base, x, y);			
		}
	}
}
