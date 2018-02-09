/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_fdf.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rliu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/01 18:52:03 by rliu              #+#    #+#             */
/*   Updated: 2018/02/09 05:20:46 by rliu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

/*
** Gets the len of each line in the file and checks for invalid files
** such as files containing invalid characters.
*/

static int		row_length(char *str)
{
	int		i;
	int		length;

	i = 0;
	length = 0;
	while (str[i])
	{
		if (ft_isdigit(str[i]))
		{
			length++;
			while (ft_isdigit(str[i]))
				i++;
		}
		else if (str[i] == ' ')
			i++;
		else if (str[i] == '-')
			i++;
		else
			ft_error("Invalid characters", 6);
	}
	return (length);
}

/*
** Gets the number of rows in the file to store and use for map/2d array
*/

static int		col_height(t_env *b, int fd)
{
	int		length;
	int		height;
	int		width;
	char	*line;

	width = 0;
	height = 0;
	line = NULL;
	while (get_next_line(fd, &line) == 1)
	{
		length = row_length(line);
		if (length > width)
			width = length;
		height++;
		free(line);
	}
	if (close(fd) < 0)
		ft_error("Close Error!!", 6);
	b->map.width = width;
	return (height);
}

int				read_fdf(t_env *b, int fd, char *line, char *argv)
{
	char	**array;
	int		i;
	int		x;
	int		y;

	y = -1;
	b->map.height = col_height(b, fd);
	if ((fd = open(argv, O_RDONLY)) < 1)
		ft_error("This is the second open attempt, Open Error", 4);
	if (!(b->map.z = (int **)malloc(sizeof(int *) * (b->map.height + 1))))
		ft_error("2D array; Allocation error", 3);
	while ((++y < b->map.height) && (get_next_line(fd, &line) == 1))
	{
		if (!(b->map.z[y] = (int *)malloc(sizeof(int) * (b->map.width + 1))))
			ft_error("Allocation error", 3);
		x = -1;
		i = 0;
		array = ft_strsplit(line, ' ');
		while ((++x < b->map.width) && (array[i]))
			b->map.z[y][x] = ft_atoi(array[i++]);
		free(line);
		free(array);
	}
	return (1);
}
