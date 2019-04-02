/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltuffleb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/27 17:10:51 by ltuffleb          #+#    #+#             */
/*   Updated: 2018/12/06 14:08:40 by ltuffleb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int		check_next(t_list *current)
{
	if (!current->next)
	{
		free(current->content);
		free(current);
		return (0);
	}
	return (1);
}

t_list			*ft_lstmap(t_list *lst, t_list *(*f) (t_list *elem))
{
	t_list	*current;
	t_list	*el;

	if (lst && f)
	{
		el = f(lst);
		if (!el)
			return (NULL);
		current = ft_lstnew(el->content, el->content_size);
		free(el);
		if (!current)
			return (NULL);
		if (lst->next)
		{
			current->next = ft_lstmap(lst->next, f);
			if (!check_next(current))
				return (NULL);
		}
		else
			current->next = NULL;
		return (current);
	}
	return (NULL);
}
