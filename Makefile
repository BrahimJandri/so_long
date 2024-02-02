NAME = so_long
CC = gcc
CFLAGS = -Wall -Wextra -Werror -g
MLXFLAGS = -L minilibx -lmlx -lm -lX11 -lXext -lbsd
MINILIBX = minilibx/libmlx.a
RM = rm -f
AR = ar rcs
LIBFT = libft/libft.a

SRC = check_all_map.c draw_map.c read_map.c so_long.c get_next_line/get_next_line.c get_next_line/get_next_line_utils.c
OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(MAKE) -C libft
	$(CC) $(CFLAGS) $(OBJ) $(LIBFT) $(MLXFLAGS) -o $(NAME) #-fsanitize=address

clean:
	$(MAKE) clean -C libft
	$(RM) $(OBJ)

fclean: clean
	$(MAKE) fclean -C libft
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
