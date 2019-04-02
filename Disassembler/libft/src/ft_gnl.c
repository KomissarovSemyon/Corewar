/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amerlon- <amerlon-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/06 12:24:33 by amerlon-          #+#    #+#             */
/*   Updated: 2018/12/18 22:16:41 by amerlon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static t_list	*t_list_create_file(int fd)
{
	t_list	*res;

	res = (t_list *)malloc(sizeof(t_list));
	if (!res)
		return (NULL);
	res->content = ft_strnew(0);
	if (!res->content)
	{
		free(res);
		return (NULL);
	}
	res->content_size = fd;
	res->next = NULL;
	return (res);
}

static t_list	*get_file(int fd, t_list **head)
{
	t_list	*now;

	if (!head || fd < 0)
		return (NULL);
	now = *head;
	while (now)
	{
		if (now->content_size == (size_t)fd)
			return (now);
		now = now->next;
	}
	now = t_list_create_file(fd);
	if (!now)
		return (NULL);
	ft_lstadd(head, now);
	return (now);
}

static int		ft_lstdelfile(t_list **head, int fd)
{
	t_list	*now;
	t_list	*prev;

	if ((!head || !(now = *head) || fd < 0))
		return (0);
	if ((now->content_size == (size_t)fd) && !(prev = NULL))
	{
		free(now->content);
		*head = now->next;
		free(now);
		return (0);
	}
	while (now)
	{
		if (now->content_size == (size_t)fd)
		{
			free(now->content);
			prev ? (prev->next = now->next) : (0);
			free(now);
			return (0);
		}
		prev = now;
		now = now->next;
	}
	return (0);
}

static int		make_return_value(t_list *file, t_list **head,
									int len, char **line)
{
	if (ft_strchr_safe(file->content, '\n'))
	{
		free(*line);
		*line = ft_copyuntil(file->content, '\n');
		file->content = ft_strshift((char **)&(file->content),
			ft_strchr(file->content, '\n') - (char *)(file->content) + 1);
		return (1);
	}
	if (file->content && !len)
	{
		if (((char *)(file->content))[0] == '\0')
			return (ft_lstdelfile(head, file->content_size));
		ft_strdel((char **)&(file->content));
		return (1);
	}
	return (ft_lstdelfile(head, file->content_size));
}

int				ft_gnl(const int fd, char **line)
{
	static t_list	*head;
	t_list			*file;
	char			buff[BUFF_SIZE + 1];
	int				len;
	char			*temp;

	if (fd < 0 || !line || (read(fd, buff, 0) < 0))
		return (-1);
	len = 1;
	file = get_file(fd, &head);
	temp = NULL;
	while (!(ft_strchr_safe(file->content, '\n')) && len)
	{
		free(temp);
		temp = NULL;
		len = read(file->content_size, buff, BUFF_SIZE);
		buff[len] = '\0';
		temp = ft_strjoin((char *)(file->content), buff);
		free(file->content);
		file->content = ft_strdup_safe(temp);
	}
	*line = temp;
	return (make_return_value(file, &head, len, line));
}
