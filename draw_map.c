#include "so_long.h"

void	draw_params(t_game *game)
{
	int i;
	int j;
	int img_width;
	int img_height;

	img_height = 64;
	img_width = 64;
	i = 0;
	while (i < game->map.x)
	{
		j = 0;
		while (j < game->map.y)
		{
			if (game->map.all_map[i][j] == 'E')
			{
				void *exit = mlx_xpm_file_to_image(game->mlx, EXIT_SPRITE,
						&img_width, &img_height);
				mlx_put_image_to_window(game->mlx, game->win, exit, j
					* img_width, i * img_height);
			}
			else if (game->map.all_map[i][j] == 'P')
			{
				void *player = mlx_xpm_file_to_image(game->mlx, PLAYER_SPRITE,
						&img_width, &img_height);
				mlx_put_image_to_window(game->mlx, game->win, player, j
					* img_width, i * img_height);
			}
			else if (game->map.all_map[i][j] == 'C')
			{
				void *coin = mlx_xpm_file_to_image(game->mlx, COINS_SPRITE,
						&img_width, &img_height);
				mlx_put_image_to_window(game->mlx, game->win, coin, j
					* img_width, i * img_height);
			}
			else if (game->map.all_map[i][j] == '0')
			{
				void *floor = mlx_xpm_file_to_image(game->mlx, FLOOR_SPRITE,
						&img_width, &img_height);
				mlx_put_image_to_window(game->mlx, game->win, floor, j
					* img_width, i * img_height);
			}
			else if (game->map.all_map[i][j] == '1')
			{
				void *wall = mlx_xpm_file_to_image(game->mlx, WALL_SPRITE,
						&img_width, &img_height);
				mlx_put_image_to_window(game->mlx, game->win, wall, j
					* img_width, i * img_height);
			}
			j++;
		}
		i++;
	}
}
