# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jmocniak <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/24 14:34:25 by jmocniak          #+#    #+#              #
#    Updated: 2019/01/05 18:35:12 by jmocniak         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
LIBFT = libft/libft.a
CC = gcc
INC = includes/ft_printf.h \
	  libft/libft.h
FLAGS := -Wall -Werror -Wextra -I includes/ $(INC)
SRC = src/conv_c.c \
	src/conv_d.c \
	src/conv_f.c \
	src/conv_o.c \
	src/conv_p.c \
	src/conv_s.c \
	src/conv_u.c \
	src/conv_x.c \
	src/dtoa.c \
	src/ft_printf.c \
	src/itoa_d.c \
	src/itoa_hex.c \
	src/itoa_octal.c \
	src/itoa_u.c \
	src/lenmod.c

OBJ = conv_c.o \
	conv_d.o \
	conv_f.o \
	conv_o.o \
	conv_p.o \
	conv_s.o \
	conv_u.o \
	conv_x.o \
	dtoa.o \
	ft_printf.o \
	itoa_d.o \
	itoa_hex.o \
	itoa_octal.o \
	itoa_u.o \
	lenmod.o \
	libft/ft_atoi.o \
	libft/ft_bzero.o \
	libft/ft_isalnum.o \
	libft/ft_isalpha.o \
	libft/ft_isascii.o \
	libft/ft_isdigit.o \
	libft/ft_islower.o \
	libft/ft_isprint.o \
	libft/ft_isspace.o \
	libft/ft_isupper.o \
	libft/ft_itoa.o \
	libft/ft_lstadd.o \
	libft/ft_lstdel.o \
	libft/ft_lstdelone.o \
	libft/ft_lstiter.o \
	libft/ft_lstmap.o \
	libft/ft_lstnew.o \
	libft/ft_memalloc.o \
	libft/ft_memccpy.o \
	libft/ft_memchr.o \
	libft/ft_memcmp.o \
	libft/ft_memcpy.o \
	libft/ft_memdel.o \
	libft/ft_memmove.o \
	libft/ft_memset.o \
	libft/ft_putchar.o \
	libft/ft_putchar_fd.o \
	libft/ft_putendl.o \
	libft/ft_putendl_fd.o \
	libft/ft_putnbr.o \
	libft/ft_putnbr_fd.o \
	libft/ft_putstr.o \
	libft/ft_putstr_fd.o \
	libft/ft_replacechar.o \
	libft/ft_strcat.o \
	libft/ft_strchr.o \
	libft/ft_strclr.o \
	libft/ft_strcmp.o \
	libft/ft_strcontains.o \
	libft/ft_strcpy.o \
	libft/ft_strdel.o \
	libft/ft_strdup.o \
	libft/ft_strequ.o \
	libft/ft_striter.o \
	libft/ft_striteri.o \
	libft/ft_strjoin.o \
	libft/ft_strlcat.o \
	libft/ft_strlen.o \
	libft/ft_strmap.o \
	libft/ft_strmapi.o \
	libft/ft_strncat.o \
	libft/ft_strncmp.o \
	libft/ft_strncpy.o \
	libft/ft_strnequ.o \
	libft/ft_strnew.o \
	libft/ft_strnstr.o \
	libft/ft_strrchr.o \
	libft/ft_strsplit.o \
	libft/ft_strstr.o \
	libft/ft_strsub.o \
	libft/ft_strtrim.o \
	libft/ft_tolower.o \
	libft/ft_toupper.o \
	libft/ft_wordcount.o \
	libft/get_next_line.o


all: $(NAME)

$(NAME): $(LIBFT)
	@echo "making libftprintf.a"
	@gcc $(FLAGS) -c $(SRC)
	@ar rc $(NAME) $(OBJ)
	@ranlib $(NAME)

$(LIBFT):
	@echo "making libft"
	@make -C libft

clean:
	-rm -Rf $(OBJ)
	make -C libft clean

fclean: clean
	rm -f $(NAME)
	make -C libft fclean

re: fclean all

.PHONY: all clean fclean re
