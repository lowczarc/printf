/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags_detect.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lowczarc <lowczarc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/30 23:16:20 by lowczarc          #+#    #+#             */
/*   Updated: 2017/12/03 16:38:18 by lowczarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

const t_flags		g_modifier[] =
{
	{"hh", 1},
	{"h", 2},
	{"ll", 8},
	{"l", 4},
	{"j", 16},
	{"z", 32},
	{NULL, 0}
};

const t_flags		g_flag[] =
{
	{"#", 256},
	{"0", 512},
	{"-", 1024},
	{"+", 2048},
	{" ", 4096},
	{NULL, 0}
};

const t_format	g_format[] =
{
	{'s', &string_format, 0},
	{'S', &string_format, 4},
	{'s', &string_format, 0},
	{'p', &pointer_format, 0},
	{'d', &int_format, 0},
	{'D', &int_format, 4},
	{'i', &int_format, 0},
	{'o', &octal_format, 0},
	{'O', &octal_format, 4},
	{'u', &int_format, 64},
	{'U', &int_format, 68},
	{'x', &hexa_format, 0},
	{'X', &hexa_format, 128},
	{'c', &char_format, 0},
	{'C', &char_format, 4},
	{'%', &pourcent_format, 0},
	{0, NULL}
};

int		ft_modifier(char **str)
{
	int	i;
	int	j;

	i = 0;
	while (g_modifier[i].str)
	{
		j = 0;
		while (g_modifier[i].str[j] && g_modifier[i].str[j] == (*str)[j])
			j++;
		if (!g_modifier[i].str[j])
		{
			*str = &(*str)[j];
			return (g_modifier[i].flag);
		}
		i++;
	}
	return (0);
}

int		ft_flag(char **str)
{
	int	i;
	int	j;

	i = 0;
	while (g_flag[i].str)
	{
		j = 0;
		while (g_flag[i].str[j] && g_flag[i].str[j] == (*str)[j])
			j++;
		if (!g_flag[i].str[j])
		{
			*str = &(*str)[j];
			return (g_flag[i].flag);
		}
		i++;
	}
	return (0);
}

int		ft_isformat(char c)
{
	int	i;

	i = 0;
	while (g_format[i].c)
	{
		if (g_format[i].c == c)
			return (1);
		i++;
	}
	return (0);
}

void	*ft_fonctformat(char c)
{
	int	i;

	i = 0;
	while (g_format[i].c)
	{
		if (g_format[i].c == c)
			return (g_format[i].fonct);
		i++;
	}
	return (NULL);
}
