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

void	ft_error()
{

}

int		main(int argc, char **argv)
{
	t_env	structception;

	structception = malloc(sizeof(t_env))
	if (argc != 2)
	{
		write(1, "usage: ./fdf filename.fdf\n", 26);
		return (0);
	}
	else
	{
		if (read_fdf(argv[1], structception) == 0)
			ft_error();
		
	}
	return (0);
}
