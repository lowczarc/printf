/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lowczarc <lowczarc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/04 16:47:08 by lowczarc          #+#    #+#             */
/*   Updated: 2017/12/04 17:11:17 by lowczarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include "libft.h"

typedef struct		s_formaitem
{
	char			format;
	int				flags;
	int				precision;
	int				min_size;
}					t_formaitem;

typedef	struct		s_format
{
	char			c;
	char			*(*fonct)();
	unsigned int	flag;
}					t_format;

typedef	struct		s_flags
{
	char			*str;
	unsigned int	flag;
}					t_flags;

int					ft_modifier(char **str);
int					ft_flag(char **str);
int					ft_isformat(char c);
void				*ft_fonctformat(char c);
char				*string_format(va_list ap, t_formaitem format);
char				*pointer_format(va_list ap, t_formaitem format);
char				*int_format(va_list ap, t_formaitem format);
char				*octal_format(va_list ap, t_formaitem format);
char				*hexa_format(va_list ap, t_formaitem format);
char				*char_format(va_list ap, t_formaitem format);
char				*pourcent_format(va_list ap, t_formaitem format);

#endif
