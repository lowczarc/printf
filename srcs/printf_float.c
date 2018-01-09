/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_float.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lowczarc <lowczarc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/09 15:34:06 by lowczarc          #+#    #+#             */
/*   Updated: 2018/01/09 16:09:13 by lowczarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_floatoa(double f, t_formaitem *format)
{
	int		size;
	char	*ret;

	size = (format->precision == -1) ? 6 : format->precision;
	format->precision = -1;
	ret = ft_llitoa((int)f, format);
	if (size)
		ret = ft_strfreejoin(ret, ft_strdup("."));
	while (size--)
	{
		f = (f - (int)f) * 10;
		ret = ft_strfreejoin(ret, ft_llutoa((int)f, 1));
	}
	return (ret);
}

char	*float_format(va_list ap, t_formaitem *format, int *size)
{
	char		*ret;

	ret = ft_floatoa(va_arg(ap, double), format);
	if (ret[0] != '-')
	{
		if (format->flags & 2048)
			ret = ft_strfreejoin(ft_strdup("+"), ret);
		else if (format->flags & 4096)
			ret = ft_strfreejoin(ft_strdup(" "), ret);
	}
	*size = ft_strlen(ret);
	return (ret);
}
