# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jmocniak <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/24 14:34:25 by jmocniak          #+#    #+#              #
#    Updated: 2018/12/27 22:54:36 by jmocniak         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := libftprintf
FLAGS := -Wall -Werror -Wextra -I ./includes/
SRCDIR := ./src/
OBJDIR := ./obj/
SRC := $(wildcard $(SRCDIR)*.c)
OBJ := $(patsubst $(SRCDIR)%.c,$(OBJDIR)%.o,$(SRC))
OBJLIBFT := $(wildcard ./libft/*.o)
INCLUDES := ./includes/
CC := gcc

all: $(NAME).a

$(OBJDIR):
	mkdir $(OBJDIR)

$(OBJDIR)%.o: $(SRCDIR)%.c $(INCLUDES)ft_printf.h $(INCLUDES)libft.h $(OBJDIR)
	$(CC) $(FLAGS) -c $< -o $@

$(NAME).a: $(OBJ) $(INCLUDES)ft_printf.h $(INCLUDES)libft.h
	ar rc ./$(NAME).a $(OBJ) $(OBJLIBFT)
	ranlib ./$(NAME).a

libft.a:
	@make -C ./libft

clean:
	rm -Rf ./$(OBJDIR)
	make -C ./libft clean

fclean: clean
	rm -f ./$(NAME).a
	make -C ./libft fclean

re: fclean all

.PHONY: all clean fclean re
