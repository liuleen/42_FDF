/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rliu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/02 22:18:03 by rliu              #+#    #+#             */
/*   Updated: 2018/02/09 04:53:17 by rliu             ###   ########.fr       */
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
	if (!(ft_strstr(str, ".fdf")))
		ft_error("there's no .fdf, invalid file name", 2);
	return (1);
}

int				expose(t_env *b)
{
	static int i = 1;

	if (i)
	{
		ft_putendl("HOLD UP REDRAWING");
		mlx_clear_window(b->mlx.mlx, b->mlx.win);
		fdf(b);
	}
	i--;
	return (0);
}

int				main(int argc, char **argv)
{
	t_env	*b;
	int		fd;
	char	*line;

	line = NULL;
	if (!(b = (t_env *)malloc(sizeof(t_env))))
		ft_error("Allocation Error", 3);
	if (argc == 2)
	{
		environment(b);
		if (check_fdf(argv[1]) != 1)
			ft_error("Oh no, you entered an invalid file", 4);
		if ((fd = open(argv[1], O_RDONLY)) < 1)
			ft_error("Oh no, open error", 4);
		if ((read_fdf(b, fd, line, argv[1])) != 1)
			ft_error("Try again, read error", 5);
		if (close(fd) < 0)
			ft_error("You got a close error!!", 6);
		window(b);
		mlx(b);
	}
	else
		write(1, "usage: ./fdf filename.fdf\n", 26);
	return (0);
}
