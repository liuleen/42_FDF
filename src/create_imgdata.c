/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_imgdata.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rliu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/29 22:46:10 by rliu              #+#    #+#             */
/*   Updated: 2018/01/29 22:46:18 by rliu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

t_pxlpt		**pxlpts(t_env *base)
{
	int				l;
	int				r;
	t_pxlpt			**cart_pts;

	
	if (!(cart_pts = (t_pxlpt **)malloc(sizeof(t_pxlpt *) * (base->map.height + 1))))
		ft_error("Allocation error", 3);
	l = -1;
	// printf("half my height is %f\n", base->map.height / 2);
	// printf("half my width is %f\n", base->map.width / 2);
	// printf("my pixel gap is %f\n", base->map.pixel_gap);
	while (++l < base->map.height)
	{
		if (!(cart_pts[l] = (t_pxlpt *)malloc(sizeof(t_pxlpt) * (base->map.width + 1))))
			ft_error("Allocation error", 3);
		r = -1;
		while (++r < base->map.width)
		{
			cart_pts[l][r].y = (l - (base->bresen.mid_y)) * base->map.pixel_gap; 
				//(base->bresen.zoom < 0 ? 5 : base->bresen.zoom);
			cart_pts[l][r].x = (r - (base->bresen.mid_x)) * base->map.pixel_gap;
				//(base->bresen.zoom < 0 ? 5 : base->bresen.zoom);
			cart_pts[l][r].z = base->map.z[l][r];
			// printf("The x plot points are: %f\n", cart_pts[l][r].x);
			// printf("The y plot points are: %f\n", cart_pts[l][r].y);

		}
	}
	//free t_pxlpt;
	return (cart_pts);
}

void		setup_env(t_env *base)
{
	base->bresen.mid_x = base->map.width / 2;
	base->bresen.mid_y = base->map.height / 2;
	base->map.pixel_gap = base->map.width > base->map.height ? \
		((WIDTH / 2) / base->map.width) : ((HEIGHT / 2) / base->map.height);
	base->bresen.z = 75;
}

void 		reset(t_env *base)
{
	base->bresen.angle_x = 0.42;
	base->bresen.angle_y = 0.42;
	base->bresen.angle_z = 0.42;
	base->bresen.zoom = 0;
	base->bresen.z = 100;
	base->bresen.shift_x = 0;
	base->bresen.shift_y = 0;
}

void		environment(t_env *base)
 {
 	base->map.height = 0;
 	base->map.width = 0;
 	base->map.z = NULL;
 	base->map.pixel_gap = 0;
 	base->bresen.mid_x = 0;
 	base->bresen.mid_y = 0;
 	base->bresen.x1 = 0;
 	base->bresen.x2 = 0;
 	base->bresen.y1 = 0;
 	base->bresen.y2 = 0;
 	base->bresen.delta = 0;
 	base->bresen.slope = 0;
 	base->map.pixel_gap = 0;
 }
 
