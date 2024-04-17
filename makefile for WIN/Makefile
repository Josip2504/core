SRC = main.c
NAME = main
OBJ = $(SRC:.c=.o)
CC = gcc

all: $(NAME)

$(NAME): $(SRC)
	$(CC) -o $(NAME) $(SRC)

%.o: %.cc
	cc -c $< -o $@

clean:
	rm -f $(OBJ)

fclean:
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re 