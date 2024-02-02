/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_all_map.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjandri <bjandri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/13 17:55:05 by bjandri           #+#    #+#             */
/*   Updated: 2024/02/02 11:31:07 by bjandri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	error_msg(char *msg, t_game *game)
{
	ft_printf("%s\n", msg);
	free(game->map.all_map);
	exit(1);
}

void	check_border_map(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	j = game->map.y - 1;
	while (i < game->map.x)
	{
		if(game->map.all_map[0][0] == '\n')
			error_msg("Error\nMap has a new line first", game);
		else if (game->map.all_map[i][0] != WALL || game->map.all_map[i][j] != WALL)
			error_msg("Error\nMap is not closed missing walls rows", game);
		i++;
	}
	i = 0;
	j = game->map.x - 1;
	while (i < game->map.y)
	{
		if (game->map.all_map[0][i] != WALL || game->map.all_map[j][i] != WALL)
			error_msg("Error\nMap is not closed missing walls columns", game);
		i++;
	}
}

void	count_map_params(t_game *game)
{
	int	i;
	int	j;

	game->map.exit = 0;
	game->map.floor = 0;
	game->map.coins = 0;
	game->map.players = 0;
	
	i = 0;
	while (i < game->map.x)
	{
		j = 0;
		while (j < game->map.y)
		{
			if (game->map.all_map[i][j] == 'E')
				game->map.exit++;
			else if (game->map.all_map[i][j] == 'P')
			{
				game->player.x = i;
				game->player.y = j;
				game->map.players++;
			}
			else if (game->map.all_map[i][j] == 'C')
				game->map.coins++;
			else if (game->map.all_map[i][j] == '0')
				game->map.floor++;
			j++;
		}
		i++;
	}
}

void check_map_params(t_game *game)
{	
	if (game->map.exit != 1 || game->map.players != 1 || game->map.coins == 0
		|| game->map.floor == 0)
		error_msg("Error\nMap params is not valid", game);
}
