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

void		bresenham(t_env	*base)
{
	double y;
	double x;
	double vector;

	y = base->bresen.y1;
	x = base->bresen.x1;
	vector = sqrt((pow(base->bresen.delta_x, 2)) + (pow(base->bresen.delta_y, 2)));
	base->bresen.delta_x /= vector;
	base->bresen.delta_y /= vector;
	while (vector > 0)
	{
		mlx_pixel_put(base->mlx.mlx, base->mlx.win, x, y, vector);
		x += base->bresen.delta_x;
		y += base->bresen.delta_x;
		vector -= 1;
	}
}

void		set_horizontal(t_env *base, int x, int y)
{
	base->bresen.x1 = base->pxlpt[y][x].x + base->bresen.center_x;
	base->bresen.y1 = base->pxlpt[y][x].y + base->bresen.center_y;
	base->bresen.x2 = base->pxlpt[y][x + 1].x + base->bresen.center_x;
	base->bresen.y2 = base->pxlpt[y][x + 1].y + base->bresen.center_y;
	base->bresen.delta_y = base->bresen.y2 - base->bresen.y1;
	base->bresen.delta_x = base->bresen.x2 - base->bresen.x1;
	bresenham(base);
}

void		set_vertical(t_env *base, int x, int y)
{
	base->bresen.x1 = base->pxlpt[y][x].x + base->bresen.center_x;
	base->bresen.y1 = base->pxlpt[y][x].y + base->bresen.center_y;
	base->bresen.x2 = base->pxlpt[y + 1][x].x + base->bresen.center_x;
	base->bresen.y2 = base->pxlpt[y + 1][x].y + base->bresen.center_y;
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
