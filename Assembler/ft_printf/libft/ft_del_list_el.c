/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_del_list_el.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltuffleb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/12 13:22:54 by ltuffleb          #+#    #+#             */
/*   Updated: 2018/12/14 20:50:11 by ltuffleb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_del_list_el(t_list **root, t_list *el)
{
	t_list *current;
	t_list *temp;

	current = *root;
	while (current != NULL && current != el)
	{
		temp = current;
		current = current->next;
	}
	return (1);
}
