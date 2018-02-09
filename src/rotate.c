#include "../includes/fdf.h"

void		 rotate_zaxis(t_env *base)
{
	int i;
	int j;
	int tmpx;
	int tmpy;

	i = -1;
	while (++i < base->map.height)
	{
		j = -1;
		while (++j < base->map.width)
		{
			tmpx = base->pxlpt[i][j].x;
			tmpy = base->pxlpt[i][j].y;
			base->pxlpt[i][j].x =  tmpx * cos(0.633038) - tmpy * sin(0.633038);
			base->pxlpt[i][j].y = tmpx * sin(0.633038) + tmpy * cos(0.633038);
		}
	}
}
//transform theta --> radians (radians = degrees × π / 180°) --> key event
//M_PI == pi

void		rotate_xaxis(t_env *base)
{
	int i;
	int j;
	int tmpy;
	int tmpz;

	i = -1;
	while (++i < base->map.height)
	{
		j = -1;
		while (++j < base->map.width)
		{
			tmpy = base->pxlpt[i][j].y;
			tmpz = base->pxlpt[i][j].z;
			base->pxlpt[i][j].y = tmpy * cos(0.933038) - tmpz * 5 * sin(0.933038);
			base->pxlpt[i][j].z = tmpz * sin(0.933038) + tmpz * cos(0.933038);
		}
	}
}

void		rotate(t_env *base)
{
	rotate_xaxis(base);
	rotate_zaxis(base);
}