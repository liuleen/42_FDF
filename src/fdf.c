/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rliu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/01 18:52:03 by rliu              #+#    #+#             */
/*   Updated: 2017/12/01 18:53:10 by rliu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		create_fdf(t_env *base)
{
	int		x;
	int		y;

	y = 0;
	base->mlx.img = mlx_new_image(fdf->mlx.init, WIDTH, HEIGHT);
	while (y++ < base->map.height)
	{
		x = 0;
		while (x++ < base->map.width)
		{
			base->map.x1 = x;
			base->map.y1 = y;
			if (x + 1 < base->map.width) //was y
				draw_horizontal(fdf, x, y);
			if (y + 1 < fdf->map.height)
				draw_vertical(fdf, x, y);
		}
	}
	mlx_put_image_to_window(fdf->mlx.init, fdf->mlx.win, fdf->mlx.img, 0, 0);
	mlx_destroy_image(fdf->mlx.init, fdf->mlx.img);
	return (0);
}

