/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags_detect.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lowczarc <lowczarc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/30 23:16:20 by lowczarc          #+#    #+#             */
/*   Updated: 2017/11/30 23:35:04 by lowczarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_modifier(char **str)
{
	int	i;
	int	j;

	i = 0;
	while (g_modifier[i]->str)
	{
		j = 0;
		while (g_modifier[i]->str[j] && g_modifier[i]->str[j] == (*str)[j])
			j++;
		if (!g_modifier[i]->str[j])
		{
			*str = &(*str)[j];
			return (g_modifier[i]->flag);
		}
		i++;
	}
	return (0);
}

int	ft_flag(char **str)
{
	int	i;
	int	j;

	i = 0;
	while (g_flag[i]->str)
	{
		j = 0;
		while (g_flag[i]->str[j] && g_flag[i]->str[j] == (*str)[j])
			j++;
		if (!g_flag[i]->str[j])
		{
			*str = &(*str)[j];
			return (g_flag[i]->flag);
		}
		i++;
	}
	return (0);
}

int	ft_isformat(char c)
{
	int	i;

	i = 0;
	while (g_flag[i]->c)
	{
		if (g_flag[i]->c == c)
			return (1);
		i++;
	}
	return (0);
}
