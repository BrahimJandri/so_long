/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_all_map.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjandri <bjandri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/13 17:55:05 by bjandri           #+#    #+#             */
/*   Updated: 2024/02/04 11:37:55 by bjandri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	error_msg(char *msg)
{
	ft_printf("%s\n", msg);
	exit(1);
}

void	check_border_map(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	j = game->map_y - 1;
	while (i < game->map_x)
	{
		if (game->map[0][0] == '\n')
			error_msg("Error\nMap has a new line first");
		else if (game->map[i][0] != WALL || game->map[i][j] != WALL)
			error_msg("Error\nMap is not closed missing walls rows");
		i++;
	}
	i = 0;
	j = game->map_x - 1;
	while (i < game->map_y)
	{
		if (game->map[0][i] != WALL || game->map[j][i] != WALL)
			error_msg("Error\nMap is not closed missing walls columns");
		i++;
	}
}

void	count_map_params(t_game *game)
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
				game->map_exit++;
			else if (game->map[i][j] == 'P')
			{
				game->player_x = i;
				game->player_y = j;
				game->map_player++;
			}
			else if (game->map[i][j] == 'C')
				game->map_coins++;
			else if (game->map[i][j] == '0')
				game->map_floor++;
			j++;
		}
		i++;
	}
}

void	check_map_params(t_game *game)
{
	if (game->map_exit != 1 || game->map_player != 1 || game->map_coins == 0
		|| game->map_floor == 0)
		error_msg("Error\nMap params is not valid");
}

// void check_canreach(t_game )