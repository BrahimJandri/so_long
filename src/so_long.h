/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjandri <bjandri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/13 17:55:31 by bjandri           #+#    #+#             */
/*   Updated: 2024/02/03 14:53:42 by bjandri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../libft/libft.h"
# include "../minilibx/mlx.h"
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

# define ESC	65307
# define UP		65362
# define DOWN	65364
# define LEFT	65361
# define RIGHT	65363
# define W	119
# define A	97
# define S	115
# define D	100






# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

# define WALL '1'
# define FLOOR '0'
# define COINS 'C'
# define PLAYER 'P'
# define EXIT 'E'

# define WALL_SPRITE "../Textures/wall.xpm"
# define FLOOR_SPRITE "../Textures/floor.xpm"
# define PLAYER_SPRITE "../Textures/player.xpm"
# define COINS_SPRITE "../Textures/coin.xpm"
# define EXIT_SPRITE "../Textures/exit.xpm"

typedef struct s_player
{
	int			x;
	int			y;
}				t_player;

typedef struct s_map
{
	char		**all_map;
	int			x;
	int			y;
	int			coins;
	int			exit;
	int			wall;
	int			floor;
	int			players;
}				t_map;

typedef struct s_param
{
	void		*exit;
	void		*player;
	void		*coin;
	void		*floor;
	void		*wall;
}				t_param;

typedef struct s_game
{
	void		*mlx;
	void		*win;
	int			moves;
	t_map		map;
	t_param		param;
	t_player	player;
}				t_game;

void			check_map_params(t_game *game);
void			count_map_params(t_game *game);
void			check_border_map(t_game *game);
void			error_msg(char *msg, t_game *game);
int				read_map(t_game *game, char *argv);
void			map_run(t_game *game);
void			draw_coins(t_game *game, int height, int width);
void			draw_player(t_game *game, int height, int width);
void			draw_floor(t_game *game, int height, int width);
void			draw_exit(t_game *game, int height, int width);
void			draw_wall(t_game *game, int height, int width);
int				move_player(t_game *game, int keycode);
int 			is_valid_move(t_game *game, int x, int y);

char			*get_next_line(int fd);
int				ft_strllen(char *str);
char			*ft_strjoin(char *s1, char *s2);
char			*ft_strchr(char *str, int c);
char			*ft_free(char *str);

#endif
