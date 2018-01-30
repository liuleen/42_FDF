*--*-------------*--**/* ************************************************************************** */
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

t_pixelpoint		**pixelpoints(t_env *base)
{
	int				left;
	int				right;
	t_pixelpoint	**cart_points;

	left = -1;
	while (++left < base->map.height)
	{
		right = -1;
		while (++right < base->map.width)
		{
			cart_points[left][right].x = left;
			cart_points[left][right].y = right;
		}
	}
	return (cart_points);
}