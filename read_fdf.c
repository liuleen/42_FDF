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

static int		col_height(char *str, t_env *base)
{
	int len;

	while(get_next_line(fd, &line) == 1)
	{
	}
}

int			read_fdf(t_env *base, char *argv)
{
	int 	fd;
	char 	*line;

	if((fd = open(argv, O_RDONLY)) < 0)
	{
		write(1, "open error\n", 11);
		return (0);
	}
	base->map.height = col_height(line, base);
}