/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_all_map.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjandri <bjandri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/13 17:55:05 by bjandri           #+#    #+#             */
/*   Updated: 2024/02/10 15:12:09 by bjandri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_check_all_map(t_game *game)
{
	ft_check_border_map(game);
	ft_count_map_params(game);
	ft_check_rectungle(game);
	ft_check_params(game);
}

void	ft_check_border_map(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	j = game->map_y - 1;
	while (i < game->map_x)
	{
		if (game->map[i][0] != '1' || game->map[i][j] != '1')
			error_msg("Error\nMap is not closed missing walls rows");
		i++;
	}
	i = 0;
	j = game->map_x - 1;
	while (i < game->map_y)
	{
		if (game->map[0][i] != '1' || game->map[j][i] != '1')
			error_msg("Error\nMap is not closed missing walls columns");
		i++;
	}
}

void	ft_count_map_params(t_game *game)
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
				game->exit_c++;
			else if (game->map[i][j] == 'P')
			{
				game->player_x = i;
				game->player_y = j;
				game->player_c++;
			}
			else if (game->map[i][j] == 'C')
				game->coins_c++;
			j++;
		}
		i++;
	}
	if (game->coins_c == 0 || game->exit_c != 1 || game->player_c != 1)
		error_msg("Error\nMap params is not valid");
}

void	ft_check_rectungle(t_game *game)
{
	int	first_line;
	int	current_line;
	int	i;

	i = 1;
	first_line = ft_strlen(game->map[0]);
	while (i < game->map_x - 1)
	{
		current_line = ft_strlen(game->map[i]);
		if (current_line != first_line)
			error_msg("Error\nMap is Not Rectungle");
		i++;
	}
	current_line = ft_strlen(game->map[i]);
	if (current_line != first_line - 1)
		error_msg("Error\nMap is Not Rectungle");
}

void	ft_check_params(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (i < game->map_x)
	{
		j = 0;
		while (j < game->map_y)
		{
			if (game->map[i][j] != '1' && game->map[i][j] != 'C'
				&& game->map[i][j] != 'E' && game->map[i][j] != '0'
				&& game->map[i][j] != 'P')
				error_msg("Error\nInvalid params of the map");
			j++;
		}
		i++;
	}
}
