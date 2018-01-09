# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lowczarc <lowczarc@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/12/04 21:27:41 by lowczarc          #+#    #+#              #
#    Updated: 2018/01/09 16:08:35 by lowczarc         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=libftprintf.a
SRCSPATH=srcs
INCLUDEPATH=includes

OBJ=printfutils.o flags_detect.o printf_char.o printf_int.o printf_pourcent.o \
	printf_string.o ft_wstr.o ft_lltoa.o ft_llxtoa.o ft_strfreejoin.o \
	ft_strlenc.o ft_putstrfinalc.o printf_float.o\
	ft_memset.o ft_bzero.o ft_memcpy.o ft_memmove.o ft_memchr.o ft_memcmp.o \
	ft_strlen.o ft_strdup.o ft_memccpy.o ft_strcpy.o ft_strncpy.o \
	ft_strcat.o ft_strncat.o ft_strlcat.o ft_strchr.o ft_strrchr.o \
	ft_strstr.o ft_strnstr.o ft_strcmp.o ft_strncmp.o ft_atoi.o \
	ft_isalpha.o ft_isdigit.o ft_isalnum.o ft_isascii.o ft_isprint.o \
	ft_toupper.o ft_tolower.o ft_memalloc.o ft_memdel.o ft_strnew.o \
	ft_strdel.o ft_strclr.o ft_striter.o ft_striteri.o ft_strmap.o \
	ft_strmapi.o ft_strequ.o ft_strnequ.o ft_strsub.o ft_strjoin.o \
	ft_strtrim.o ft_strsplit.o ft_itoa.o ft_putchar.o ft_putstr.o \
	ft_putendl.o ft_putnbr.o ft_putchar_fd.o ft_putstr_fd.o ft_putendl_fd.o \
	ft_putnbr_fd.o ft_lstnew.o ft_lstdelone.o ft_lstdel.o ft_lstadd.o \
	ft_lstiter.o ft_lstmap.o

FLAGS= -Wall -Wextra -Werror -I $(INCLUDEPATH)

RED=\033[31m
GREEN=\033[32m
EOC=\033[0m

all: $(NAME)

$(NAME):$(OBJ)
	ar rc $(NAME) $(LOBJ) $(OBJ) 
	ranlib $(NAME)

%.o: $(SRCSPATH)/%.c
	gcc -o $@ -c $< $(FLAGS)

.PHONY: fclean all clean re

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
