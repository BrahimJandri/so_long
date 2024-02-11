/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjandri <bjandri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/13 17:55:23 by bjandri           #+#    #+#             */
/*   Updated: 2024/02/11 15:26:35 by bjandri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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
	while (game->visited[i])
	{
		free(game->visited[i]);
		i++;
	}
	free(game->map);
	free(game);
	free(game->visited);
}

int	main(int argc, char **argv)
{
	t_game	*game;

	game = (t_game *)malloc(sizeof(t_game));
	if (!game)
	{
		free(game);
		exit(1);
	}
	if (argc != 2)
		error_msg("Error\nInvalid number of arguments");
	else if (!check_path(argv[1]))
		error_msg("Error\nInvalid Extension of map Should be .ber");
	ft_memset(game, 0, sizeof(t_game));
	game->height = 64;
	game->width = 64;
	ft_read_map(game, argv[1]);
	game->mlx = mlx_init();
	game->win = mlx_new_window(game->mlx, 64 * game->map_y, 64 * game->map_x,
			"so_long");
	map_run(game);
	mlx_hook(game->win, 2, 1L << 0, move_game, game);
	mlx_loop(game->mlx);
	return (0);
}
