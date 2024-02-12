/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjandri <bjandri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 11:14:50 by bjandri           #+#    #+#             */
/*   Updated: 2024/02/12 12:32:16 by bjandri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	move_game(int keycode, t_game *game)
{
	if (keycode == ESC || keycode == Q)
	{
		ft_destroy_game(game);
		exit(1);
	}
	else
	{
		move_up(keycode, game);
		move_left(keycode, game);
		move_down(keycode, game);
		move_right(keycode, game);
	}
	if (game->map[game->player_x][game->player_y] == 'C')
	{
		game->count_coins++;
		game->map[game->player_x][game->player_y] = '0';
	}
	return (0);
}

void	move_up(int keycode, t_game *game)
{
	game->new_x = game->player_x;
	game->new_y = game->player_y;
	if ((keycode == UP || keycode == W))
	{
		if (game->map[game->player_x - 1][game->player_y] == '0'
			|| game->map[game->player_x - 1][game->player_y] == 'C'
			|| game->map[game->player_x - 1][game->player_y] == 'P')
		{
			game->player_x -= 1;
			game->moves++;
			ft_printf("Moves = %d\n", game->moves);
			ft_put_img_up(game->new_y, game->new_x, game);
		}
		else if (game->map[game->player_x - 1][game->player_y] == 'E')
		{
			if (game->coins_c == game->count_coins)
			{
				// ft_destroy_game(game);
				exit(1);
			}
		}
	}
}

void	move_left(int keycode, t_game *game)
{
	game->new_x = game->player_x;
	game->new_y = game->player_y;
	if ((keycode == LEFT || keycode == A))
	{
		if (game->map[game->player_x][game->player_y - 1] == '0'
			|| game->map[game->player_x][game->player_y - 1] == 'C'
			|| game->map[game->player_x][game->player_y - 1] == 'P')
		{
			game->player_y -= 1;
			game->moves++;
			ft_printf("Moves = %d\n", game->moves);
			ft_put_img_left(game->new_y, game->new_x, game);
		}
		else if (game->map[game->player_x][game->player_y - 1] == 'E')
		{
			if (game->coins_c == game->count_coins)
			{
				// ft_destroy_game(game);
				exit(1);
			}
		}
	}
}

void	move_down(int keycode, t_game *game)
{
	game->new_x = game->player_x;
	game->new_y = game->player_y;
	if ((keycode == DOWN || keycode == S))
	{
		if (game->map[game->player_x + 1][game->player_y] == '0'
			|| game->map[game->player_x + 1][game->player_y] == 'C'
			|| game->map[game->player_x + 1][game->player_y] == 'P')
		{
			game->player_x += 1;
			game->moves++;
			ft_printf("Moves = %d\n", game->moves);
			ft_put_img_down(game->new_y, game->new_x, game);
		}
		else if (game->map[game->player_x + 1][game->player_y] == 'E')
		{
			if (game->coins_c == game->count_coins)
			{
				// ft_destroy_game(game);
				exit(1);
			}
		}
	}
}

void	move_right(int keycode, t_game *game)
{
	game->new_x = game->player_x;
	game->new_y = game->player_y;
	if ((keycode == RIGHT || keycode == D))
	{
		if (game->map[game->player_x][game->player_y + 1] == '0'
			|| game->map[game->player_x][game->player_y + 1] == 'C'
			|| game->map[game->player_x][game->player_y + 1] == 'P')
		{
			game->player_y += 1;
			game->moves++;
			ft_printf("Moves = %d\n", game->moves);
			ft_put_img_right(game->new_y, game->new_x, game);
		}
		else if (game->map[game->player_x][game->player_y + 1] == 'E')
		{
			if (game->coins_c == game->count_coins)
			{
				// ft_destroy_game(game);
				exit(1);
			}
		}
	}
}
