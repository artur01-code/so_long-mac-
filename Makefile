SRC = main.c get_next_line.c get_next_line_utils.c create_map.c move.c check_map.c map_helper.c

OBJS		=	$(SRC:.c=.o)

CFLAGS		=	-Wall -Werror -Wextra

%.o: %.c 
		gcc $(CFLAGS) -Imlx -c $< -o $@

so_long:	$(OBJS)
			cd mlx && make
			cd ft_printf && make
			gcc $(OBJS) ft_printf/libftprintf.a libmlx.dylib -o $@

all:		so_long

clean:
		cd mlx && make clean
		cd ft_printf && make clean
		rm -rf $(OBJS)

fclean: clean
		rm -rf so_long
		rm -rf ft_printf/libftprintf.a
		rm -rf libmlx.a

re: fclean all
