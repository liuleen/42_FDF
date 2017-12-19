/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rliu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/22 10:44:24 by rliu              #+#    #+#             */
/*   Updated: 2017/09/24 17:51:24 by rliu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		*ft_memalloc(size_t size)
{
	void *new_mem;

	new_mem = (void *)malloc(size);
	if (new_mem)
	{
		ft_bzero(new_mem, size);
		return (new_mem);
	}
	return (NULL);
}
