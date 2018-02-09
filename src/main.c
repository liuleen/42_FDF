/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rliu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/02 22:18:03 by rliu              #+#    #+#             */
/*   Updated: 2018/01/29 16:05:27 by rliu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void			ft_error(char *str, int ret)
{
	ft_putendl(str);
	exit(ret);
}

static int		check_fdf(char *str)
{
	int		i;
	int		j;
	char	*fdf;

	j = 0;
	fdf = "fdf";
	i = ft_strlen(str);
	i--;
	while (fdf[j])
	{
		if (str[i] == fdf[j])
		{
			i--;
			j++;
		}
		else
			return (0);
	}
	return (1);
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
		environment(base);
		if (check_fdf(argv[1]) != 1)
			ft_error("Oh no, you entered an invalid file", 4);
		if ((fd = open(argv[1], O_RDONLY)) < 1)
			ft_error("Oh no, open error", 4);
		if ((read_fdf(base, fd, line, argv[1])) != 1)
			ft_error("Try again, read error", 5);
		printf("struct values stored: map.height: %f\n map.width: %f\n", base->map.height, base->map.width);
		if (close(fd) < 0)
			ft_error("You got a close error!!", 6);
		mlx(base);
	}
	else
		write(1, "usage: ./fdf filename.fdf\n", 26);
	return (0);
}
