/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjandri <bjandri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 14:48:07 by bjandri           #+#    #+#             */
/*   Updated: 2024/02/19 17:37:13 by bjandri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

char	*animations_enemy(t_game *game)
{
	static int	i = 0;
	char		*img;

	if (i < 100)
	{
		img = ENEMY_1;
	}
	else if (i < 150)
	{
		img = ENEMY_2;
	}
	else
	{
		i = 0;
		img = ENEMY_1;
	}
	draw_enemy(game, img);
	i++;
	return (img);
}

void	draw_enemy(t_game *game, char *img)
{
	int		i;
	int		j;
	void	*enemy_img;

	i = 0;
	while (i < game->map_x)
	{
		j = 0;
		while (j < game->map_y)
		{
			if (game->map[i][j] == 'T')
			{
				enemy_img = mlx_xpm_file_to_image(game->mlx, img, &game->height,
						&game->width);
				mlx_put_image_to_window(game->mlx, game->win, enemy_img, j * 64,
					i * 64);
				mlx_destroy_image(game->mlx, enemy_img);
			}
			j++;
		}
		i++;
	}
}

int	update_and_draw(t_game *game)
{
	char	*img;

	img = animations_enemy(game);
	draw_enemy(game, img);
	return (0);
}
