/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rliu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/12 00:47:07 by rliu              #+#    #+#             */
/*   Updated: 2018/02/12 00:49:39 by rliu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void		set_horizontal(t_env *b, int x, int y)
{
	b->bresen.x1 = b->pxlpt[y][x].x;
	b->bresen.y1 = b->pxlpt[y][x].y;
	b->bresen.x2 = b->pxlpt[y][x + 1].x;
	b->bresen.y2 = b->pxlpt[y][x + 1].y;
	b->bresen.delta_y = b->bresen.y2 - b->bresen.y1;
	b->bresen.delta_x = b->bresen.x2 - b->bresen.x1;
	bresenham(b);
}

void		set_vertical(t_env *b, int x, int y)
{
	b->bresen.x1 = b->pxlpt[y][x].x;
	b->bresen.y1 = b->pxlpt[y][x].y;
	b->bresen.x2 = b->pxlpt[y + 1][x].x;
	b->bresen.y2 = b->pxlpt[y + 1][x].y;
	b->bresen.delta_y = b->bresen.y2 - b->bresen.y1;
	b->bresen.delta_x = b->bresen.x2 - b->bresen.x1;
	bresenham(b);
}
