/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printfutils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lowczarc <lowczarc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/01 16:21:42 by lowczarc          #+#    #+#             */
/*   Updated: 2017/12/03 16:48:30 by lowczarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_readformat(char **str, t_formatitem format, va_list ap)
{
	char	*(*f)(va_list, unsigned int);

	format.format = **str;
	(*str)++;
	f = ft_fonctformat(format.format);
	printf("\nFlags : %#x, min_size : %d, precision : %d, format : %c\n", format.flags, format.min_size, format.precision, format.format);
	return (ft_strdup("tst"));
}

char	*ft_readflags(char **str, va_list ap)
{
	t_formatitem	format;
	int	tmp;

	format.precision = 1;
	format.min_size = 0;
	format.flags = 0;
	while (tmp = ft_flag(str))
		format.flags = format.flags | tmp;
	if (ft_isdigit(**str))
		format.min_size = ft_atoi(*str);
	while (ft_isdigit(**str))
		(*str)++;
	if (**str == '.')
	{
		(*str)++;
		format.precision = ft_atoi(*str);
		while (ft_isdigit(**str))
			(*str)++;
	}
	format.flags = format.flags | ft_modifier(str);
	return (ft_readformat(str, format, ap));
}

int	ft_printf(char *format, ...)
{
	va_list ap;
	char	*tmp;
	int		ret;

	va_start(ap, format);
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

int	main(void)
{
	ft_printf("test ! bonjour ! %s ! les carottes sont cuites ! %0-0 54.58lld\n", "test", 8);
	return (0);
}
