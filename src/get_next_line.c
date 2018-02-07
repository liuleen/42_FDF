/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rliu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/05 21:11:58 by rliu              #+#    #+#             */
/*   Updated: 2017/12/01 18:15:24 by rliu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"

t_list	*get_fd(t_list **head_list, int fd)
{
	t_list *tmp_list;

	tmp_list = *head_list;
	if (!(*head_list))
	{
		*head_list = (t_list *)malloc(sizeof(t_list));
		(*head_list)->content_size = (size_t)fd;
		(*head_list)->content = ft_strnew(1);
		(*head_list)->next = NULL;
		return (*head_list);
	}
	while (tmp_list->next)
	{
		if (tmp_list->content_size == (size_t)fd)
			return (tmp_list);
		tmp_list = tmp_list->next;
	}
	if (tmp_list->content_size == (size_t)fd)
		return (tmp_list);
	tmp_list->next = ft_lstnew(ft_strnew(1), fd);
	return (tmp_list->next);
}

int		big_buffer_probs(t_list *tmp_list, char **line)
{
	int		newline;
	char	*nextline;

	newline = 0;
	if (ft_strchr(tmp_list->content, '\n'))
	{
		nextline = tmp_list->content;
		while (nextline[newline] != '\n')
			newline++;
		*line = ft_strsub(tmp_list->content, 0, newline);
		tmp_list->content = ft_strsub(tmp_list->content, newline + 1,
				(ft_strlen(tmp_list->content) - newline + 1));
		free(nextline);
		return (1);
	}
	if (ft_strlen(tmp_list->content) > 0)
	{
		*line = ft_strdup(tmp_list->content);
		ft_strclr(tmp_list->content);
		return (1);
	}
	return (0);
}

int		read_next_line(int fd, t_list *tmp_list, char **line, char *str1)
{
	int			read_ret;
	char		*tmp_str;

	while ((read_ret = read(fd, str1, BUFF_SIZE)) > 0)
	{
		tmp_str = tmp_list->content;
		str1[read_ret] = '\0';
		tmp_list->content = ft_strjoin(tmp_list->content, str1);
		free(tmp_str);
		if (ft_strchr(str1, '\n'))
			break ;
	}
	if ((big_buffer_probs(tmp_list, line)) == 1)
		return (1);
	return (0);
}

int		get_next_line(const int fd, char **line)
{
	static t_list	*head_list;
	t_list			*tmp_list;
	char			str[BUFF_SIZE + 1];

	if (fd < 0 || BUFF_SIZE < 1 || !line || read(fd, str, 0) < 0)
		return (-1);
	tmp_list = get_fd(&head_list, fd);
	if (read_next_line(fd, tmp_list, line, str) == 1)
		return (1);
	return (0);
}
