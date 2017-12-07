/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lltoa.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lowczarc <lowczarc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/07 20:52:30 by lowczarc          #+#    #+#             */
/*   Updated: 2017/12/07 21:35:28 by lowczarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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

static int	ft_putinstr(char *s, int n)
{
	if (n == 0)
		return (0);
	ft_putinstr(s - 1, n / 10);
	*s = (n % 10) + '0';
	return (n);
}

char		*ft_llutoa(unsigned long long int n)
{
	char	*ret;

	ret = malloc(sizeof(char) * (size_llutoa(n) + 1));
	if (ret == NULL)
		return (NULL);
	ret[size_llutoa(n) + 1] = 0;
	ft_putinstr(&ret[size_llutoa(n) - 1], n);
	ret[size_llutoa(n)] = 0;
	return (ret);
}

char		*ft_llitoa(long long int n)
{
	char	*tmp;
	char	*ret;

	tmp = ft_llutoa((n < 0) ? -n : n);
	ret = (n < 0) ? ft_strjoin("-", tmp) : ft_strdup(tmp);
	free(tmp);
	return (ret);
}
