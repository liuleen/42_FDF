/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rliu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/28 19:41:24 by rliu              #+#    #+#             */
/*   Updated: 2018/02/09 05:26:37 by rliu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void		straight(t_env *b)
{
	float tmpy;

	tmpy = 0;
	if (b->bresen.y2 < b->bresen.y1)
	{
		tmpy = b->bresen.y1;
		b->bresen.y1 = b->bresen.y2;
		b->bresen.y2 = tmpy;
	}
	b->bresen.y = b->bresen.y1;
	while (b->bresen.y <= b->bresen.y2)
	{
		mlx_pixel_put(b->mlx.mlx, b->mlx.win, b->bresen.x1 +
			b->bresen.shift_x, b->bresen.y + b->bresen.shift_y,
			b->bresen.color);
		b->bresen.y++;
	}
}

void		y_over_x(t_env *b)
{
	b->bresen.delta = fabsf(b->bresen.delta_x / b->bresen.delta_y);
	b->bresen.x = b->bresen.x1;
	if (b->bresen.y2 < b->bresen.y1)
	{
		b->tmpy = b->bresen.y1;
		b->bresen.y1 = b->bresen.y2;
		b->bresen.y2 = b->tmpy;
		b->bresen.x = b->bresen.x2;
	}
	b->bresen.y = b->bresen.y1;
	while (b->bresen.y <= b->bresen.y2)
	{
		mlx_pixel_put(b->mlx.mlx, b->mlx.win, b->bresen.x +
			b->bresen.shift_x, b->bresen.y + b->bresen.shift_y,
			b->bresen.color);
		b->bresen.offset += b->bresen.delta;
		if (b->bresen.offset >= b->bresen.threshold)
		{
			b->bresen.x += b->bresen.adjust;
			b->bresen.threshold += 1;
		}
		b->bresen.y++;
	}
}

void		x_over_y(t_env *b)
{
	b->bresen.delta = fabsf(b->bresen.slope);
	b->bresen.y = b->bresen.y1;
	if (b->bresen.x2 < b->bresen.x1)
	{
		b->tmpx = b->bresen.x1;
		b->bresen.x1 = b->bresen.x2;
		b->bresen.x2 = b->tmpx;
		b->bresen.y = b->bresen.y2;
	}
	b->bresen.x = b->bresen.x1;
	while (b->bresen.x <= b->bresen.x2)
	{
		mlx_pixel_put(b->mlx.mlx, b->mlx.win, b->bresen.x + b->bresen.shift_x,
			b->bresen.y + b->bresen.shift_y, b->bresen.color);
		b->bresen.offset += b->bresen.delta;
		if (b->bresen.offset >= b->bresen.threshold)
		{
			b->bresen.y += b->bresen.adjust;
			b->bresen.threshold += 1;
		}
		b->bresen.x++;
	}
}

void		bresenham(t_env *b)
{
	b->bresen.slope = b->bresen.delta_y / b->bresen.delta_x;
	b->bresen.offset = 0;
	b->bresen.adjust = b->bresen.slope >= 0 ? 1 : -1;
	b->bresen.threshold = 0.5;
	if (b->bresen.delta_x == 0)
		straight(b);
	else
	{
		if (b->bresen.slope <= 1 && b->bresen.slope >= -1)
			x_over_y(b);
		else
			y_over_x(b);
	}
}

void		fdf(t_env *b)
{
	int	y;
	int	x;

	y = -1;
	while (++y < b->map.height)
	{
		x = -1;
		while (++x < b->map.width)
		{
			if (x + 1 < b->map.width)
			{
				color(b, x, y);
				set_horizontal(b, x, y);
			}
			if (y + 1 < b->map.height)
			{
				color(b, x, y);
				set_vertical(b, x, y);
			}
		}
	}
	user_message(b);
}
