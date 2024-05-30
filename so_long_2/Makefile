# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jsamardz <jsamardz@student.42heilnronn.    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/29 11:47:19 by jsamardz          #+#    #+#              #
#    Updated: 2024/05/30 14:05:12 by jsamardz         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long
CC = gcc
CFLAGS = 
SRC = $(addprefix src/, main.c ft_maps.c map_check.c)
OBJ = $(SRC:.c=.o)
MLX_PATH = mlx
MLX_LIB = -L$(MLX_PATH) -lmlx -framework OpenGL -framework AppKit
LIBFT_PATH = libft
LIBFT_H = -L$(LIBFT_PATH) -lft
PRINTF_PATH = printf
PRINTF_H = -L$(PRINTF_PATH) -lftprintf
INCLUDES = -I$(MLX_PATH) -Iinclude -I$(LIBFT_PATH) -I$(PRINTF_PATH)

%.o: %.c
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(NAME): $(OBJ)
	@echo "make"
	@make -C mlx
	@make -C libft
	@make -C printf
	@$(CC) $(OBJ) $(MLX_LIB) $(LIBFT_H) $(PRINTF_H) -o $(NAME)

clean:
	@echo "clean"
	@make clean -C libft
	@make clean -C printf
	@rm -f $(OBJ)

fclean: clean
	@echo "fclean"
	@rm -f $(NAME)

re: fclean all

all: $(NAME)

.PHONY: all clean fclean re
