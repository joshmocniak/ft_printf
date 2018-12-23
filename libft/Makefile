# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jmocniak <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/02/19 15:49:46 by jmocniak          #+#    #+#              #
#    Updated: 2018/06/22 17:59:04 by jmocniak         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := libft.a

SRC := ft_atoi ft_bzero ft_isalnum ft_isalpha ft_isascii ft_isdigit ft_isprint ft_memalloc ft_memccpy ft_memchr ft_memcmp ft_memcpy ft_memmove ft_memset ft_strcat ft_strchr ft_strcmp ft_strcpy ft_strdup ft_strlcat ft_strlen ft_strncat ft_strncmp ft_strncpy ft_strnstr ft_strrchr ft_strstr ft_tolower ft_toupper ft_memdel ft_strnew ft_strdel ft_strclr ft_striter ft_striteri ft_strmap ft_strmapi ft_strequ ft_strnequ ft_strsub ft_strjoin ft_strtrim ft_strsplit ft_itoa ft_putchar ft_putstr ft_putendl ft_putnbr ft_putchar_fd ft_putstr_fd ft_putendl_fd ft_putnbr_fd ft_lstnew ft_lstdelone ft_lstdel ft_lstadd ft_lstiter ft_lstmap ft_isupper ft_islower ft_strcontains ft_replacechar ft_isspace ft_wordcount get_next_line

FLAGS := -Wall -Werror -Wextra

CC := gcc

HEADER := libft.h

all: $(NAME)

%.o: %.c $(HEADER)
	$(CC) $(FLAGS) -c $< -o $@

get_next_line.o: get_next_line.h

$(NAME): $(addsuffix .o, $(SRC))
	ar rc $(NAME) $(addsuffix .o, $(SRC))
	ranlib $(NAME)

clean:
	/bin/rm -f $(addsuffix .o, $(SRC))

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all
