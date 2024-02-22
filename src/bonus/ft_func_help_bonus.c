/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_func_help_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjandri <bjandri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 11:30:35 by bjandri           #+#    #+#             */
/*   Updated: 2024/02/20 09:21:24 by bjandri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	error_msg(char *msg)
{
	ft_printf("%s\n", msg);
	exit(EXIT_FAILURE);
}

int	check_path(const char *filename)
{
	size_t	len;

	len = ft_strlen(filename);
	if (len >= 4 && ft_strncmp(filename + len - 4, ".ber", 4) == 0)
		return (1);
	else
		return (0);
}

void	free_all(t_game *game)
{
	int	i;

	i = 0;
	while (game->map[i])
	{
		free(game->map[i]);
		i++;
	}
	i = 0;
	while (game->map2[i])
	{
		free(game->map2[i]);
		i++;
	}
	free(game->map);
	free(game->map2);
}

int	ft_exit(t_game *game)
{
	mlx_destroy_window(game->mlx, game->win);
	mlx_destroy_display(game->mlx);
	free(game->mlx);
	free_all(game);
	ft_printf("Unfortunately You Exit The Game 👎 ❌\n");
	exit(1);
	return (0);
}

void	map_check(t_game *game)
{
	ft_check_all_map(game);
	map_dup(game);
	ft_flood_fill(game->player_x, game->player_y, game);
	ft_check_e(game);
}
