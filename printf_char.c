/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_char.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lowczarc <lowczarc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/02 20:54:24 by lowczarc          #+#    #+#             */
/*   Updated: 2017/12/04 17:49:35 by lowczarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <string.h>

char	*char_format(va_list ap, t_formaitem format)
{
	char *ret;

	if (!(format.flags & 4))
	{
		ret = ft_memalloc(2);
		ret[0] = va_arg(ap, int);
		return (ret);
	}
	return (NULL);
}
