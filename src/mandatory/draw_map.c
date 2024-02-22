/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjandri <bjandri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 18:59:56 by bjandri           #+#    #+#             */
/*   Updated: 2024/02/22 14:57:52 by bjandri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static char	*ft_make_map(char **map, int x, int y)
{
	char	*str;

	if (map[x][y] == '0')
		str = FLOOR_SPRITE;
	else if (map[x][y] == '1')
		str = WALL_SPRITE;
	else if (map[x][y] == 'E')
		str = EXIT_SPRITE;
	else if (map[x][y] == 'C')
		str = COINS_SPRITE;
	else if (map[x][y] == 'P')
		str = P_FROTN;
	return (str);
}

void	ft_draw_map(t_game *game)
{
	int		i;
	int		j;
	char	*img;

	i = 0;
	while (i < game->map_x)
	{
		j = 0;
		while (j < game->map_y)
		{
			img = ft_make_map(game->map, i, j);
			game->img = mlx_xpm_file_to_image(game->mlx, img, &game->height,
					&game->width);
			mlx_put_image_to_window(game->mlx, game->win, game->img, j * 64, i
				* 64);
			j++;
			mlx_destroy_image(game->mlx, game->img);
		}
		i++;
	}
}

void	error_map(char *msg, t_game *game)
{
	int	i;

	i = 0;
	while (game->map[i])
	{
		free(game->map[i]);
		i++;
	}
	free(game->map);
	ft_printf("%s\n", msg);
	exit(EXIT_FAILURE);
}

void	error_map2(char *msg, t_game *game)
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
	ft_printf("%s\n", msg);
	exit(EXIT_FAILURE);
}
