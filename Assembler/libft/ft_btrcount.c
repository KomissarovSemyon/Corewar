/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_btrcount.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltuffleb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/30 17:35:32 by ltuffleb          #+#    #+#             */
/*   Updated: 2018/11/30 17:35:35 by ltuffleb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_btrcount(t_btree *root)
{
	if (root)
		return (ft_btrcount(root->left) + ft_btrcount(root->right) + 1);
	return (0);
}
