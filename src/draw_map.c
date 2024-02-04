/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjandri <bjandri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 18:59:56 by bjandri           #+#    #+#             */
/*   Updated: 2024/02/04 11:36:34 by bjandri          ###   ########.fr       */
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
	while (i < game->map_x)
	{
		j = 0;
		while (j < game->map_y)
		{
			if (game->map[i][j] == 'C')
			{
				game->coin = mlx_xpm_file_to_image(game->mlx, COINS_SPRITE,
						&height, &width);
				mlx_put_image_to_window(game->mlx, game->win, game->coin, j
					* 64, i * 64);
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
	while (i < game->map_x)
	{
		j = 0;
		while (j < game->map_y)
		{
			if (game->map[i][j] == 'E')
			{
				game->exit = mlx_xpm_file_to_image(game->mlx, EXIT_SPRITE,
						&height, &width);
				mlx_put_image_to_window(game->mlx, game->win, game->exit, j
					* 64, i * 64);
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
	while (i < game->map_x)
	{
		j = 0;
		while (j < game->map_y)
		{
			if (game->map[i][j] == 'P')
			{
				game->player = mlx_xpm_file_to_image(game->mlx, PLAYER_SPRITE,
						&height, &width);
				mlx_put_image_to_window(game->mlx, game->win, game->player, j
					* 64, i * 64);
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
	while (i < game->map_x)
	{
		j = 0;
		while (j < game->map_y)
		{
			if (game->map[i][j] == '0')
			{
				game->floor = mlx_xpm_file_to_image(game->mlx, FLOOR_SPRITE,
						&height, &width);
				mlx_put_image_to_window(game->mlx, game->win, game->floor, j
					* 64, i * 64);
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
	while (i < game->map_x)
	{
		j = 0;
		while (j < game->map_y)
		{
			if (game->map[i][j] == '1')
			{
				game->wall = mlx_xpm_file_to_image(game->mlx, WALL_SPRITE,
						&height, &width);
				mlx_put_image_to_window(game->mlx, game->win, game->wall, j
					* 64, i * 64);
			}
			j++;
		}
		i++;
	}
}
