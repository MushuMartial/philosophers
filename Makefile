NAME = philo
SRC = main.c parser.c
OBJ = $(SRC:.c=.o)

CFLAGS = -Wall -Wextra -Werror
CC = gcc
RM = rm -rf

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re