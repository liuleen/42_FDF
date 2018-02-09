#include "../includes/fdf.h"

void		 rotate_zaxis(t_env *base)
{
	int i;
	int j;
	float tmpx;
	float tmpy;

	i = -1;
	while (++i < base->map.height)
	{
		j = -1;
		while (++j < base->map.width)
		{
			tmpx = base->pxlpt[i][j].x;
			tmpy = base->pxlpt[i][j].y;
			base->pxlpt[i][j].x =  tmpx * cos(base->bresen.angle_z) - tmpy * sin(base->bresen.angle_z);
			base->pxlpt[i][j].y = tmpx * sin(base->bresen.angle_z) + tmpy * cos(base->bresen.angle_z);
		}
	}
}
//transform theta --> radians (radians = degrees × π / 180°) --> key event
//M_PI == pi

void		rotate_yaxis(t_env *base)
{
	int i;
	int j;
	float tmpx;
	float tmpz;

	i = -1;
	while (++i < base->map.height)
	{
		j = -1;
		while (++j < base->map.width)
		{
			tmpx = base->pxlpt[i][j].x;
			tmpz = base->pxlpt[i][j].z;
			base->pxlpt[i][j].x = tmpx * cos(base->bresen.angle_y) + tmpz * sin(base->bresen.angle_y);
			base->pxlpt[i][j].z = -tmpx * sin(base->bresen.angle_y) + tmpz * cos(base->bresen.angle_y);
		}
	}
}
void		rotate_xaxis(t_env *base)
{
	int i;
	int j;
	float tmpy;
	float tmpz;

	i = -1;
	while (++i < base->map.height)
	{
		j = -1;
		while (++j < base->map.width)
		{
			tmpy = base->pxlpt[i][j].y;
			tmpz = base->pxlpt[i][j].z;
			base->pxlpt[i][j].y = tmpy * cos(base->bresen.angle_x) - tmpz * 5 * sin(base->bresen.angle_x);
			base->pxlpt[i][j].z = tmpz * sin(base->bresen.angle_x) + tmpz * cos(base->bresen.angle_x);
		}
	}
}

void		rotate(t_env *base)
{
	rotate_xaxis(base);
	rotate_yaxis(base);
	rotate_zaxis(base);
}