/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rliu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/22 12:39:31 by rliu              #+#    #+#             */
/*   Updated: 2017/09/24 17:57:00 by rliu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strjoin(char const *s1, char const *s2)
{
	char *new_str;

	if (!s1 || !s2 || !(new_str = ft_strnew((ft_strlen(s1) + ft_strlen(s2)))))
		return (NULL);
	new_str = ft_strcpy(new_str, s1);
	new_str = ft_strcat(new_str, s2);
	return (new_str);
}
