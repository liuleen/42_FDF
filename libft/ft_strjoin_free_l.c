/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin_free_l.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rliu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/30 18:43:53 by rliu              #+#    #+#             */
/*   Updated: 2017/09/30 18:45:44 by rliu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin_free_l(char *s1, char const *s2)
{
	char *str_new;

	if (!s1 || !s2 || !(str_new = ft_strnew((ft_strlen(s1) + ft_strlen(s2)))))
		return (NULL);
	str_new = ft_strcpy(str_new, s1);
	str_new = ft_strcat(str_new, s2);
	free(s1);
	return (str_new);
}
