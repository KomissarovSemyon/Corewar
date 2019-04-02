/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadend.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vferry <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/04 15:15:01 by vferry            #+#    #+#             */
/*   Updated: 2018/12/14 20:31:22 by ltuffleb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadend(t_list **alst, t_list *new)
{
	t_list	*buff;

	if (alst)
	{
		if (*alst)
		{
			buff = *alst;
			while (buff->next)
				buff = buff->next;
			buff->next = new;
		}
		else
			*alst = new;
	}
}
