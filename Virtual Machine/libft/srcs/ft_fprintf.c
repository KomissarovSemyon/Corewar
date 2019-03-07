/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fprintf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcorwin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/19 11:11:55 by jcorwin           #+#    #+#             */
/*   Updated: 2019/01/19 11:24:50 by jcorwin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int				ft_fprintf(int fd, const char *restrict format, ...)
{
	t_printf	pr;

	pr.len = 0;
	pr.cur = pr.buf;
	if ((pr.fd = fd) < 1)
		pr.fd = 1;
	va_start(pr.args, format);
	pr.str = (char *)format;
	print_format(&pr);
	va_end(pr.args);
	write(pr.fd, pr.buf, pr.len % 1000);
	return (pr.len);
}
