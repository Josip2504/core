# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jsamardz <jsamardz@student.42heilnronn.    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/08 14:39:19 by jsamardz          #+#    #+#              #
#    Updated: 2024/03/08 16:06:24 by jsamardz         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CFLAGS = -Wall -Werror -Wextra
SRC = ft_strlen.c ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c \
ft_toupper.c ft_tolower.c ft_strchr.c ft_strncmp.c ft_memset.c \
ft_bzero.c ft_memmove.c ft_memchr.c ft_strrchr.c 
OBJ = $(SRC:.c=.o)
NAME = libft.a

all: ${NAME}

${NAME}: ${OBJ}
	ar rcs ${NAME} ${OBJ} 

%.o: %.cc
	cc -c $< -o $@ ${CFLAGS}

clean:
	rm -f ${OBJ}
	rm -f ${NAME}

fclean:
	rm -f ${NAME}

re: fclean all