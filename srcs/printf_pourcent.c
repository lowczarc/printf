/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_pourcent.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lowczarc <lowczarc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/02 20:50:08 by lowczarc          #+#    #+#             */
/*   Updated: 2017/12/04 21:25:43 by lowczarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "ft_printf.h"

char	*pourcent_format(va_list ap, t_formaitem *format)
{
	char	*ret;

	(void)ap;
	ret = ft_memalloc(2);
	ret[0] = format->format;
	return (ret);
}
