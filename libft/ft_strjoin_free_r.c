/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin_free_r.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rliu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/30 18:44:09 by rliu              #+#    #+#             */
/*   Updated: 2017/09/30 18:44:10 by rliu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin_free_r(char const *s1, char *s2)
{
	char *str_new;

	if (!s1 || !s2 || !(str_new = ft_strnew((ft_strlen(s1) + ft_strlen(s2)))))
		return (NULL);
	str_new = ft_strcpy(str_new, s1);
	str_new = ft_strcat(str_new, s2);
	free(s2);
	return (str_new);
}
