/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrhaenys <rrhaenys@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/16 21:04:57 by rrhaenys          #+#    #+#             */
/*   Updated: 2019/02/20 18:09:00 by rrhaenys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void		ft_free_ptr(void *data)
{
	if (data != NULL)
	{
		free(data);
	}
}

void		ft_free(char **str)
{
	int		index;

	if (str == NULL)
		return ;
	index = -1;
	while (str[++index] != NULL)
	{
		free(str[index]);
	}
	free(str);
}
