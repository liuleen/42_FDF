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

# define WIDTH 	(700)
# define HEIGHT (700)
# define BLUE 0x0000ff
# define RED 0xff0000
# define YELLOW 0xffff00
# define WHITE 0xffffff
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
	int				height;
	int				width;
	int 			pixel_gap;
}					t_map;

typedef struct  	s_bresenham
{
	int 			x;
	int 			y;
	int 			x1;
	int 			x2;
	int 			y1;
	int 			y2;
	double			delta_x;
	double			delta_y;
	double			slope;
	double 			center_x;
	double			center_y;
}					t_bresenham;

typedef struct 		s_rotatematrix
{
	int 			x;
	int 			y;
	int 			z;
}					t_rotatematrix;

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
	t_rotatematrix	rotate;
}					t_env;

t_pxlpt				**pxlpts(t_env *base);
void				environment(t_env *base);
void				mlx(t_env *base);
void				fdf(t_env *base);
int					read_fdf(t_env *base, int fd, char *line, char *argv);
void				ft_error(char *str, int ret);
int					create_fdf(t_env *base);
int					main(int argc, char **argv);
int 				get_next_line(const int fd, char **line);

#endif
