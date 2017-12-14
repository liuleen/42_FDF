/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rliu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/21 11:18:39 by rliu              #+#    #+#             */
/*   Updated: 2017/09/28 18:41:11 by rliu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *s1, const char *s2, size_t n)
{
	char	*str1;
	char	*str2;
	size_t	i;
	size_t	j;
	size_t	tmp;

	str1 = (char *)s1;
	str2 = (char *)s2;
	i = 0;
	if (!*str2)
		return (str1);
	while ((i < n) && *(str1 + i))
	{
		j = 0;
		tmp = i;
		while ((tmp < n) && str1[tmp++] == str2[j++])
			if (!*(str2 + j))
				return (str1 + i);
		i++;
	}
	return (NULL);
}
