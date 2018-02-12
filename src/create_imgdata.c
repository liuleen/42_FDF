/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_imgdata.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rliu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/29 22:46:10 by rliu              #+#    #+#             */
/*   Updated: 2018/02/09 05:16:26 by rliu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

t_pxlpt		**pxlpts(t_env *b)
{
	int				l;
	int				r;
	t_pxlpt			**cart_pts;

	if (!(cart_pts = (t_pxlpt **)malloc(sizeof(t_pxlpt *) *
					(b->map.height + 1))))
		ft_error("Allocation error", 3);
	l = -1;
	while (++l < b->map.height)
	{
		if (!(cart_pts[l] = (t_pxlpt *)malloc(sizeof(t_pxlpt) *
						(b->map.width + 1))))
			ft_error("Allocation error", 3);
		r = -1;
		while (++r < b->map.width)
		{
			cart_pts[l][r].y = (l - (b->map.height / 2)) * b->map.pixel_gap
				* (b->bresen.zoom < 0 ? 0 : b->bresen.zoom);
			cart_pts[l][r].x = (r - (b->map.width / 2)) * b->map.pixel_gap
				* (b->bresen.zoom < 0 ? 0 : b->bresen.zoom);
			cart_pts[l][r].z = b->map.z[l][r] * b->bresen.z
				* (b->bresen.zoom < 0 ? 0 : b->bresen.zoom);
		}
	}
	return (cart_pts);
}

void		reset(t_env *b)
{
	b->bresen.angle_x = 0;
	b->bresen.angle_y = 0;
	b->bresen.angle_z = 0;
	b->bresen.z = .5;
	b->bresen.shift_x = 0;
	b->bresen.shift_y = 0;
}

void		environment(t_env *b)
{
	b->bresen.z = .5;
	b->map.height = 0;
	b->map.width = 0;
	b->map.pixel_gap = 0;
	b->bresen.x1 = 0;
	b->bresen.x2 = 0;
	b->bresen.y1 = 0;
	b->bresen.y2 = 0;
	b->bresen.delta = 0;
	b->bresen.slope = 0;
	b->map.pixel_gap = 0;
	b->bresen.zoom = 0;
	b->bresen.shift_x = 0;
	b->bresen.shift_y = 0;
}
