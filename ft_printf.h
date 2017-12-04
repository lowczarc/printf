/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lowczarc <lowczarc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/30 22:15:24 by lowczarc          #+#    #+#             */
/*   Updated: 2017/12/03 16:47:32 by lowczarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#	ifndef FT_PRINTF_H
#	define FT_PRINTF_H
#	include <stdarg.h>
#	include "libft.h"

typedef struct	s_formatitem
{
	char			format;
	int				flags;
	int				precision;
	int				min_size;
}				t_formatitem;

typedef	struct	s_format
{
	char			c;
	char			*(*fonct)(va_list, t_formatitem);
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

int		ft_modifier(char **str);
int		ft_flag(char **str);
int		ft_isformat(char c);
void	*ft_fonctformat(char c);
char	*string_format(va_list ap, t_formatitem format);
char	*pointer_format(va_list ap, t_formatitem format);
char	*int_format(va_list ap, t_formatitem format);
char	*octal_format(va_list ap, t_formatitem format);
char	*hexa_format(va_list ap, t_formatitem format);
char	*char_format(va_list ap, t_formatitem format);
char	*pourcent_format(va_list ap, t_formatitem format);

#	endif
