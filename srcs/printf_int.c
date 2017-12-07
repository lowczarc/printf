/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_int.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lowczarc <lowczarc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/02 20:48:16 by lowczarc          #+#    #+#             */
/*   Updated: 2017/12/07 21:57:37 by lowczarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "ft_printf.h"

char	*signed_format(va_list ap, t_formaitem *format)
{
	long long int	nbr;

	nbr = va_arg(ap, long long int);
	if (format->flags & 1)
		nbr = (char)nbr;
	else if (format->flags & 2)
		nbr = (short)nbr;
	else if (format->flags & 4)
		nbr = (long int)nbr;
	else if (!(format->flags & 8))
		nbr = (int)nbr;
	return (ft_llitoa(nbr));
}

char	*unsigned_format(va_list ap, t_formaitem *format)
{
	if (format->flags & 1)
		return (ft_llutoa((unsigned char)va_arg(ap, int)));
	else if (format->flags & 2)
		return (ft_llutoa((unsigned short)va_arg(ap, int)));
	else if (format->flags & 4)
		return (ft_llutoa(va_arg(ap, unsigned long int)));
	else if (format->flags & 8)
		return (ft_llutoa(va_arg(ap, unsigned long long int)));
	else
		return (ft_llutoa(va_arg(ap, int)));
}

char	*int_format(va_list ap, t_formaitem *format)
{
	char		*ret;

		ret = (format->flags & 64) ? unsigned_format(ap, format)
			: signed_format(ap, format);
	return (ret);
}
