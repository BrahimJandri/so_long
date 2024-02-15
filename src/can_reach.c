/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   can_reach.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjandri <bjandri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 09:27:28 by bjandri           #+#    #+#             */
/*   Updated: 2024/02/15 15:41:17 by bjandri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	can_reach(int x, int y, t_game *game)
{
	game->visited[x][y] = 1;
	if (game->map[x][y] == 'C')
		game->coins_reach++;
	if (game->map[x][y] == 'E')
		game->exit_reach++;
	if (is_valid(x + 1, y, game))
		can_reach(x + 1, y, game);
	if (is_valid(x - 1, y, game))
		can_reach(x - 1, y, game);
	if (is_valid(x, y + 1, game))
		can_reach(x, y + 1, game);
	if (is_valid(x, y - 1, game))
		can_reach(x, y - 1, game);
}

void	fill_visited(t_game *game)
{
	int	i;
	int	j;

	game->visited = (int **)malloc(game->map_x * sizeof(int *));
	if (!game->visited)
		error_msg("Memory allocation failed for visited rows.\n");
	i = 0;
	while (i < game->map_x)
	{
		game->visited[i] = (int *)malloc(game->map_y * sizeof(int));
		if (!game->visited[i])
			error_msg("Memory allocation failed for visited columns.\n");
		i++;
	}
	i = 0;
	while (i < game->map_x)
	{
		j = 0;
		while (j < game->map_y)
		{
			game->visited[i][j] = 0;
			j++;
		}
		i++;
	}
}

int	is_valid(int x, int y, t_game *game)
{
	if (x > 0 && x < game->map_x && y > 0 && y < game->map_y
		&& game->map[x][y] != '1' && game->map[x][y] != 'P'
		&& !game->visited[x][y])
			return (1);
	return (0);
}

void	is_recheable(t_game *game)
{
	if (game->coins_reach != game->coins_c || game->exit_reach != 1)
		error_msg("Invalid Map");
}
