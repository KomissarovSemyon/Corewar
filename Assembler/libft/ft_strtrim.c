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

static	size_t	get_ready(char const *s, size_t *min, size_t *max)
{
	size_t	a;

	*min = 0;
	*max = 0;
	while (s[*max])
		(*max)++;
	a = *max;
	while (*min < *max && (s[*min] == ' ' ||
			s[*min] == '\n' || s[*min] == '\t'))
		(*min)++;
	while (*(max - 1) > *min && (s[*(max - 1)] == ' ' ||
			s[*(max - 1)] == '\n' || s[*(max - 1)] == '\t'))
		(*max)--;
	return (a);
}

char			*ft_strtrim(char const *s)
{
	size_t	max;
	size_t	min;
	size_t	i;
	char	*new;

	if (!s)
		return (NULL);
	if (get_ready(s, &min, &max) == max && min == 0 && max > 0)
		return (ft_strdup((char *)s));
	if (max <= min)
		return (NULL);
	new = (char *)malloc(sizeof(char) * (max - min + 1));
	if (!new)
		return (NULL);
	i = 0;
	while (i + min < max)
	{
		new[i] = s[min + i];
		i++;
	}
	new[i] = '\0';
	return (new);
}
