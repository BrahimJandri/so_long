NAME = so_long
CC = gcc
CFLAGS = -Wall -Wextra -Werror -g3 -fsanitize=address
MLXFLAGS = -L../minilibx -lmlx -lm -lX11 -lXext
RM = rm -f
AR = ar rcs
LIBFT = ../libft/libft.a
BONUSRC = ./bonus
MANSRC = ./mandatory

SRC = $(MANSRC)/check_all_map.c $(MANSRC)/draw_map.c $(MANSRC)/read_map.c $(MANSRC)/so_long.c \
	$(MANSRC)/get_next_line.c $(MANSRC)/get_next_line_utils.c $(MANSRC)/can_reach.c \
	 $(MANSRC)/ft_func_help.c $(MANSRC)/events.c
OBJ = $(SRC:.c=.o)

SRCB = $(BONUSRC)/check_all_map_bonus.c $(BONUSRC)/draw_map_bonus.c $(BONUSRC)/read_map_bonus.c \
	$(BONUSRC)/so_long_bonus.c $(BONUSRC)/get_next_line_bonus.c $(BONUSRC)/get_next_line_utils_bonus.c \
	$(BONUSRC)/can_reach_bonus.c $(BONUSRC)/ft_func_help_bonus.c $(BONUSRC)/events_bonus.c
OBJB = $(SRCB:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(MAKE) -C ../libft
	$(CC) $(CFLAGS) $(OBJ) $(MLXFLAGS) $(LIBFT) -o $(NAME)

bonus: $(OBJB)
	$(MAKE) -C ../libft
	$(CC) $(CFLAGS) $(OBJB) $(MLXFLAGS) $(LIBFT) -o $(NAME)_bonus

clean:
	$(MAKE) clean -C ../libft
	$(RM) $(OBJ) $(OBJB)

fclean: clean
	$(MAKE) fclean -C ../libft
	$(RM) $(NAME) $(NAME)_bonus

re: fclean all

re_bonus: fclean bonus

.PHONY: all clean re fclean re_bonus
