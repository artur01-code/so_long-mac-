NAME = so_long

CC = gcc
FLAGS = -Wall -Werror -Wextra -g
RM = rm -f

SRC = main.c get_next_line.c get_next_line_utils.c create_map.c move.c check_map.c

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	make -C mlx/
	$(CC) $(OBJ) -Lmlx -lmlx -framework OpenGL -framework AppKit -o $(NAME)

%.o: %.c
	$(CC) $(FLAGS) -Imlx -c $< -o $@

clean:
	$(RM) *.o
	make clean -C mlx/

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
