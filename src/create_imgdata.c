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
		((WIDTH / 2) / base->map.width) : ((HEIGHT / 2) / base->map.height);
	cart_pts = (t_pxlpt **)malloc(sizeof(t_pxlpt *) * base->map.height);
	l = -1;
	printf("half my height is %f\n", base->map.height / 2);
	printf("half my width is %f\n", base->map.width / 2);
	printf("my pixel gap is %f\n", base->map.pixel_gap);
	while (++l < base->map.height)
	{
		cart_pts[l] = (t_pxlpt *)malloc(sizeof(t_pxlpt) * base->map.width);
		r = -1;
		while (++r < base->map.width)
		{
			cart_pts[l][r].y = (l - (base->map.height / 2)) * base->map.pixel_gap;
			cart_pts[l][r].x = (r - (base->map.width / 2)) * base->map.pixel_gap;
			cart_pts[l][r].z = base->map.z[l][r];
			printf("The x plot points are: %f\n", cart_pts[l][r].x);
			printf("The y plot points are: %f\n", cart_pts[l][r].y);

		}
	}
	//free t_pxlpt; 
	return (cart_pts);
}

void		translate_image(t_env *base)
{
	int x;
	int y;

	y = -1;
	while (++y < base->map.height)
	{
		x = -1;
		while (++x < base->map.width)
		{
			base->pxlpt[y][x].y += HEIGHT / 2;
			base->pxlpt[y][x].x += WIDTH / 2;
		}
	}
}

int			color_image(t_env *base)
{
	
}

void		environment(t_env *base)
 {
 	base->map.height = 0;
 	base->map.width = 0;
 	base->map.z = NULL;
 	base->map.pixel_gap = 0;
	// base->rotate.x = 0;
	// base->rotate.y = 0;
	// base->rotate.z = 0;
 }
 
