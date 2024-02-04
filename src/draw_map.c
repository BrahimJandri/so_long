/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjandri <bjandri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 18:59:56 by bjandri           #+#    #+#             */
/*   Updated: 2024/02/04 15:52:59 by bjandri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	draw_coins(t_game *game);
void	draw_player(t_game *game);
void	draw_floor(t_game *game);
void	draw_exit(t_game *game);
void	draw_wall(t_game *game);

void	draw_coins(t_game *game)
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
						&game->height, &game->width);
				mlx_put_image_to_window(game->mlx, game->win, game->coin, j
					* 64, i * 64);
			}
			j++;
		}
		i++;
	}
}

void	draw_exit(t_game *game)
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
						&game->height, &game->width);
				mlx_put_image_to_window(game->mlx, game->win, game->exit, j
					* 64, i * 64);
			}
			j++;
		}
		i++;
	}
}

void	draw_player(t_game *game)
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
				game->p_front = mlx_xpm_file_to_image(game->mlx, P_FROTN,
						&game->height, &game->width);
				mlx_put_image_to_window(game->mlx, game->win, game->p_front, j
					* 64, i * 64);
			}
			j++;
		}
		i++;
	}
}

void	draw_floor(t_game *game)
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
						&game->height, &game->width);
				mlx_put_image_to_window(game->mlx, game->win, game->floor, j
					* 64, i * 64);
			}
			j++;
		}
		i++;
	}
}

void	draw_wall(t_game *game)
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
						&game->height, &game->width);
				mlx_put_image_to_window(game->mlx, game->win, game->wall, j
					* 64, i * 64);
			}
			j++;
		}
		i++;
	}
}
