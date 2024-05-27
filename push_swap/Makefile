# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jsamardz <jsamardz@student.42heilnronn.    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/29 11:39:03 by jsamardz          #+#    #+#              #
#    Updated: 2024/05/27 12:45:05 by jsamardz         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CFLAGS = -Wall -Werror -Wextra -Iinclude
SRC_DIR = src
OBJ_DIR = obj
SRC_FILES = main.c ft_input.c ft_handling.c stacks.c push_swap.c rotate.c swap.c push.c r_rotate.c ft_algorithm.c target.c cost.c moves.c
SRC = $(addprefix $(SRC_DIR)/,$(SRC_FILES))
OBJ = $(patsubst $(SRC_DIR)/%.c,$(OBJ_DIR)/%.o,$(SRC))
NAME = push_swap
RM = rm -f

all: $(NAME)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(OBJ_DIR)
	@cc $(CFLAGS) -Ilibft -Iprintf -c $< -o $@

$(NAME): $(OBJ)
	@make -C libft
	@make -C printf
	@cc $(CFLAGS) $^ -Llibft -lft -Lprintf -lftprintf -o $@

libft:
	@make -C libft

printf:
	@make -C printf

clean:
	@echo "clean"
	@make clean -C libft
	@make clean -C printf
	@$(RM) -r $(OBJ_DIR)

fclean:
	@make clean
	@echo "fclean"
	@$(RM) push_swap

re: fclean all

.PHONY: libft printf clean fclean re