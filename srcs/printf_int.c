/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_int.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lowczarc <lowczarc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/02 20:48:16 by lowczarc          #+#    #+#             */
/*   Updated: 2017/12/15 17:52:11 by lowczarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "ft_printf.h"
#include <stdio.h>

char	*signed_format(va_list ap, t_formaitem *format)
{
	if (format->flags & 1)
		return (ft_llitoa((char)va_arg(ap, int), format));
	else if (format->flags & 2)
		return (ft_llitoa((short)va_arg(ap, int), format));
	else if (format->flags & 4)
		return (ft_llitoa(va_arg(ap, long int), format));
	else if (format->flags & 8)
		return (ft_llitoa(va_arg(ap, long long int), format));
	else
		return (ft_llitoa(va_arg(ap, int), format));
}

char	*unsigned_format(va_list ap, t_formaitem *format)
{
	unsigned long long int	nb;

	if (format->flags & 1)
		nb = (unsigned char)va_arg(ap, int);
	else if (format->flags & 2)
		nb = (unsigned short)va_arg(ap, int);
	else if (format->flags & 4)
		nb = va_arg(ap, unsigned long);
	else if (format->flags & 8)
		nb = va_arg(ap, unsigned long long);
	else
		nb = va_arg(ap, unsigned int);
	if (format->format == 'u' || format->format == 'U')
		return (ft_llutoa(nb, format->precision));
	if (format->format == 'x')
		return (ft_llxtoa(nb, format->precision, "0123456789abcdef"));
	if (format->format == 'X')
		return (ft_llxtoa(nb, format->precision, "0123456789ABCDEF"));
	if (format->format == 'o' || format->format == 'O')
		return (ft_llxtoa(nb, format->precision, "01234567"));
	return (NULL);
}

char	*int_format(va_list ap, t_formaitem *format)
{
	char		*ret;

	if (format->format == 'p')
		format->format = 'x';
	if (format->precision != -1)
		format->flags = format->flags & 0xFDFF;
	else if (format->precision == -1 && format->flags & 512)
		format->precision = format->min_size;
	ret = (format->flags & 64) ? unsigned_format(ap, format)
		: signed_format(ap, format);
	if (!(format->flags & 64) && ret[0] != '-')
	{
		if (format->flags & 2048)
			ret = ft_strfreejoin(ft_strdup("+"), ret);
		else if (format->flags & 4096)
			ret = ft_strfreejoin(ft_strdup(" "), ret);
	}
	if (ret[0] != '0' && format->flags & 256
			&& (format->format == 'o' || format->format == 'O'))
		ret = ft_strfreejoin(ft_strdup("0"), ret);
	if (format->flags & 256 && (format->format == 'x'))
		ret = ft_strfreejoin(ft_strdup("0x"), ret);
	if (format->flags & 256 && (format->format == 'X'))
		ret = ft_strfreejoin(ft_strdup("0X"), ret);
	return (ret);
}
