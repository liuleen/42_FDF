/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rliu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/09 05:09:49 by rliu              #+#    #+#             */
/*   Updated: 2018/02/09 05:15:40 by rliu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void		rotate_zaxis(t_env *b)
{
	int		i;
	int		j;
	float	tmpx;
	float	tmpy;

	i = -1;
	while (++i < b->map.height)
	{
		j = -1;
		while (++j < b->map.width)
		{
			tmpx = b->pxlpt[i][j].x;
			tmpy = b->pxlpt[i][j].y;
			b->pxlpt[i][j].x = tmpx * cos(b->bresen.angle_z) - tmpy *
				sin(b->bresen.angle_z);
			b->pxlpt[i][j].y = tmpx * sin(b->bresen.angle_z) + tmpy *
				cos(b->bresen.angle_z);
		}
	}
}

void		rotate_yaxis(t_env *b)
{
	int		i;
	int		j;
	float	tmpx;
	float	tmpz;

	i = -1;
	while (++i < b->map.height)
	{
		j = -1;
		while (++j < b->map.width)
		{
			tmpx = b->pxlpt[i][j].x;
			tmpz = b->pxlpt[i][j].z;
			b->pxlpt[i][j].x = tmpx * cos(b->bresen.angle_y) + tmpz *
				sin(b->bresen.angle_y);
			b->pxlpt[i][j].z = -tmpx * sin(b->bresen.angle_y) + tmpz *
				cos(b->bresen.angle_y);
		}
	}
}

void		rotate_xaxis(t_env *b)
{
	int		i;
	int		j;
	float	tmpy;
	float	tmpz;

	i = -1;
	while (++i < b->map.height)
	{
		j = -1;
		while (++j < b->map.width)
		{
			tmpy = b->pxlpt[i][j].y;
			tmpz = b->pxlpt[i][j].z;
			b->pxlpt[i][j].y = tmpy * cos(b->bresen.angle_x) - tmpz *
				5 * sin(b->bresen.angle_x);
			b->pxlpt[i][j].z = tmpz * sin(b->bresen.angle_x) + tmpz *
				cos(b->bresen.angle_x);
		}
	}
}

void		rotate(t_env *b)
{
	rotate_xaxis(b);
	rotate_yaxis(b);
	rotate_zaxis(b);
}
