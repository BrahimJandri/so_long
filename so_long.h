/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjandri <bjandri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/13 17:55:31 by bjandri           #+#    #+#             */
/*   Updated: 2024/02/02 18:05:19 by bjandri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "libft/libft.h"
# include "minilibx/mlx.h"
# include <fcntl.h>
# include <stdio.h>
# include "get_next_line/get_next_line.h"


# define WALL '1'
# define FLOOR '0'
# define COINS 'C'
# define PLAYER 'P'
# define EXIT 'E'


# define WALL_SPRITE "Textures/wall.xpm"
# define FLOOR_SPRITE "Textures/floor.xpm"
# define PLAYER_SPRITE "Textures/player.xpm"
# define COINS_SPRITE "Textures/coin.xpm"
# define EXIT_SPRITE "Textures/exit.xpm"

	
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

typedef struct s_img
{
	void		*img_xpm;
	int			x;
	int			y;
}				t_img;

typedef struct s_game
{
	void		*mlx;
	void		*win;
	int			moves;
	t_map		map;
	t_img		img;
	t_player	player;
}				t_game;


void 			check_map_params(t_game *game);
void			count_map_params(t_game *game);
void    		check_border_map(t_game *game);
void			error_msg(char *msg, t_game *game);
int 			read_map(t_game *game, char *argv);
void 			draw_params(t_game *game);

#endif
