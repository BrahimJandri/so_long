/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjandri <bjandri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 18:59:56 by bjandri           #+#    #+#             */
/*   Updated: 2024/02/03 11:04:28 by bjandri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	draw_coins(t_game *game, int height, int width);
void	draw_player(t_game *game, int height, int width);
void	draw_floor(t_game *game, int height, int width);
void	draw_exit(t_game *game, int height, int width);
void	draw_wall(t_game *game, int height, int width);

void	draw_coins(t_game *game, int height, int width)
{
	int	i;
	int	j;

	i = 0;
	while (i < game->map.x)
	{
		j = 0;
		while (j < game->map.y)
		{
			if (game->map.all_map[i][j] == 'C')
			{
				game->param.coin = mlx_xpm_file_to_image(game->mlx,
						COINS_SPRITE, &height, &width);
				mlx_put_image_to_window(game->mlx, game->win, game->param.coin,
					j * 64, i * 64);
			}
			j++;
		}
		i++;
	}
}

void	draw_exit(t_game *game, int height, int width)
{
	int	i;
	int	j;

	i = 0;
	while (i < game->map.x)
	{
		j = 0;
		while (j < game->map.y)
		{
			if (game->map.all_map[i][j] == 'E')
			{
				game->param.exit = mlx_xpm_file_to_image(game->mlx, EXIT_SPRITE,
						&height, &width);
				mlx_put_image_to_window(game->mlx, game->win, game->param.exit,
					j * 64, i * 64);
			}
			j++;
		}
		i++;
	}
}

void	draw_player(t_game *game, int height, int width)
{
	int	i;
	int	j;

	i = 0;
	while (i < game->map.x)
	{
		j = 0;
		while (j < game->map.y)
		{
			if (game->map.all_map[i][j] == 'P')
			{
				game->param.player = mlx_xpm_file_to_image(game->mlx,
						PLAYER_SPRITE, &height, &width);
				mlx_put_image_to_window(game->mlx, game->win,
					game->param.player, j * 64, i * 64);
			}
			j++;
		}
		i++;
	}
}

void	draw_floor(t_game *game, int height, int width)
{
	int	i;
	int	j;

	i = 0;
	while (i < game->map.x)
	{
		j = 0;
		while (j < game->map.y)
		{
			if (game->map.all_map[i][j] == '0')
			{
				game->param.floor = mlx_xpm_file_to_image(game->mlx,
						FLOOR_SPRITE, &height, &width);
				mlx_put_image_to_window(game->mlx, game->win, game->param.floor,
					j * 64, i * 64);
			}
			j++;
		}
		i++;
	}
}

void	draw_wall(t_game *game, int height, int width)
{
	int	i;
	int	j;

	i = 0;
	while (i < game->map.x)
	{
		j = 0;
		while (j < game->map.y)
		{
			if (game->map.all_map[i][j] == '1')
			{
				game->param.wall = mlx_xpm_file_to_image(game->mlx, WALL_SPRITE,
						&height, &width);
				mlx_put_image_to_window(game->mlx, game->win, game->param.wall,
					j * 64, i * 64);
			}
			j++;
		}
		i++;
	}
}
