/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_del.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcorwin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/25 21:31:08 by jcorwin           #+#    #+#             */
/*   Updated: 2019/02/27 10:09:59 by jcorwin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		arg_cut(char **arg, char *dst)
{
	int		i;

	i = 0;
	while (arg[i] != dst)
		++i;
	while (arg[i++])
		arg[i - 1] = arg[i];
}

char		**arg_del(char **matrix)
{
	int		i;

	i = 0;
	while (matrix[i])
		free(matrix[i++]);
	free(matrix);
	return (0);
}

char		**arg_add(char **arg, char *str)
{
	int		i;
	char	**new;

	i = arg_len(arg);
	if (!(new = (char **)malloc(sizeof(char *) * (i + 2))))
		return (NULL);
	new[i + 1] = NULL;
	new[i] = str;
	while (i-- > 0)
		new[i] = arg[i];
	if (arg)
		free(arg);
	return (new);
}

void		arg_print(char **arg, char *del)
{
	int		i;

	i = 0;
	while (arg[i])
		putl(arg[i++], del);
}

char		**arg_join(char **dst, char **src)
{
	char	**new;
	int		i;
	int		j;

	if (!src)
		return (dst);
	if (!dst)
		return (src);
	if (!(new = (char **)malloc(sizeof(char *) *
					(arg_len(dst) + arg_len(src) + 1))))
		return (NULL);
	i = -1;
	while (dst[++i])
		new[i] = dst[i];
	j = -1;
	while (src[++j])
		new[i++] = src[j];
	free(src);
	free(dst);
	return (new);
}
