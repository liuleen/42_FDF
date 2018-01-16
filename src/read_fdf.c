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
** Gets the number values in each line from the fdf file.
** If there's an invalid character in the line, prints an error message.
** Sometimes my fdf calaquea, asi que I added "read error" in the error message,
** because my gnl is broken? or some shit like that... It happens very rarely.
*/

static int		row_length(char *str)
{
	int i;
	int len;

	i = 0;
	len = 0;
	while(str[i])
	{
		if(str[i] == '\0')
			break ;
		if(ft_isdigit(str[i]))
		{
			len++;
			while(ft_isdigit(str[i]))
				i++;
		}
		else if(str[i] != ' ' && str[i] != '-')
		{
			write(1, "ERROR\n", 6);
			return(0);
		}
		i++;
	}
	return(len);
}

/*
** Count and returns the number of lines (rows) that the file has.
** This value is used to allocate the correct memory size
** for the two dimensional array.
** If the total values from every line is not equal to the other lines,
** there is an error with the fdf file... lel.
*/

static int		col_height(char *str, t_env *base, int fd)
{
	int len;

	while(get_next_line(fd, &line) == 1)
	{
	}
}

/*
** Read the fdf file, allocates in memory the correct size of the height
** and width of the map.
*/

int			read_fdf(t_env *base, int fd)
{
	char 	*line;

	base->map.height = col_height(line, base, fd);
}