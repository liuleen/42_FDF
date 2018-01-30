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

void		bresenham()
{
	
}

void		horizontal()
{

}

void		vertical()
{

}

int			fdf(t_env *base)
{
	int 	y;
	int 	x;

	y = -1;
	while (++y < base->map.height)
	{
		x = -1;
		while (++x < base->map.width)
		{
			
		}
	}
}

//plot on window w/key bindingns
//convert z to a 2d array of points on the window <-- allows offset, --> double x and y
//youtube bresenham's algorithm, use two random points