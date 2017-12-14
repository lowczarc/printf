/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_int.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lowczarc <lowczarc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/02 20:48:16 by lowczarc          #+#    #+#             */
/*   Updated: 2017/12/08 16:39:13 by lowczarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "ft_printf.h"
#include <stdio.h>

char	*signed_format(va_list ap, t_formaitem *format)
{
	if (format->flags & 1)
		return (ft_llitoa((char)va_arg(ap, int), format->precision));
	else if (format->flags & 2)
		return (ft_llitoa((short)va_arg(ap, int), format->precision));
	else if (format->flags & 4)
		return (ft_llitoa(va_arg(ap, long int), format->precision));
	else if (format->flags & 8)
		return (ft_llitoa(va_arg(ap, long long int), format->precision));
	else
		return (ft_llitoa(va_arg(ap, int), format->precision));
}

char	*unsigned_format(va_list ap, t_formaitem *format)
{
	if (format->flags & 1)
		return (ft_llutoa((unsigned char)va_arg(ap, int), format->precision));
	else if (format->flags & 2)
		return (ft_llutoa((unsigned short)va_arg(ap, int), format->precision));
	else if (format->flags & 4)
		return (ft_llutoa(va_arg(ap, unsigned long int), format->precision));
	else if (format->flags & 8)
		return (ft_llutoa(va_arg(ap, unsigned long long int), format->precision));
	else
		return (ft_llutoa(va_arg(ap, unsigned int), format->precision));
}

char	*int_format(va_list ap, t_formaitem *format)
{
	char		*ret;

	if (format->precision != -1)
		format->flags = format->flags & 0xFDFF;
	else if (format->precision == -1 && format->flags & 512)
		format->precision = format->min_size;
	ret = (format->flags & 64) ? unsigned_format(ap, format)
		: signed_format(ap, format);
	return (ret);
}
