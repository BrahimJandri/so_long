/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjandri <bjandri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/13 17:55:31 by bjandri           #+#    #+#             */
/*   Updated: 2024/02/04 17:52:18 by bjandri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../libft/libft.h"
# include "../minilibx/mlx.h"
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

# define WALL '1'
# define FLOOR '0'
# define COINS 'C'
# define PLAYER 'P'
# define EXIT 'E'

# define WALL_SPRITE "../Textures/wall.xpm"
# define FLOOR_SPRITE "../Textures/floor.xpm"
# define COINS_SPRITE "../Textures/coins.xpm"
# define EXIT_SPRITE "../Textures/exit.xpm"
# define P_FROTN "../Textures/p_front.xpm"
# define P_LEFT "../Textures/p_left.xpm"
# define P_RIGHT "../Textures/p_right.xpm"
# define P_BACK "../Textures/p_back.xpm"

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
	int		map_coins;
	int		map_exit;
	int		map_wall;
	int		map_floor;
	int		map_player;
	void	*exit;
	void	*p_front;
	void	*p_left;
	void	*p_back;
	void	*p_right;
	void	*coin;
	void	*floor;
	void	*wall;
	int		width;
	int		height;
	int		new_x;
	int		new_y;
}			t_game;

void		check_map_params(t_game *game);
void		count_map_params(t_game *game);
void		check_border_map(t_game *game);
int			error_msg(char *msg);
int			read_map(t_game *game, char *argv);
void		map_run(t_game *game);
void		draw_coins(t_game *game);
void		draw_player(t_game *game);
void		draw_floor(t_game *game);
void		draw_exit(t_game *game);
void		draw_wall(t_game *game);
int			check_path(const char *filename);
int			move_game(int keycode, t_game *game);
void		free_game(t_game *game);
void		move_updown(int keycode, t_game *game);
void		move_leftright(int keycode, t_game *game);
void		put_imgleft(t_game *game);


char		*get_next_line(int fd);
int			ft_strllen(char *str);
char		*ft_strjoin(char *s1, char *s2);
char		*ft_strchr(char *str, int c);
char		*ft_free(char *str);

#endif
