CC = cc
FLAGS = -Werror -Wall -Wextra
MFLAGS = -lmlx -lXext -lX11
SRC = parser.c
OBJ = $(SRC:.c=.o)

GNLOBJ = ./gnl/gnl.a
PRINTFOBJ = ./printf/libftprintf.a
LIBFTOBJ = ./libft/libft.a

NAME = so_long

all: $(NAME)

$(NAME): $(OBJ) $(GNLOBJ) $(PRINTFOBJ) $(LIBFTOBJ)
	$(CC) $(FLAGS) $(OBJ) $(GNLOBJ) $(PRINTFOBJ) $(LIBFTOBJ) $(MFLAGS) -o $(NAME)

%.o: %.c
	$(CC) $(FLAGS) $(MFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
