/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lltoa.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lowczarc <lowczarc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/07 20:52:30 by lowczarc          #+#    #+#             */
/*   Updated: 2017/12/08 16:20:27 by lowczarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	size_llutoa(unsigned long long int n)
{
	unsigned long long int	ret;

	ret = 0;
	while (n >= 10)
	{
		ret++;
		n /= 10;
	}
	ret++;
	return (ret);
}

static void	ft_putinstr(char *s, unsigned long long n, int size)
{
	while (size > 0)
	{
		size--;
		s[size] = (n % 10) + '0';
		n = n / 10;
	}
}

char		*ft_llutoa(unsigned long long int n, int size)
{
	char	*ret;

	if (size < size_llutoa(n))
		size = size_llutoa(n);
	ret = malloc(sizeof(char) * (size + 1));
	if (ret == NULL)
		return (NULL);
	ft_putinstr(ret, n, size);
	ret[size] = 0;
	return (ret);
}

char		*ft_llitoa(long long int n, int size)
{
	char	*tmp;
	char	*ret;

	tmp = ft_llutoa((n < 0) ? -n : n, size);
	ret = (n < 0) ? ft_strjoin("-", tmp) : ft_strdup(tmp);
	free(tmp);
	return (ret);
}
