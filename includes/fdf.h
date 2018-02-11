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
# define ZOOMOUT 27
# define TURNLEFT 18
# define TURNRIGHT 19
# define ROTATEUP 20
# define ROTATEDOWN 21
# define ROTATERIGHT 23
# define ROTATELEFT 22
# define OUT 49
# define IN 51
# define RESET 36
# define COLOR 0

typedef struct 		s_map
{
	int				**z;
	int				height;
	int				width;
	float 			pixel_gap;
}					t_map;

//float x and float y are used as temps so origianls don't change

typedef struct  	s_bresenham
{
	float 			x;
	float 			y;
	float 			x1;
	float 			x2;
	float 			y1;
	float 			y2;
	float			delta_x;
	float			delta_y;
	float   		delta;
	float 			slope;

	float 			offset;
	float 			adjust;
	float			threshold;
	float			zoom;
	float 			angle_x;
	float			angle_y;
	float			angle_z;
	float 			z;
	float 			shift_x;
	float 			shift_y;
	float 			color;
}					t_bresenham;

//CARTESIAN POINTS
typedef struct 		s_pxlpt
{
	float			x;
	float			y;
	float			z;
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
	float 			tmpy;
	float 			tmpx;
}					t_env;

t_pxlpt				**pxlpts(t_env *base);
void				environment(t_env *base);
void				mlx(t_env *base);
void				user_message(t_env *b);
void				reset(t_env *b);
void 				color(t_env *b, int x, int y);
void				rotate(t_env *base);
int 				expose(t_env *base);
void				fdf(t_env *base);
void				window(t_env *b);
void				translate_image(t_env *base);
int					read_fdf(t_env *base, int fd, char *line, char *argv);
void				ft_error(char *str, int ret);
void 				reset(t_env *base);
int					create_fdf(t_env *base);
int					main(int argc, char **argv);
int 				get_next_line(const int fd, char **line);

#endif
