# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jsamardz <jsamardz@student.42heilnronn.    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/09 11:19:38 by jsamardz          #+#    #+#              #
#    Updated: 2024/04/09 11:53:14 by jsamardz         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CFLAGS = -Wall -Werror -Wextra
SRC = server.c client.c
OBJ = $(SRC:.c=.o)
NAME = minitalk.a

LIB_P = ./libft
LIB = $(LIB_P)/libft.a

PRT_P = ./ft_printf
PRT = $(PRT_P)/ft_printf.a

all: $(NAME)

$(NAME): $(OBJ) $(LIB) $(PRT)
	ar rcs $(NAME) $(OBJ) $(LIB) $(PRT)

%.o: %.cc
	cc $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean:
	rm -f $(OBJ)
	rm -f $(NAME)

re: fclean all
.PHONY: all clean fclean re