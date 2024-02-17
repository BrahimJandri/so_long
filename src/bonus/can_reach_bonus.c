/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   can_reach_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjandri <bjandri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 09:27:28 by bjandri           #+#    #+#             */
/*   Updated: 2024/02/17 13:13:01 by bjandri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void    ft_flood_fill(int x, int y, t_game *game)
{
    if (x < 0 || x >= game->map_x || y < 0 || y >= game->map_y
        || game->map2[x][y] == '1' || game->map2[x][y] == 'E' || game->map2[x][y] == 'V')
        return ;
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
	int	j;

	game->map2 = (char **)malloc(game->map_x * sizeof(char *));
	if (!game->map2)
		error_msg("Memory allocation failed for visited rows.\n");
	i = 0;
	while (i < game->map_x)
	{
		game->map2[i] = (char *)malloc(game->map_y * sizeof(char));
		if (!game->map2[i])
			error_msg("Memory allocation failed for visited columns.\n");
		i++;
	}
	i = 0;
	while (i < game->map_x)
	{
		j = 0;
		while (j < game->map_y)
		{
			game->map2[i][j] = game->map[i][j];
			j++;
		}
		i++;
	}
}
void ft_check_e(t_game *game)
{
	int i;
	int j;

	i = 0;
	while(i < game->map_x)
	{
		j = 0;
		while(j < game->map_y)
		{
			if(game->map2[i][j] == 'E')
			{
				if(game->map2[i + 1][j] != 'V' && game->map2[i - 1][j] != 'V' && game->map2[i][j + 1] != 'V' && game->map2[i][j - 1] != 'V')
					error_msg("Can't Reach The Exit");
				if(game->map2[i][j] == 'C')
					error_msg("Can't Reach The Coins");
			}
			j++;
		}
		i++;
	}
}