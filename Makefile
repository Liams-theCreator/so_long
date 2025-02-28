CC = cc
FLAGS = -Werror -Wall -Wextra
MFLAGS = -lmlx -lXext -lX11
SRC = main.c
OBJ = $(SRC:.c=.o)
NAME = so_long

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(FLAGS) $(OBJ) $(MFLAGS) -o $(NAME)

%.o: %.c
	$(CC) $(FLAGS) $(MFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
