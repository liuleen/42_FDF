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

static void		ft_error(void)
{
	write(1, "ERROR BITCH\n", 12);
	exit(1);
}

int				main(int argc, char **argv)
{
	t_env	*base;

	if (argc == 2)
	{
		if((read_fdf(argv[1], base)) != 1)
			ft_error();
	}
	else
		write(1, "usage: ./fdf filename.fdf\n", 26);
	return (0);
}
