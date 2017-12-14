/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rliu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/30 13:48:03 by rliu              #+#    #+#             */
/*   Updated: 2017/09/30 18:48:01 by rliu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrev(char *str)
{
	int		i;
	int		j;
	char	*new_str;

	i = 0;
	j = 0;
	while (str[i])
		i++;
	new_str = (char *)malloc(sizeof(str) * (i - 1));
	while (i > 0)
	{
		new_str[j] = str[i - 1];
		i--;
		j++;
	}
	return (new_str);
}
