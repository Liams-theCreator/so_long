NAME = gnl.a
CC = cc
CFLAGS = -Werror -Wall -Wextra
SRC = get_next_line_bonus.c get_next_line_utils_bonus.c
OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	ar rcs $(NAME) $(OBJ)

%.o: %.c
	$(CC) $(CFLAGS) -c $<

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
