CC = cc
FLAGS = -Werror -Wall -Wextra
MFLAGS = -lmlx -lXext -lX11
SRC = debugging.c ./parser/parser.c ./parser/parser_checks.c ./parser/parser_getmap.c ./parser/parser_init.c ./parser/parser_path.c ./parser/parser_store.c ./parser/errors.c
OBJ = $(SRC:.c=.o)

GNLOBJ = ./srcs/gnl/gnl.a
PRINTFOBJ = ./srcs/printf/libftprintf.a
LIBFTOBJ = ./srcs/libft/libft.a

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
