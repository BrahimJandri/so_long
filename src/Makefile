NAME = so_long
BONUS_NAME = so_long_bonus
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

SRCB = $(BONUSRC)/check_all_map_bonus.c $(BONUSRC)/draw_map_bonus.c $(BONUSRC)/read_map_bonus.c \
	$(BONUSRC)/so_long_bonus.c $(BONUSRC)/get_next_line_bonus.c $(BONUSRC)/get_next_line_utils_bonus.c \
	$(BONUSRC)/can_reach_bonus.c $(BONUSRC)/ft_func_help_bonus.c $(BONUSRC)/events_bonus.c $(BONUSRC)/Animation.c

OBJ = $(SRC:.c=.o)
OBJB = $(SRCB:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(MAKE) -C ../libft
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ) $(MLXFLAGS) $(LIBFT)

$(BONUS_NAME): $(OBJB)
	$(MAKE) -C ../libft
	$(CC) $(CFLAGS) -o $(BONUS_NAME) $(OBJB) $(MLXFLAGS) $(LIBFT)

bonus: $(BONUS_NAME)

clean:
	$(MAKE) clean -C ../libft
	$(RM) $(OBJ) $(OBJB)

fclean: clean
	$(MAKE) fclean -C ../libft
	$(RM) $(NAME) $(BONUS_NAME)

re: fclean all

re_bonus: fclean bonus

.SECONDARY: $(OBJ) $(OBJB)
.PHONY: all clean re fclean re_bonus
