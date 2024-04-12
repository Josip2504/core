# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jsamardz <jsamardz@student.42heilnronn.    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/11 10:51:35 by jsamardz          #+#    #+#              #
#    Updated: 2024/04/12 09:51:46 by jsamardz         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CFLAGS = -Wall -Werror -Wextra
SRC = server.c client.c
OBJ = $(SRC:.c=.o)
NAME = minitalk
RM = rm -f

all: $(NAME)

%.o: %.cc
	@cc $(CFLAGS) -Ilibft -Iprintf -c $? -o $@

$(NAME): server client

libft:
	@make -C libft

printf:
	@make -C printf

server: server.o
	@make -C libft
	@make -C printf
	@cc $(CFLAGS) $? -Llibft -lft -Lprintf -lftprintf -o server

client:  client.o
	@make -C libft
	@make -C printf
	@cc $(CFLAGS) $? -Llibft -lft -Lprintf -lftprintf -o client


clean:
	@echo "clean"
	@make clean -C libft
	@make clean -C printf
	@$(RM) $(OBJ)

fclean: clean
	@echo "fclean"
	@$(RM) server client

re: fclean all

.PHONY: libft printf