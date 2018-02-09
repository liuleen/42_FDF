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
# define FDF_H

# include "../minilibx/mlx.h"
# include "../libft/libft.h"

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>
# include <math.h>

# define WIDTH 	(800)
# define HEIGHT (600)
# define BLUE 0x0000ff
# define RED 0xff0000
# define YELLOW 0xffff00
# define WHITE 0xffffff
# define CYAN 0x00ffff
# define GRAY 0xd3d3d3
# define ESCAPE 53
# define UP 126
# define DOWN 125
# define RIGHT 124
# define LEFT 123
# define ZOOMIN 24
# define ZOOMOUT 23

typedef struct 		s_map
{
	int				**z;
	float			height;
	float			width;
	float 			pixel_gap;
}					t_map;

typedef struct  	s_bresenham
{
	float 			x;
	float 			y;
	float 			x1;
	float 			x2;
	float 			y1;
	float 			y2;
	double			delta_x;
	double			delta_y;
	float   		delta;
	float 			slope;
	double 			mid_x;
	double			mid_y;

	float 			offset;
	float 			adjust;
	float			threshold;
}					t_bresenham;

//CARTESIAN POINTS
typedef struct 		s_pxlpt
{
	double			x;
	double			y;
	double			z;
}					t_pxlpt;

typedef struct		s_mlx
{
	void			*mlx;
	void			*init;
	void			*win;
	void			*img;
}					t_mlx;


typedef struct 		s_env
{
	t_map			map;
	t_mlx			mlx;
	t_pxlpt			**pxlpt;
	t_bresenham		bresen;
}					t_env;

t_pxlpt				**pxlpts(t_env *base);
void				environment(t_env *base);
void				mlx(t_env *base);
void				rotate(t_env *base);
void				fdf(t_env *base);
void				translate_image(t_env *base);
int					read_fdf(t_env *base, int fd, char *line, char *argv);
void				ft_error(char *str, int ret);
int					create_fdf(t_env *base);
int					main(int argc, char **argv);
int 				get_next_line(const int fd, char **line);

#endif
