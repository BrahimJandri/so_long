/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjandri <bjandri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 19:00:02 by bjandri           #+#    #+#             */
/*   Updated: 2024/02/21 12:59:11 by bjandri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static void	error_open(int fd)
{
	if (fd == -1)
	{
		error_msg("Error opening file");
		exit(EXIT_FAILURE);
	}
}

static int	contline(int fd)
{
	int		i;
	char	*line;

	i = 0;
	line = get_next_line(fd);
	while (line)
	{
		free(line);
		i++;
		line = get_next_line(fd);
	}
	return (i);
}

static void	ft_fill_map(t_game *game, int fd)
{
	int		i;
	char	*line;

	i = 0;
	game->map = malloc(sizeof(char *) * (game->map_x + 1));
	if (!game->map)
		error_msg("Memory allocation error");
	while (i < game->map_x)
	{
		line = get_next_line(fd);
		game->map[i] = ft_strdup(line);
		free(line);
		i++;
	}
	game->map[i] = NULL;
}

void	ft_read_map(t_game *game, char *argv)
{
	int		fd;
	char	*temp;
	int		len;

	fd = open(argv, O_RDONLY);
	error_open(fd);
	game->map_x = contline(fd);
	if (!game->map_x || game->map_x < 3)
		error_msg("Erorr\nInvalid map");
	close(fd);
	fd = open(argv, O_RDONLY);
	error_open(fd);
	temp = get_next_line(fd);
	if (temp[0] == '\n')
		error_msg("Erorr\nInvalid map");
	len = ft_strlen(temp) - 1;
	game->map_y = len;
	close(fd);
	fd = open(argv, O_RDONLY);
	error_open(fd);
	ft_fill_map(game, fd);
	close(fd);
	free(temp);
}
