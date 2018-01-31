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


	base->map.pixel_gap = base->map.width > base->map.height ? \
		WIDTH / base->map.width : HEIGHT / base->map.height;
	cart_pts = (t_pxlpt **)malloc(sizeof(t_pxlpt *) * base->map.height);
	l = -1;
	while (++l < base->map.height)
	{
		cart_pts[l] = (t_pxlpt *)malloc(sizeof(t_pxlpt) * base->map.width);
		r = -1;
		while (++r < base->map.width)
		{
			cart_pts[l][r].y = l; //multiply by rotational matrix
			cart_pts[l][r].x = r; //multiply by roational matrix
			cart_pts[l][r].z = base->map.z[l][r];
			printf("The x plot points are: %f\n", cart_pts[l][r].x);
			printf("The y plot points are: %f\n", cart_pts[l][r].y);

			cart_pts[l][r].x *= base->map.pixel_gap;
			cart_pts[l][r].y *= base->map.pixel_gap;
			if(base->map.z[l][r] > 0)
				mlx_pixel_put(base->mlx.mlx, base->mlx.win, cart_pts[l][r].x, cart_pts[l][r].y, 0x0000ff);
			else
				mlx_pixel_put(base->mlx.mlx, base->mlx.win, cart_pts[l][r].x, cart_pts[l][r].y, 0xff0000);
		}
	}
	//free t_pxlpt;
	return (cart_pts);
}

/* void		environment(t_env *base)
 {
 	base->map.height = 0;
 	base->map.width = 0;
 	
 	base->pxlpt = pxlpts(base);
 	base->bresenham.offset_x = (WIDTH / 2) - base->map.width;
	base->bresenham.offset_y = (HEIGHT / 2) - base->map.height;
	base->map.pixel_gap = base->map.width > base->map.height ? \
		WIDTH / base->map.width : HEIGHT / base->map.height;
 }
 */
