/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_string.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lowczarc <lowczarc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/02 20:35:16 by lowczarc          #+#    #+#             */
/*   Updated: 2017/12/08 15:46:50 by lowczarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "ft_printf.h"

char	*string_format(va_list ap, t_formaitem *format)
{
	char	*ret;

	if (!(format->flags & 4))
		ret = va_arg(ap, char*);
	else
		ret = wstr_to_str(va_arg(ap, wchar_t*));
	if (ret == NULL)
		return (ft_strdup("(null)"));
	if (format->precision != -1)
	{
		ret = ft_strsub(ret, 0, format->precision);
	}
	return (ret);
}
