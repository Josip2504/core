# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jsamardz <jsamardz@student.42heilnronn.    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/18 12:16:43 by jsamardz          #+#    #+#              #
#    Updated: 2024/03/21 13:56:40 by jsamardz         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CFLAGS = -Wall -Werror -Wextra
SRC = ft_printf.c print_format.c print_char.c print_str.c print_digit.c print_x.c \
print_ptr.c
OBJ = $(SRC:.c=.o)
NAME = libftprintf.a

all: $(NAME)

$(NAME): $(OBJ)
	$(MAKE) -C ./libft
	cp ./libft/libft.a $(NAME)
	ar rcs $(NAME) $(OBJ)

%.o: %.cc
	cc $(CFLAGS) -c $< -o $@ 

clean:
	rm -f $(OBJ)
	$(MAKE) -C ./libft

fclean:
	rm -f $(OBJ)
	rm -f $(NAME)
	$(MAKE) -C ./libft

re: fclean all
.PHONY: all clean fclean re