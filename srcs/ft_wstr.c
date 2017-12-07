/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wstr.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lowczarc <lowczarc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/07 15:47:39 by lowczarc          #+#    #+#             */
/*   Updated: 2017/12/07 19:27:07 by lowczarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "ft_printf.h"

char	*wstr_to_str(wchar_t *str)
{
	char	*ret;
	int		i;
	
	if (!str)
		return (NULL);
	if (!(ret = ft_strnew(ft_wstrlen(str))))
		return (NULL);
	i = 0;
	while (str[i])
	{
		ret[i] = str[i];
		i++;
	}
	return (ret);
}

size_t	ft_wstrlen(wchar_t *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}
