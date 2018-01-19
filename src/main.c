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

#include "../includes/fdf.h"

void			ft_error(char *str, int ret)
{
	ft_putendl(str);
	exit(ret);
}

int				main(int argc, char **argv)
{
	t_env	*base;
	int		fd;
	char	*line;

	line = NULL;
	if (!(base = (t_env *)malloc(sizeof(t_env))))
		ft_error("Allocation Error", 3);
	if (argc == 2)
	{
		if ((fd = open(argv[1], O_RDONLY)) < 1)
			ft_error("Open Error", 4);
		if((read_fdf(base, fd, line, argv[1])) != 1)
			ft_error("Read Error", 5);
		printf("struct values stored: map.height: %i\n map.width: %i\n", base->map.height, base->map.width);
		// int j = 0;
		// int h = 0;
		// while(base->map.z[j])
		// {
		// 	while(base->map.z[j][h] < 19)
		// 	{
		// 		printf("map.z[%i][%i]: %i", j, h, base->map.z[j][h]);
		// 		h++;
		// 	}
		// 	j++;
		// }
		if (close(fd) < 0)
			ft_error("Close Error!!", 6);
		//mlx(base);
	}
	else
		write(1, "usage: ./fdf filename.fdf\n", 26);
	return (0);
}
