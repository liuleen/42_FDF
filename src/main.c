/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rliu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/02 22:18:03 by rliu              #+#    #+#             */
/*   Updated: 2017/12/02 22:29:12 by rliu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void			ft_error(char *str, int ret)
{
	ft_putendl(str);
	exit(ret);
}

int				main(int argc, char **argv)
{
	t_env	*base;
	int		fd;

	if (!(base = (t_env *)malloc(sizeof(t_env))))
		ft_error("Memory Allocation Error", 3);
	if (argc == 2)
	{
		if ((fd = open(argv[1], O_RDONLY)) < 1)
			ft_error("Open Error", 4);
		if((read_fdf(base, fd)) != 1)
			ft_error("Read Error", 5);
		if (close(fd) < 0)
			ft_error("Close Error", 6);
		//emelex(base);
	}
	else
		write(1, "usage: ./fdf filename.fdf\n", 26);
	return (0);
}
