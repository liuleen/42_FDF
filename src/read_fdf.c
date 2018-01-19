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

#include "../includes/fdf.h"

/*
** Gets the len of each line in the file and checks for invalid files
** such as files containing invalid characters.
*/

static int		row_length(char *str)
{
	int 	i;
	int 	length;

	i = 0;
	length = 0;
	while(str[i])
	{
		// if(str[i] == '\0')
		// 	break ;
		if(ft_isdigit(str[i]))
		{
			length++;
			while(ft_isdigit(str[i]))
				i++;
		}
		else if(str[i] == ' ')
			i++;
		else if(str[i] == '-')
			i++;
		else
			ft_error("Invalid characters", 6);
	}
	return(length);
}

/*
** Gets the number of rows in the file to store and use for map/2d array
*/

static int		col_height(t_env *base, int fd)
{
	int 	length;
	int		height;
	int 	width;
	char 	*line;

	width = 0;
	height = 0;
	while(get_next_line(fd, &line) == 1)
	{
		length = row_length(line);
		if (length > width)
			width = length;
		height++;
		free(line);
	}
	if (close(fd) < 0)
		ft_error("Close Error!!", 6);
	base->map.width = width;
	return (height);
}

/*
** Read the fdf file
*/

int			read_fdf(t_env *base, int fd, char *line, char *argv)
{
	char 	**array;
	int		i;
	int		x;
	int		y;
	int		value;

	i = 0;
	y = 0;
	base->map.height = col_height(base, fd);
	if(!(base->map.z = (int **)malloc(sizeof(int *) * base->map.height)))
		ft_error("Allocation error", 3);
	if ((fd = open(argv, O_RDONLY)) < 1)
		ft_error("Open Error", 4);
	while((y < base->map.height) && (get_next_line(fd, &line) == 1))
	{
		if(!(base->map.z[y] = (int *)malloc(sizeof(int) * base->map.width)))
			ft_error("Allocation error", 3);
		x = 0;
		array = ft_strsplit(line, ' ');
		while((x < base->map.width) && (array[i]))
		{
			value = ft_atoi(array[i]);
			base->map.z[y][x] = value;
			printf("map.z[%i][%i]: %i", y, x, base->map.z[y][x]);
			i++;
			x++;
		}
		y++;
		free(line);
		free(array);
	}
	return (1);
}