/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rliu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/21 11:19:34 by rliu              #+#    #+#             */
/*   Updated: 2017/10/03 19:53:59 by rliu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	size_t			len;
	char			*str;

	len = ft_strlen(s1);
	if (!(str = (char *)malloc(sizeof(*str) * len + 1)))
		return (NULL);
	str = ft_strcpy(str, s1);
	return (str);
}
