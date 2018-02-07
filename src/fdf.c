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

void		draw_straight(t_env *base)
{
	int tmpy;

	tmpy = 0;
	if (base->bresen.y2 < base->bresen.y1)
	{
		tmpy = base->bresen.y1;
		base->bresen.y1 = base->bresen.y2;
		base->bresen.y2 = tmpy;
	}
	base->bresen.y = base->bresen.y1;
	while (base->bresen.y <= base->bresen.y2)
	{
		mlx_pixel_put(base->mlx.mlx, base->mlx.win, base->bresen.x1, base->bresen.y, GRAY);
		base->bresen.y++;
	}
}

void		y_over_x(t_env *base)
{
	int 	tmpy;

	tmpy = 0;
	base->bresen.delta = fabsf(base->bresen.slope);
	base->bresen.x = base->bresen.x1;
	base->bresen.threshold = 0.5;
	if (base->bresen.y2 < base->bresen.y1)
	{
		tmpy = base->bresen.y1;
		base->bresen.y1 = base->bresen.y2;
		base->bresen.y2 = tmpy;
		base->bresen.x = base->bresen.x2;
	}
	base->bresen.y = base->bresen.y1;
	while (base->bresen.y <= base->bresen.y2)
	{
		//base->bresen.color = color();
		mlx_pixel_put(base->mlx.mlx, base->mlx.win, base->bresen.x, base->bresen.y, BLUE);
		base->bresen.offset += base->bresen.delta;
		if (base->bresen.offset >= base->bresen.threshold)
		{
			base->bresen.x += base->bresen.adjust;
			base->bresen.threshold += 1;
		}
		base->bresen.y++;
	}
}

void 		x_over_y(t_env *base)
{
	int 	tmpx;

	tmpx = 0;
	base->bresen.delta = fabsf(base->bresen.slope);
	base->bresen.y = base->bresen.y1;
	base->bresen.threshold = 0.5;
	if (base->bresen.x2 < base->bresen.x1)
	{
		tmpx = base->bresen.x1;
		base->bresen.x1 = base->bresen.x2;
		base->bresen.x2 = tmpx;
		base->bresen.y = base->bresen.y2;
	}
	base->bresen.x = base->bresen.x1;
	while (base->bresen.x <= base->bresen.x2)
	{
		//base->bresen.color = color();
		mlx_pixel_put(base->mlx.mlx, base->mlx.win, base->bresen.x, base->bresen.y, BLUE);
		base->bresen.offset += base->bresen.delta;
		if (base->bresen.offset >= base->bresen.threshold)
		{
			base->bresen.y += base->bresen.adjust;
			base->bresen.threshold += 1;
		}
		base->bresen.x++;
	}
}

void		bresenham(t_env	*base)
{
	
		base->bresen.slope = base->bresen.delta_y / base->bresen.delta_x;
		base->bresen.offset = 0;
		if(base->bresen.slope >= 0)
			base->bresen.adjust = 1;
		else
			base->bresen.adjust = -1;

		if(base->bresen.delta_x == 0)
			draw_straight(base);
		else
		{
			if (base->bresen.slope <= 1 && base->bresen.slope >= -1)
				x_over_y(base);
			else
				y_over_x(base);	
		}
}

void		set_horizontal(t_env *base, int x, int y)
{
	base->bresen.x1 = base->pxlpt[y][x].x;
	base->bresen.y1 = base->pxlpt[y][x].y;
	base->bresen.x2 = base->pxlpt[y][x + 1].x;
	base->bresen.y2 = base->pxlpt[y][x + 1].y;
	base->bresen.delta_y = base->bresen.y2 - base->bresen.y1;
	base->bresen.delta_x = base->bresen.x2 - base->bresen.x1;
	bresenham(base);
}

void		set_vertical(t_env *base, int x, int y)
{
	base->bresen.x1 = base->pxlpt[y][x].x;
	base->bresen.y1 = base->pxlpt[y][x].y;
	base->bresen.x2 = base->pxlpt[y + 1][x].x;
	base->bresen.y2 = base->pxlpt[y + 1][x].y;
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
