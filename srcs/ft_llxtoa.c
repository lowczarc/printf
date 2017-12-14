/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_llxtoa.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lowczarc <lowczarc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/14 21:37:17 by lowczarc          #+#    #+#             */
/*   Updated: 2017/12/14 22:07:58 by lowczarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	size_llxtoa(unsigned long long int n, char *base)
{
	unsigned long long int	ret;

	ret = 0;
	while (n >= ft_strlen(base))
	{
		ret++;
		n /= ft_strlen(base);
	}
	ret++;
	return (ret);
}

static void	ft_putinstr(char *s, unsigned long long n, int size, char *base)
{
	while (size > 0)
	{
		size--;
		s[size] = base[(n % ft_strlen(base))];
		n = n / ft_strlen(base);
	}
}

char		*ft_llxtoa(unsigned long long int n, int size, char *base)
{
	char	*ret;

	if (size < size_llxtoa(n, base))
		size = size_llxtoa(n, base);
	ret = malloc(sizeof(char) * (size + 1));
	if (ret == NULL)
		return (NULL);
	ft_putinstr(ret, n, size, base);
	ret[size] = 0;
	return (ret);
}
