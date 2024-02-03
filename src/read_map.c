/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjandri <bjandri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 19:00:02 by bjandri           #+#    #+#             */
/*   Updated: 2024/02/03 12:10:48 by bjandri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	error_open(int fd, t_game *game)
{
	if (fd == -1)
		error_msg("Error opening file", game);
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
	return (i);
}

void	fill_map(t_game *game, char *argv)
{
	int		i;
	int		fd;
	char	*line;

	i = 0;
	fd = open(argv, O_RDONLY);
	error_open(fd, game);
	game->map.all_map = malloc(sizeof(char *) * (game->map.x + 1));
	while (i < game->map.x)
	{
		line = get_next_line(fd);
		game->map.all_map[i] = ft_strdup(line);
		free(line);
		i++;
	}
	game->map.all_map[i] = NULL;
	close(fd);
}

int	read_map(t_game *game, char *argv)
{
	int	fd;

	fd = open(argv, O_RDONLY);
	error_open(fd, game);
	game->map.x = contline(fd);
	close(fd);
	fd = open(argv, O_RDONLY);
	error_open(fd, game);
	game->map.y = ft_strlen(get_next_line(fd)) - 1;
	close(fd);
	game->win = mlx_new_window(game->mlx, 64 * game->map.y, 64 * game->map.x,
			"so_long");
	fill_map(game, argv);
	if (!game->map.all_map)
		error_msg("Memory allocation error", game);
	map_run(game);
	mlx_loop(game->mlx);
	return (0);
}

void	map_run(t_game *game)
{
	int	height;
	int	width;

	height = 64;
	width = 64;
	check_border_map(game);
	count_map_params(game);
	check_map_params(game);
	draw_coins(game, height, width);
	draw_player(game, height, width);
	draw_floor(game, height, width);
	draw_exit(game, height, width);
	draw_wall(game, height, width);
}
