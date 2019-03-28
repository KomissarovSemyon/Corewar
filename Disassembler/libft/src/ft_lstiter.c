/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amerlon- <amerlon-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/01 19:09:47 by amerlon-          #+#    #+#             */
/*   Updated: 2018/12/01 19:40:04 by amerlon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(t_list *elem))
{
	t_list	*now;
	t_list	*temp;

	if (!lst || !f)
		return ;
	now = lst;
	while (now)
	{
		temp = now->next;
		(*f)(now);
		now = temp;
	}
}
