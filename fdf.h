/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rliu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/29 22:26:09 by rliu              #+#    #+#             */
/*   Updated: 2017/11/29 23:35:32 by rliu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
#define FDF_H
//#include <mlx.h>
#include <stdio.h>
#include <fcntl.h>

typedef struct 		s_env
{
	t_map			map;
	t_pixelpoint	**pixelcoords;

}					t_env;

typedef struct 		s_map
{
	int				**z;
	int				height;
	int				width;
}					t_map;

typedef struct 		s_pixelpoint
{
	float			x;
	float			y;
	float			z;
	
}					t_pixelpoint;

#endif
