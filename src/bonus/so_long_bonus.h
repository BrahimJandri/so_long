/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjandri <bjandri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/13 17:55:31 by bjandri           #+#    #+#             */
/*   Updated: 2024/02/19 16:42:47 by bjandri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H

# include "../../libft/libft.h"
# include "../../minilibx/mlx.h"
# include <X11/keysym.h>
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

# define ESC 65307
# define UP 65362
# define DOWN 65364
# define LEFT 65361
# define RIGHT 65363
# define W 119
# define A 97
# define S 115
# define D 100
# define Q 113

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

# define WALL_SPRITE "Textures/wall.xpm"
# define FLOOR_SPRITE "Textures/floor.xpm"
# define COINS_SPRITE "Textures/coins.xpm"
# define EXIT_SPRITE "Textures/exit.xpm"
# define P_FROTN "Textures/p_front.xpm"
# define P_LEFT "Textures/p_left.xpm"
# define P_RIGHT "Textures/p_right.xpm"
# define P_BACK "Textures/p_back.xpm"
# define ENEMY_1 "Textures/enemy-1.xpm"
# define ENEMY_2 "Textures/enemy-2.xpm"

typedef struct s_game
{
	void	*mlx;
	void	*win;
	int		moves;
	char	**map;
	int		map_x;
	int		map_y;
	int		player_x;
	int		player_y;
	int		coins_c;
	int		exit_c;
	int		player_c;
	int		floor_c;
	int		enemy_c;
	void	*img;
	int		width;
	int		height;
	int		new_x;
	int		new_y;
	char	**map2;
	int		enemy_x;
	int		enemy_y;
	int		direction;
	int		coins_reach;
	int		exit_reach;
	int		count_coins;
}			t_game;

void		ft_check_all_map(t_game *game);
void		ft_check_params(t_game *game);
void		ft_check_border_map(t_game *game);
void		ft_count_map_params(t_game *game);
void		ft_check_rectungle(t_game *game);
int			error_msg(char *msg);
void		ft_read_map(t_game *game, char *str);
void		map_check(t_game *game);
void		ft_draw_map(t_game *game);
int			check_path(const char *filename);
int			move_game(int keycode, t_game *game);
void		move_player(int keycode, t_game *game);
void		move_direction(t_game *game, int x, int y, char *img);
void		ft_put_img(int i, int j, char *img, t_game *game);
void		free_all(t_game *game);
void		draw_enemy(t_game *game, char *img);
int			update_and_draw(t_game *game);
char		*Animations_enemy(t_game *game);
int			ft_exit(void);
void		ft_print_movements(t_game *game, int move);
void		map_dup(t_game *game);
void		ft_flood_fill(int x, int y, t_game *game);
void		ft_check_e(t_game *game);
char		*get_next_line(int fd);
int			ft_strllen(char *str);
char		*ft_strjjoin(char *s1, char *s2);
char		*ft_strchr(char *str, int c);
char		*ft_free(char *str);
void		check_enemy(t_game *game);

#endif
