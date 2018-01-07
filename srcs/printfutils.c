/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printfutils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lowczarc <lowczarc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/01 16:21:42 by lowczarc          #+#    #+#             */
/*   Updated: 2018/01/02 21:24:11 by lowczarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>


int		ft_readformat(char **str, t_formaitem format, va_list ap)
{
	char	*(*f)(va_list, t_formaitem*, int*);
	char	*ret;
	char	*tmp;
	int		size;

	format.format = **str;
	f = ft_fonctformat(format.format, &format);
	(*str)++;
	if (!(ret = f(ap, &format, &size)))
		return (-1);
	if (size < format.min_size)
	{
		tmp = ft_strnew(format.min_size - size);
		ft_memset(tmp,
				(((format.flags & 512) && !(format.flags & 1024)) ? '0' : ' '),
				format.min_size - size);
		if (format.flags & 1024)
			ret = ft_strnjoin(ret, tmp, size, ft_strlen(tmp));
		else
			ret = ft_strnjoin(tmp, ret, ft_strlen(tmp), size);
		size = format.min_size;
	}
	ft_putnstr(ret, size);
	return (size);
}

int		ft_readflags(char **str, va_list ap)
{
	t_formaitem	format;
	int			tmp;

	format.precision = -1;
	format.min_size = 0;
	format.flags = 0;
	while ((tmp = ft_flag(str)))
		format.flags = format.flags | tmp;
	if (ft_isdigit(**str))
		format.min_size = ft_atoi(*str);
	else if (**str == '*')
		format.min_size = va_arg(ap, int);
	while (ft_isdigit(**str) || **str == '*')
		(*str)++;
	if (**str == '.')
	{
		(*str)++;
		format.precision = ft_atoi(*str);
		if (**str == '*')
			format.precision = va_arg(ap, int);
		while (ft_isdigit(**str) || **str == '*')
			(*str)++;
	}
	format.flags = format.flags | ft_modifier(str);
	return (ft_readformat(str, format, ap));
}

int		ft_printf(char *format, ...)
{
	va_list ap;
	int		size;
	int		tmp;

	va_start(ap, format);
	while (*format)
	{
		if (*format != '%')
		{
			ft_putchar(*format);
			size++;
			format++;
		}
		else
		{
			format++;
			tmp = ft_readflags(&format, ap);
			if (tmp == -1)
				return (-1);
			size += tmp;
		}
	}
	va_end(ap);
	return (size);
}
