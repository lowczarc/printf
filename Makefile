# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lowczarc <lowczarc@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/12/04 21:27:41 by lowczarc          #+#    #+#              #
#    Updated: 2017/12/04 22:19:15 by lowczarc         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=libftprintf.a
SRCSPATH=srcs
INCLUDEPATH=includes
LIBPATH=libft

OBJ= printfutils.o flags_detect.o printf_char.o printf_octal.o printf_int.o \
	 printf_hexa.o printf_pointer.o printf_pourcent.o printf_string.o

LOBJ = $(LIBPATH)/ft_memset.o $(LIBPATH)/ft_bzero.o $(LIBPATH)/ft_memcpy.o \
	   $(LIBPATH)/ft_memmove.o $(LIBPATH)/ft_memchr.o $(LIBPATH)/ft_memcmp.o \
	   $(LIBPATH)/ft_strlen.o $(LIBPATH)/ft_strdup.o $(LIBPATH)/ft_memccpy.o \
	   $(LIBPATH)/ft_strcpy.o $(LIBPATH)/ft_strncpy.o $(LIBPATH)/ft_strcat.o \
	   $(LIBPATH)/ft_strncat.o $(LIBPATH)/ft_strlcat.o $(LIBPATH)/ft_strchr.o \
	   $(LIBPATH)/ft_strrchr.o $(LIBPATH)/ft_strstr.o $(LIBPATH)/ft_strnstr.o \
	   $(LIBPATH)/ft_strcmp.o $(LIBPATH)/ft_strncmp.o $(LIBPATH)/ft_atoi.o \
	   $(LIBPATH)/ft_isalpha.o $(LIBPATH)/ft_isdigit.o $(LIBPATH)/ft_isalnum.o \
	   $(LIBPATH)/ft_isascii.o $(LIBPATH)/ft_isprint.o $(LIBPATH)/ft_toupper.o \
	   $(LIBPATH)/ft_tolower.o $(LIBPATH)/ft_memalloc.o $(LIBPATH)/ft_memdel.o \
	   $(LIBPATH)/ft_strnew.o $(LIBPATH)/ft_strdel.o $(LIBPATH)/ft_strclr.o \
	   $(LIBPATH)/ft_striter.o $(LIBPATH)/ft_striteri.o $(LIBPATH)/ft_strmap.o \
	   $(LIBPATH)/ft_strmapi.o $(LIBPATH)/ft_strequ.o $(LIBPATH)/ft_strnequ.o \
	   $(LIBPATH)/ft_strsub.o $(LIBPATH)/ft_strjoin.o $(LIBPATH)/ft_strtrim.o \
	   $(LIBPATH)/ft_strsplit.o $(LIBPATH)/ft_itoa.o $(LIBPATH)/ft_putchar.o \
	   $(LIBPATH)/ft_putstr.o $(LIBPATH)/ft_putendl.o $(LIBPATH)/ft_putnbr.o \
	   $(LIBPATH)/ft_putchar_fd.o $(LIBPATH)/ft_putstr_fd.o \
	   $(LIBPATH)/ft_putendl_fd.o $(LIBPATH)/ft_putnbr_fd.o \
	   $(LIBPATH)/ft_lstnew.o $(LIBPATH)/ft_lstdelone.o $(LIBPATH)/ft_lstdel.o \
	   $(LIBPATH)/ft_lstadd.o $(LIBPATH)/ft_lstiter.o $(LIBPATH)/ft_lstmap.o

FLAGS= -Wall -Wextra -Werror -I includes -I $(LIBPATH)

RED=\033[31m
GREEN=\033[32m
EOC=\033[0m

all: $(NAME)

$(NAME):$(LOBJ) $(OBJ)
	ar rc $(NAME) $(LOBJ) $(OBJ) 
	ranlib $(NAME)

$(LIBPATH)/%.o: $(LIBPATH)/%.c
	cd $(LIBPATH) && $(MAKE)

%.o: $(SRCSPATH)/%.c
	gcc -o $@ -c $< $(FLAGS)

.PHONY: fclean all clean re

clean:
	rm -f $(OBJ)
	cd $(LIBPATH) && $(MAKE) clean

fclean: clean
	rm -f $(NAME)

re: fclean all
