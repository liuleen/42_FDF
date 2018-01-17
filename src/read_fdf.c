/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*    read_fdf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rliu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/01 18:52:03 by rliu              #+#    #+#             */
/*   Updated: 2017/12/01 18:53:10 by rliu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/*
** Gets the len of each line in the file and checks for invalid files
** such as files containing invalid characters.
*/

static int		row_length(char *str)
{
	int 	i;
	int 	len;

	i = 0;
	len = 0;
	while(str[i])
	{
		// if(str[i] == '\0')
		// 	break ;
		if(ft_isdigit(str[i]))
		{
			len++;
			while(ft_isdigit(str[i]))
				i++;
		}
		else if(str[i] != ' ' && str[i] != '-')
			ft_error("Invalid characters", 6);
		i++;
	}
	return(len);
}

/*
** Gets the number of rows in the file to store and use for map/2d array
*/

static int		col_height(t_env *base, int fd)
{
	int 	len;
	int		height;
	int 	width;
	char 	*line;

	width = 0;
	height = 0;
	while(get_next_line(fd, &line) == 1)
	{
		len = row_length(line);
		if (len > width)
			width = len;
		height++;
		free(line);
	}
	base->map.width = width;
	return (height);
}

/*
** Read the fdf file
*/

int			read_fdf(t_env *base, int fd)
{
	char 	*line;
	char 	**array;
	int		i;
	int		x;
	int		y;

	i = 0;
	y = 0;
	base->map.height = col_height(base, fd);
	if(!(base->map.z = (int **)malloc(sizeof(int *) * base->map.height)))
		ft_error("Allocation error", 7);
	while((y < base->map.height) && (get_next_line(fd, &line) == 1))
	{
		if(!(base->map.z[y] = (int *)malloc(sizeof(int) * base->map.width)))
			ft_error("Allocation error", 7);
		x = 0;
		array = ft_strsplit(line, ' ');
		while((x < base->map.width) && (array[i]))
		{
			base->map.z[y][x] = ft_atoi(array[i]);
			i++;
			x++;
		}
		//free(array);
		y++;
		free(line);
	}
}