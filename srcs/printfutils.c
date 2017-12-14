/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printfutils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lowczarc <lowczarc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/01 16:21:42 by lowczarc          #+#    #+#             */
/*   Updated: 2017/12/14 22:12:35 by lowczarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

char	*ft_readformat(char **str, t_formaitem format, va_list ap)
{
	char	*(*f)(va_list, t_formaitem*);
	char	*ret;
	char	*tmp;

	format.format = **str;
	f = ft_fonctformat(format.format, &format);
	(*str)++;
	ret = f(ap, &format);
	if (ft_strlen(ret) < (size_t)format.min_size)
	{
		tmp = ft_strnew(format.min_size - ft_strlen(ret));
		ft_memset(tmp,
				(((format.flags & 512) && !(format.flags & 1024)) ? '0' : ' '),
				format.min_size - ft_strlen(ret));
		if (format.flags & 1024)
			ret = ft_strfreejoin(ret, tmp);
		else
			ret = ft_strfreejoin(tmp, ret);
	}
	return (ret);
}

char	*ft_readflags(char **str, va_list ap)
{
	t_formaitem	format;
	int	tmp;

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
	char	*tmp;
	int		ret;

	va_start(ap, format);
	ret = 0;
	while (*format)
	{
		if (*format != '%')
		{
			ft_putchar(*format);
			ret++;
			format++;
		}
		else
		{
			format++;
			tmp = ft_readflags(&format, ap);
			ret += ft_strlen(tmp);
			ft_putstr(tmp);
		}
	}
	va_end(ap);
	return (ret);
}
