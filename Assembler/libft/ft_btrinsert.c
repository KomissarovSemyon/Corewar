/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_btrinsert.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltuffleb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/03 17:03:56 by ltuffleb          #+#    #+#             */
/*   Updated: 2018/12/04 14:04:34 by ltuffleb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_btrinsert(t_btree **root, void *item, int (*cmpf) (void *, void *))
{
	if (root && cmpf)
	{
		if (!*root)
			*root = ft_btrnew(item);
		else
		{
			if (cmpf((*root)->item, item) < 0)
			{
				if ((*root)->right == NULL)
					(*root)->right = ft_btrnew(item);
				else
					ft_btrinsert(&(*root)->right, item, cmpf);
			}
			if (cmpf((*root)->item, item) > 0)
			{
				if ((*root)->left == NULL)
					(*root)->left = ft_btrnew(item);
				else
					ft_btrinsert(&(*root)->left, item, cmpf);
			}
		}
	}
}
