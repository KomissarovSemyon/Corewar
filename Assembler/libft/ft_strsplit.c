/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltuffleb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/23 17:47:30 by ltuffleb          #+#    #+#             */
/*   Updated: 2018/12/03 14:14:26 by ltuffleb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	void	clear(char **new, size_t index)
{
	size_t	i;

	i = 0;
	while (i < index)
	{
		ft_strdel(&new[i]);
		i++;
	}
	free(new);
}

static	size_t	get_count(char const *s, char c)
{
	size_t	i;
	size_t	len;
	size_t	count;

	i = 0;
	count = 0;
	while (s[i])
	{
		if (s[i] != c)
		{
			len = 0;
			while (s[i + len] && s[i + len] != c)
				len++;
			count++;
			i += len;
		}
		if (s[i])
			i++;
	}
	return (count);
}

static	char	*get_word(char const *s, char c, size_t *i)
{
	size_t	k;
	size_t	j;
	char	*new;
	size_t	t;

	k = *i;
	while (s[k] && s[k] != c)
		k++;
	j = *i;
	new = (char *)malloc(sizeof(char) * (k - j + 1));
	if (!new)
		return (NULL);
	t = 0;
	while (j + t < k)
	{
		new[t] = s[j + t];
		t++;
	}
	new[t] = '\0';
	*i = k;
	return (new);
}

static	char	**prepear(char const *s, char c)
{
	char	**new;
	size_t	count;

	if (!s)
		return (NULL);
	count = get_count(s, c);
	new = (char **)malloc(sizeof(char *) * (count + 1));
	if (!new)
		return (NULL);
	new[count] = NULL;
	return (new);
}

char			**ft_strsplit(char const *s, char c)
{
	size_t	i;
	size_t	index;
	char	**new;

	if (!(new = prepear(s, c)))
		return (NULL);
	i = 0;
	index = 0;
	while (s[i])
	{
		if (s[i] != c)
		{
			if (!(new[index] = get_word(s, c, &i)))
			{
				clear(new, index);
				return (NULL);
			}
			index++;
		}
		else
			i++;
	}
	return (new);
}
