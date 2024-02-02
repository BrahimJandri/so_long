#include "so_long.h"

void error_open(int fd, t_game *game)
{
	if (fd == -1)
		error_msg("Error opening file", game);
}
int	contline(int fd)
{
	int		i;
	char	*line;

	i = 0;
	while ((line = get_next_line(fd)) != NULL)
	{
		free(line);
		i++;
	}
	return (i);
}
void	fill_map(t_game *game,char  *argv)
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
	check_border_map(game);
	count_map_params(game);
	check_map_params(game);
	draw_params(game);
	mlx_loop(game->mlx);
	return (0);
}
