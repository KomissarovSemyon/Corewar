/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstcount.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltuffleb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/14 18:46:52 by ltuffleb          #+#    #+#             */
/*   Updated: 2018/12/14 19:02:59 by ltuffleb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_lstcount(t_list *root)
{
	int		i;

	i = 0;
	while (root)
	{
		i++;
		root = root->next;
	}
	return (i);
}
