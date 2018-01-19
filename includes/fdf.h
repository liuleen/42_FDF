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

# define WIDTH 	(720)
# define HEIGHT (720)

typedef struct 		s_map
{
	int				**z;
	int				height;
	int				width;
	int 			y1;
	int 			y2;
	int 			x2;
	int 			x1;
}					t_map;

typedef struct 		s_pixelpoint
{
	float			x;
	float			y;
	float			z;
}					t_pixelpoint;


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
	t_pixelpoint	**pixel_point;
}					t_env;

void				mlx(t_env *base);
int					read_fdf(t_env *base, int fd, char *line, char *argv);
void				ft_error(char *str, int ret);
int					main(int argc, char **argv);

#endif
