/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rliu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/22 12:40:08 by rliu              #+#    #+#             */
/*   Updated: 2017/09/28 19:13:30 by rliu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char			*new_str;
	char			*str;
	unsigned int	i;

	str = (char *)s;
	if (!(new_str = ft_strnew(len)) || !s)
		return (NULL);
	i = 0;
	while (i < len)
	{
		new_str[i] = str[start];
		i++;
		start++;
	}
	return (new_str);
}
