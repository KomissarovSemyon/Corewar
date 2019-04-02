/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltuffleb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/27 15:30:55 by ltuffleb          #+#    #+#             */
/*   Updated: 2018/12/14 20:44:57 by ltuffleb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del) (void *, size_t))
{
	t_list *temp;

	while (alst && del && *alst)
	{
		temp = *alst;
		*alst = (*alst)->next;
		free(temp);
	}
	if (alst)
		*alst = NULL;
}
