/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjandri <bjandri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 19:00:02 by bjandri           #+#    #+#             */
/*   Updated: 2024/02/05 17:29:32 by bjandri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	error_open(int fd)
{
	if (fd == -1)
		error_msg("Error opening file");
}

int	contline(int fd)
{
	int		i;
	char	*line;

	i = 0;
	line = get_next_line(fd);
	while (line)
	{
		line = get_next_line(fd);
		free(line);
		i++;
	}
	free(line);
	return (i);
}

void	fill_map(t_game *game, char *argv)
{
	int		i;
	int		fd;
	char	*line;

	i = 0;
	fd = open(argv, O_RDONLY);
	error_open(fd);
	game->map = malloc(sizeof(char *) * (game->map_x + 1));
	while (i < game->map_x)
	{
		line = get_next_line(fd);
		game->map[i] = ft_strdup(line);
		free(line);
		i++;
	}
	game->map[i] = NULL;
	close(fd);
}

int	read_map(t_game *game, char *argv)
{
	int	fd;

	// game->color = 0x00FF0000;
	// game->move_w = ft_strjoin("Movement = ", ft_itoa(game->moves));
	fd = open(argv, O_RDONLY);
	error_open(fd);
	game->map_x = contline(fd);
	close(fd);
	fd = open(argv, O_RDONLY);
	error_open(fd);
	game->map_y = ft_strlen(get_next_line(fd)) - 1;
	close(fd);
	game->win = mlx_new_window(game->mlx, 64 * game->map_y, 64 * game->map_x,
			"so_long");
	fill_map(game, argv);
	if (!game->map)
		error_msg("Memory allocation error");
	map_run(game);
	mlx_hook(game->win, 2, 1L << 0, move_game, game);
	// mlx_string_put(game->mlx, game->win, 10, 10, game->color, game->move_w);
	mlx_loop(game->mlx);
	return (0);
}

void	map_run(t_game *game)
{
	check_border_map(game);
	count_map_params(game);
	check_map_params(game);
	fill_visited(game);
	can_reach(game->player_x, game->player_y, game);
	is_valid(game->player_x, game->player_y, game);
	is_recheable(game);
	draw_coins(game);
	draw_player(game);
	draw_floor(game);
	draw_exit(game);
	draw_wall(game);
	count_coins(game);
}
