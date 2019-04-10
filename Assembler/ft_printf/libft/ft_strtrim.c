/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltuffleb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/23 17:20:15 by ltuffleb          #+#    #+#             */
/*   Updated: 2018/12/11 16:58:52 by ltuffleb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	size_t	get_ready(char const *s, size_t *min, size_t *max, size_t *inc)
{
	size_t	a;

	*min = 0;
	*max = 0;
	while (s[*max])
		(*max)++;
	if (*max > 0)
		(*max)--;
	a = *max;
	while (*min < *max && (s[*min] == ' ' ||
			s[*min] == '\n' || s[*min] == '\t'))
		(*min)++;
	while (*max > *min && (s[*max] == ' ' ||
			s[*max] == '\n' || s[*max] == '\t'))
		(*max)--;
	*inc = 0;
	if (*max != *min)
		*inc = 1;
	return (a);
}

static	size_t	is_symbol(char const *s)
{
	size_t	i;

	i = 0;
	while (s[i])
	{
		if (s[i] != ' ' && s[i] != '\n' && s[i] != '\t')
			return (1);
		i++;
	}
	return (0);
}

char			*ft_strtrim(char const *s)
{
	size_t	max;
	size_t	min;
	size_t	i;
	char	*new;
	size_t	inc;

	if (!s)
		return (NULL);
	if (get_ready(s, &min, &max, &inc) == max && min == 0)
		return (ft_strdup((char *)s));
	if (max < min)
		return (NULL);
	new = (char *)malloc(sizeof(char) * (max - min + inc + 1));
	if (!new)
		return (NULL);
	i = 0;
	inc = is_symbol(s);
	while (i + min < max || (i + min == max && inc))
	{
		new[i] = s[min + i];
		i++;
	}
	new[i] = '\0';
	return (new);
}
