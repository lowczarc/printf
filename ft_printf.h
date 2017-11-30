/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lowczarc <lowczarc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/30 22:15:24 by lowczarc          #+#    #+#             */
/*   Updated: 2017/11/30 23:21:42 by lowczarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#	ifndef	FT_PRINTF_H
#	define FT_PRINTF_H

typedef	struct	s_format
{
	char 			c;
	char			*(*fonct)(void*, short);
	unsigned int	flag;
}				t_format;

typedef	struct	s_flags
{
	char			*str;
	unsigned int	flag;
}				t_flags;

/*
 * A SUPPRIMER !!!!!!!!!!!!!!!!!!
 * 1 = hh
 * 2 = h
 * 4 = l
 * 8 = ll
 * 16 = j
 * 32 = z
 * 64 = u
 * 128 = upcase
 * 256 = #
 * 512 = 0
 * 1024 = -
 * 2048 = +
 * 4096 = ' '
 */

t_flags		g_modifier[] =
{
	{"hh", 1},
	{"h", 2},
	{"ll", 8},
	{"l", 4},
	{"j", 16},
	{"z", 32},
	{NULL, 0}
};

t_flags		g_flag[] =
{
	{"#", 256},
	{"0", 512},
	{"-", 1024},
	{"+", 2048},
	{" ", 4096},
	{NULL, 0}
};

t_format	g_format[] = 
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

#	endif
