/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstrfinalc.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lowczarc <lowczarc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/09 13:21:20 by lowczarc          #+#    #+#             */
/*   Updated: 2018/01/09 13:36:17 by lowczarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_putstrfinalc(char *str, char c)
{
	size_t		len;

	len = ft_strlenc(str, c);
	write(1, str, len);
	return (len);
}
