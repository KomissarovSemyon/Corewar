/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_make.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcorwin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/25 21:03:36 by jcorwin           #+#    #+#             */
/*   Updated: 2019/03/07 03:58:25 by jcorwin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		count_words(char *str, char *del)
{
	int		counter;

	if (!str)
		return (0);
	if (!del)
		return (1);
	if (*del == '\0')
		return (del[1]);
	counter = (ft_strchr(del, *str) ? 0 : 1);
	while (*str)
	{
		if (ft_strchr(del, *str))
		{
			*str = '\0';
			if (*(str + 1) && !ft_strchr(del, *(str + 1)))
				++counter;
		}
		++str;
	}
	return (counter);
}

int				arg_len(char **arg)
{
	int		i;

	if (!arg)
		return (0);
	i = 0;
	while (arg[i])
		i++;
	return (i);
}

char			**arg_create(char *str, char *del)
{
	char	**matr;
	int		count;
	int		i;

	count = count_words(str, del);
	if (!(matr = (char **)malloc(sizeof(char *) * (1 + count))))
		return (NULL);
	matr[count] = NULL;
	i = 0;
	while (i < count)
	{
		while (*str == '\0')
			++str;
		if ((matr[i++] = ft_strdup(str)) == NULL)
			return (arg_del(matr));
		while (*str != '\0')
			++str;
	}
	return (matr);
}

char			**arg_copy(char **arg)
{
	char	**new;
	int		i;
	int		count;

	count = arg_len(arg);
	if (!(new = (char **)malloc(sizeof(char *) * (1 + count))))
		return (NULL);
	new[count] = NULL;
	i = -1;
	while (++i < count)
		new[i] = ft_strdup(arg[i]);
	return (new);
}
