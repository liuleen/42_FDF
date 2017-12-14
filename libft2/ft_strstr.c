/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rliu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/21 11:20:20 by rliu              #+#    #+#             */
/*   Updated: 2017/09/21 11:20:21 by rliu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *big, const char *little)
{
	int i;
	int j;
	int length;

	i = 0;
	j = 0;
	length = 0;
	while (little[length] != '\0')
		length++;
	if (length == 0)
		return ((char *)big);
	while (big[i] != '\0')
	{
		while (little[j] == big[i + j])
		{
			if (j == length - 1)
				return ((char *)big + i);
			j++;
		}
		j = 0;
		i++;
	}
	return (NULL);
}
