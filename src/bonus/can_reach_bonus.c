/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   can_reach_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjandri <bjandri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 09:27:28 by bjandri           #+#    #+#             */
/*   Updated: 2024/02/22 10:52:57 by bjandri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	ft_flood_fill(int x, int y, t_game *game)
{
	if (x < 0 || x >= game->map_x || y < 0 || y >= game->map_y
		|| game->map2[x][y] == '1' || game->map2[x][y] == 'E'
		|| game->map2[x][y] == 'V')
		return ;
	if (game->map2[x][y] == 'P')
		game->map2[x][y] = 'V';
	if (game->map2[x][y] != 'P')
		game->map2[x][y] = 'V';
	ft_flood_fill(x - 1, y, game);
	ft_flood_fill(x + 1, y, game);
	ft_flood_fill(x, y - 1, game);
	ft_flood_fill(x, y + 1, game);
}

void	map_dup(t_game *game)
{
	int	i;

	i = 0;
	game->map2 = malloc(sizeof(char *) * (game->map_x + 1));
	while (i < game->map_x)
	{
		game->map2[i] = ft_strdup(game->map[i]);
		i++;
	}
	game->map2[i] = NULL;
}

void	ft_check_e(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (i < game->map_x)
	{
		j = 0;
		while (j < game->map_y)
		{
			if (game->map2[i][j] == 'E')
			{
				if (game->map2[i + 1][j] != 'V' && game->map2[i - 1][j] != 'V'
					&& game->map2[i][j + 1] != 'V' && game->map2[i][j
					- 1] != 'V')
					error_map2("Can't Reach The Exit", game);
			}
			if (game->map2[i][j] == 'C')
				error_map2("Can't Reach The Coins", game);
			if (game->map2[i][j] == 'T')
				error_map2("Can't Reach The Enemy", game);
			j++;
		}
		i++;
	}
}
