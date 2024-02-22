/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_all_map_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjandri <bjandri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/13 17:55:05 by bjandri           #+#    #+#             */
/*   Updated: 2024/02/20 21:46:12 by bjandri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

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
			error_map("Error\nMap is not closed missing walls rows", game);
		i++;
	}
	i = 0;
	j = game->map_x - 1;
	while (i < game->map_y)
	{
		if (game->map[0][i] != '1' || game->map[j][i] != '1')
			error_map("Error\nMap is not closed missing walls columns", game);
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
				game->player_c++;
			else if (game->map[i][j] == 'C')
				game->coins_c++;
			else if (game->map[i][j] == '0')
				game->floor_c++;
			else if (game->map[i][j] == 'T')
				game->enemy_c++;
			j++;
		}
		i++;
	}
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
			error_map("Error\nMap is Not Rectungle", game);
		i++;
	}
	current_line = ft_strlen(game->map[i]);
	if (current_line != first_line - 1)
		error_map("Error\nMap is Not Rectungle", game);
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
			if (game->map[i][j] == 'P')
			{
				game->player_x = i;
				game->player_y = j;
			}
			else if (game->map[i][j] != '1' && game->map[i][j] != 'C'
				&& game->map[i][j] != 'E' && game->map[i][j] != '0'
				&& game->map[i][j] != 'P' && game->map[i][j] != 'T')
				error_map("Error\nMap params is not valid", game);
			j++;
		}
		i++;
	}
	if (game->coins_c == 0 || game->exit_c != 1 || game->player_c != 1
		|| game->floor_c < 1 || game->enemy_c < 1)
		error_map("Error\nMap params is not valid", game);
}
