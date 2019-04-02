/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltuffleb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/27 14:57:41 by ltuffleb          #+#    #+#             */
/*   Updated: 2018/12/15 18:08:26 by ltuffleb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	void	init_goes(char *buf, t_list *el)
{
	int		start_i;
	int		start_j;
	int		i;
	int		index;

	start_i = -1;
	index = 0;
	i = 0;
	while (buf[i])
	{
		if (buf[i] == '#')
		{
			if (start_i == -1)
			{
				start_i = i / 5;
				start_j = i % 5;
			}
			else
			{
				el->i[index] = (i / 5) - start_i;
				el->j[index++] = (i % 5) - start_j;
			}
		}
		i++;
	}
}

t_list			*ft_lstnew(char *buf, int num)
{
	t_list	*new;

	new = (t_list *)malloc(sizeof(t_list));
	if (!new)
		return (NULL);
	if (num + 'A' > 'Z')
		new->c = num + 'a' - 26;
	else
		new->c = num + 'A';
	new->next = NULL;
	init_goes(buf, new);
	return (new);
}
