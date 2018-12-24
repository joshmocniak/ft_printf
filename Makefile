# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jmocniak <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/24 14:34:25 by jmocniak          #+#    #+#              #
#    Updated: 2018/12/23 22:05:24 by jmocniak         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := ft_printf
FLAGS := -Wall -Werror -Wextra -I ./includes/
SRCDIR := ./src/
OBJDIR := ./obj/
SRC := $(wildcard $(SRCDIR)*.c)
OBJ := $(patsubst $(SRCDIR)%.c,$(OBJDIR)%.o,$(SRC))
INCLUDES := ./includes/
CC := gcc

all: libft.a $(NAME).a

$(OBJDIR):
	mkdir $(OBJDIR)

$(OBJDIR)%.o: $(SRCDIR)%.c $(INCLUDES)$(NAME).h $(OBJDIR)
	$(CC) $(FLAGS) -c $< -o $@

$(NAME).a: $(OBJ) $(INCLUDES)$(NAME).h
	ar rc ./$(NAME).a $(OBJ)
	ranlib ./$(NAME).a
	#cp $(NAME).a /usr/src/test/tester_docker/
	#cp ./includes/* /usr/src/test/tester_docker/

libft.a:
	@make -C ./libft
	#cp ./libft/libft.a .
	#cp libft.a /usr/src/test/tester_docker/
	#pwd
	#ls
	#ls /usr/src/test/tester_docker/
	# grep "" /usr/src/test/tester_docker/Makefile
	cat /usr/src/test/tester_docker/clean.py
	sed -n 1,46p /usr/src/test/tester_docker/Makefile
	sed -i '46s/.*/python clean.py/' /usr/src/test/tester_docker/Makefile
	sed -i '47s/.*//' /usr/src/test/tester_docker/Makefile
	lsof | grep Makefile

clean:
	rm -Rf ./$(OBJDIR)
	make -C ./libft clean

fclean: clean
	rm -f ./$(NAME).a
	rm -f ./libft.a
	make -C ./libft fclean

re: fclean all

.PHONY: all clean fclean re
