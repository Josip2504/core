# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jsamardz <jsamardz@student.42heilnronn.    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/29 11:39:03 by jsamardz          #+#    #+#              #
#    Updated: 2024/04/30 13:17:42 by jsamardz         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CFALGS = -Wall -Werror -Wextra
SRC = main.c ft_input.c
OBJ = $(SRC:.c=.o)
NAME = push_swap
RM = rm -f

all: $(NAME)

%.o: %.cc
	@cc $(CFALGS) -Ilibft -Iprintf -c $? -o $@

$(NAME): $(OBJ)
	@make -C libft
	@make -C printf
	@cc $(CFALGS) $^ -Llibft -lft -Lprintf -lftprintf -o $@

libft:
	@make -C libft

printf:
	@make -C printf

clean:
	@echo "clean"
	@make clean -C libft
	@make clean -C printf
	@$(RM) $(OBJ)

fclean:
	@echo "fclean"
	@$(RM) push_swap

re: fclean all

.PHONY: libft printf