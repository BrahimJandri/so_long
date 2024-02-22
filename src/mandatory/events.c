/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjandri <bjandri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 11:14:50 by bjandri           #+#    #+#             */
/*   Updated: 2024/02/20 21:31:45 by bjandri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	move_game(int keycode, t_game *game)
{
	if (keycode == ESC || keycode == Q)
	{
		mlx_destroy_window(game->mlx, game->win);
		mlx_destroy_display(game->mlx);
		free(game->mlx);
		free_all(game);
		ft_printf("Unfortunately You Exit The Game  ❌❌\n");
		exit(1);
	}
	else
		move_player(keycode, game);
	if (game->map[game->player_x][game->player_y] == 'C')
	{
		game->count_coins++;
		game->map[game->player_x][game->player_y] = '0';
	}
	return (0);
}

void	move_player(int keycode, t_game *game)
{
	game->new_x = game->player_x;
	game->new_y = game->player_y;
	if (keycode == UP || keycode == W)
		move_direction(game, -1, 0, P_BACK);
	else if (keycode == LEFT || keycode == A)
		move_direction(game, 0, -1, P_LEFT);
	else if (keycode == DOWN || keycode == S)
		move_direction(game, 1, 0, P_FROTN);
	else if (keycode == RIGHT || keycode == D)
		move_direction(game, 0, 1, P_RIGHT);
}

void	move_direction(t_game *game, int x, int y, char *img)
{
	if (game->map[game->player_x + x][game->player_y + y] == '0'
		|| game->map[game->player_x + x][game->player_y + y] == 'C'
		|| game->map[game->player_x + x][game->player_y + y] == 'P')
	{
		game->player_x += x;
		game->player_y += y;
		game->moves++;
		ft_printf("Moves : %d\n", game->moves);
		ft_put_img(game->new_y, game->new_x, img, game);
	}
	else if (game->map[game->player_x + x][game->player_y + y] == 'E')
	{
		if (game->coins_c == game->count_coins)
		{
			game->moves++;
			ft_printf("Moves : %d\n", game->moves);
			mlx_destroy_window(game->mlx, game->win);
			mlx_destroy_display(game->mlx);
			free(game->mlx);
			free_all(game);
			ft_printf("Congratulation You Win! 🥉 🏆 🎉\n");
			exit(1);
		}
	}
}

void	ft_put_img(int i, int j, char *img, t_game *game)
{
	void	*floor;

	floor = mlx_xpm_file_to_image(game->mlx, FLOOR_SPRITE, &game->width,
			&game->height);
	mlx_put_image_to_window(game->mlx, game->win, floor, i * 64, j * 64);
	mlx_destroy_image(game->mlx, floor);
	game->img = mlx_xpm_file_to_image(game->mlx, img, &game->width,
			&game->height);
	mlx_put_image_to_window(game->mlx, game->win, game->img, game->player_y
		* 64, game->player_x * 64);
	mlx_destroy_image(game->mlx, game->img);
}
