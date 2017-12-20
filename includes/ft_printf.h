/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lowczarc <lowczarc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/04 16:47:08 by lowczarc          #+#    #+#             */
/*   Updated: 2017/12/20 15:07:28 by lowczarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <inttypes.h>
# include <wchar.h>
# include "../libft/libft.h"

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
void				*ft_fonctformat(char c, t_formaitem *format);
char				*string_format(va_list ap, t_formaitem *format);
char				*pointer_format(va_list ap, t_formaitem *format);
char				*int_format(va_list ap, t_formaitem *format);
char				*octal_format(va_list ap, t_formaitem *format);
char				*hexa_format(va_list ap, t_formaitem *format);
char				*wstr_to_str(wchar_t *str);
char				*wchar_to_str(wchar_t c);
size_t				ft_wstrlen(wchar_t *str);
char				*char_format(va_list ap, t_formaitem *format);
char				*pourcent_format(va_list ap, t_formaitem *format);
int					ft_printf(char *format, ...);
char				*ft_strfreejoin(char *s1, char *s2);
char				*ft_llitoa(long long int n, t_formaitem *format);
char 				*ft_llutoa(unsigned long long int n, int size);
char 				*ft_llxtoa(unsigned long long int n, int size, char *base);

#endif
