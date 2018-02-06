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

void		illuminate_pixel()
{
	
}

void		bresenham(t_env	*base)
{
	
}

void		draw_horizontal(t_env *base)
{
	// base->map.x1 = 
	// base->map.y1 = 
	// base->map.x2 = 
	// base->map.y2 = 
	// bresenham(base);
}

void		draw_vertical(t_env *base)
{
	// base->map.x1 = 
	// base->map.y1 = 
	// base->map.x2 = 
	// base->map.y2 = 
	// bresenham(base);
}

void			fdf(t_env *base, t_pxlpt)
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
				draw_horizontal(base);
			if (y + 1 < base->map.height)
				draw_vertical(base);			
		}
	}
}
