/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_string.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lowczarc <lowczarc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/02 20:35:16 by lowczarc          #+#    #+#             */
/*   Updated: 2017/12/24 16:06:59 by lowczarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "ft_printf.h"

char	*string_format(va_list ap, t_formaitem *format, int *size)
{
	char	*ret;

	if (!(format->flags & 4))
		ret = ft_strdup(va_arg(ap, char*));
	else
		ret = wstr_to_str(va_arg(ap, wchar_t*));
	if (ret == (void*)-1)
		return (NULL);
	if (ret == NULL)
		return (ft_strdup("(null)"));
	if (format->precision != -1)
	{
		ret = ft_strsub(ret, 0, format->precision);
	}
	*size = ft_strlen(ret);
	return (ret);
}
