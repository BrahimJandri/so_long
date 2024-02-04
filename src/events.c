/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjandri <bjandri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 11:14:50 by bjandri           #+#    #+#             */
/*   Updated: 2024/02/04 17:56:10 by bjandri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	move_game(int keycode, t_game *game)
{
	if (keycode == ESC || keycode == Q)
	{
		mlx_destroy_window(game->mlx, game->win);
		exit(0);
	}
	else
	{
		move_leftright(keycode, game);
		move_updown(keycode, game);
	}
	return (0);
}

void	move_updown(int keycode, t_game *game)
{
	game->new_x = game->player_x;
	game->new_y = game->player_y;
	if ((keycode == DOWN || keycode == S) && (game->map[game->player_x
			+ 1][game->player_y] != WALL))
	{
		game->player_x += 1;
		game->moves++;
		ft_printf("Moves = %d\n", game->moves);
		mlx_put_image_to_window(game->mlx, game->win, game->floor, game->new_y
			* 64, game->new_x * 64);
		mlx_put_image_to_window(game->mlx, game->win, game->p_front,
			game->player_y * 64, game->player_x * 64);
	}
	if ((keycode == UP || keycode == W) && (game->map[game->player_x
			- 1][game->player_y] != WALL))
	{
		game->player_x -= 1;
		game->moves++;
		ft_printf("Moves = %d\n", game->moves);
		game->p_back = mlx_xpm_file_to_image(game->mlx, P_BACK, &game->height,
				&game->width);
		mlx_put_image_to_window(game->mlx, game->win, game->floor, game->new_y
			* 64, game->new_x * 64);
		mlx_put_image_to_window(game->mlx, game->win, game->p_back,
			game->player_y * 64, game->player_x * 64);
	}
}

void	move_leftright(int keycode, t_game *game)
{
	game->new_x = game->player_x;
	game->new_y = game->player_y;
	if ((keycode == RIGHT || keycode == D)
		&& (game->map[game->player_x][game->player_y + 1] != WALL))
	{
		game->player_y += 1;
		game->moves++;
		ft_printf("Moves = %d\n", game->moves);
		game->p_right = mlx_xpm_file_to_image(game->mlx, P_RIGHT, &game->height,
				&game->width);
		mlx_put_image_to_window(game->mlx, game->win, game->floor, game->new_y
			* 64, game->new_x * 64);
		mlx_put_image_to_window(game->mlx, game->win, game->p_right,
			game->player_y * 64, game->player_x * 64);
	}
	if ((keycode == LEFT || keycode == A)
		&& (game->map[game->player_x][game->player_y - 1] != WALL))
	{
		game->player_y -= 1;
		game->moves++;
		ft_printf("Moves = %d\n", game->moves);
		put_imgleft(game);
	}
}

void	put_imgleft(t_game *game)
{
	game->p_left = mlx_xpm_file_to_image(game->mlx, P_LEFT, &game->height,
			&game->width);
	mlx_put_image_to_window(game->mlx, game->win, game->floor, game->new_y * 64,
		game->new_x * 64);
	mlx_put_image_to_window(game->mlx, game->win, game->p_left, game->player_y
		* 64, game->player_x * 64);
}
