# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jmocniak <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/24 14:34:25 by jmocniak          #+#    #+#              #
#    Updated: 2018/12/23 15:41:42 by jmocniak         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := ft_printf

FLAGS := -Wall -Werror -Wextra -I ./includes/

SRCDIR := ./src/

OBJDIR := ./obj/

SRC := $(wildcard $(SRCDIR)*.c)

OBJ := $(patsubst $(SRCDIR)%.c,$(OBJDIR)%.o,$(SRC))

INCLUDES := ./includes/


all: $(NAME).a libft.a

$(OBJDIR):
	mkdir $(OBJDIR)

$(OBJDIR)%.o: $(SRCDIR)%.c $(INCLUDES)$(NAME).h $(OBJDIR)
	$(CC) $(FLAGS) -c $<  -o $@

$(NAME).a: $(OBJ) $(INCLUDES)$(NAME).h
	ar rc $(NAME).a $(OBJ)
	ranlib $(NAME).a

libft.a:
	@make -C libft
	cp libft/libft.a .

clean:
	rm -Rf $(OBJDIR)
	make -C libft clean

fclean: clean
	rm -f $(NAME).a
	rm -f libft.a
	make -C libft fclean

re: fclean all

.PHONY: all clean fclean re
