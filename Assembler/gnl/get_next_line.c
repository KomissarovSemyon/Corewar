/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltuffleb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/05 13:23:57 by ltuffleb          #+#    #+#             */
/*   Updated: 2018/12/12 17:18:34 by ltuffleb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		add_data(char *buf, t_list *el, int len, char **line)
{
	void	*temp;

	if (buf != NULL)
	{
		buf[len] = '\0';
		temp = el->content;
		if (el->content_size == 0)
			el->content = ft_strjoin("", buf);
		else
			el->content = ft_strjoin(el->content, buf);
		el->content_size = el->content_size + len;
		free(temp);
		if (el && el->content_size > 0 && el->content)
			return (check_data(line, el, len));
	}
	else
	{
		if (el && el->content_size > 0 && el->content)
			return (check_data(line, el, len));
	}
	return (0);
}

t_list	*get_list(t_list **root, char *buf, int len, const int fd)
{
	t_list	*new;
	t_list	*temp;

	new = *root;
	while (new)
	{
		if (new->des == fd)
			return (new);
		temp = new;
		new = new->next;
	}
	new = (t_list *)malloc(sizeof(t_list));
	if (!new)
		return (NULL);
	new->next = NULL;
	new->content = NULL;
	if (buf != NULL)
		new->content = ft_strdup(buf);
	new->content_size = len;
	new->des = fd;
	if (!*root)
		*root = new;
	else
		temp->next = new;
	return (new);
}

int		check_data(char **line, t_list *el, int len)
{
	char	*temp;
	char	*s;
	int		size;

	temp = ft_strchr((char *)el->content, '\n');
	if (!temp && len < BUFF_SIZE)
		temp = ft_strchr((char *)el->content, '\0');
	if (!temp)
		return (0);
	size = temp - (char *)el->content;
	*line = (char *)malloc(sizeof(char) * (size + 1));
	*line = ft_strncpy(*line, el->content, size);
	(*line)[size] = '\0';
	s = NULL;
	if (*temp == '\0')
		el->content_size = 0;
	else
	{
		el->content_size = el->content_size - size - 1;
		s = ft_strdup(temp + 1);
	}
	free(el->content);
	el->content = s;
	return (1);
}

int		get_next_line(const int fd, char **line)
{
	char			*buf;
	int				size;
	static t_list	*root;
	t_list			*el;
	int				stop;

	if (fd < 0)
		return (-1);
	el = get_list(&root, NULL, 0, fd);
	if (add_data(NULL, el, BUFF_SIZE, line))
		return (1);
	stop = 0;
	buf = (char *)malloc(sizeof(char) * (BUFF_SIZE + 1));
	while (!stop && el && ((size = read(fd, buf, BUFF_SIZE)) > 0))
		stop = add_data(buf, el, size, line);
	ft_strdel(&buf);
	if (size < 0 || !el)
		return (-1);
	if (size == 0 && el->content_size == 0 && ft_del_list_el(&root, el))
		return (0);
	if (size == 0)
		add_data(NULL, el, size, line);
	return (1);
}
