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

/* void		environment(t_env *base)
 {
	base->fdfimage.height = 0;
 	base->fdfimage.width = 0;
 	base->fdfimage.spacing = find_spacing(*env);
 	base->fdfimage.cart_points = plotting_points(*env, env->map);
 }
 */

t_pxlpt		**pxlpts(t_env *base)
{
	int				l;
	int				r;
	t_pxlpt			**cart_pts;

	//cart_pts[l][r].z = 
	cart_pts = (t_pxlpt **)malloc(sizeof(t_pxlpt *) * base->map.height);
	l = -1;
	while (++l < base->map.height)
	{
		cart_pts[l] = (t_pxlpt *)malloc(sizeof(t_pxlpt) * base->map.width);
		r = -1;
		while (++r < base->map.width)
		{
			cart_pts[l][r].x = l; //multiply by rotational matrix
			cart_pts[l][r].y = r; //multiply by roational matrix
			printf("The x plot points are: %f\n", cart_pts[l][r].x);
			printf("The y plot points are: %f\n", cart_pts[l][r].y);
		}
	}
	return (cart_pts);
}
