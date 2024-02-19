/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjandri <bjandri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/13 17:55:23 by bjandri           #+#    #+#             */
/*   Updated: 2024/02/19 15:36:51 by bjandri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	ft_print_movements(t_game *game, int move)
{
	char	*moves;
	char	*phrase;
	void	*wall;

	moves = ft_itoa(move);
	phrase = ft_strjoin("Movements : ", moves);
	wall = mlx_xpm_file_to_image(game->mlx, WALL_SPRITE, &game->width,
			&game->height);
	mlx_put_image_to_window(game->mlx, game->win, wall, 45, 0);
	mlx_put_image_to_window(game->mlx, game->win, wall, 60, 0);
	mlx_string_put(game->mlx, game->win, 20, 20, 0xFFFFF, phrase);
	mlx_destroy_image(game->mlx, wall);
	free(moves);
	free(phrase);
}

int	main(int argc, char **argv)
{
	t_game	game;

	if (argc != 2)
		error_msg("Error\nInvalid number of arguments");
	else if (!check_path(argv[1]))
		error_msg("Error\nInvalid Extension of map Should be .ber");
	ft_memset(&game, 0, sizeof(t_game));
	game.height = 64;
	game.width = 64;
	ft_read_map(&game, argv[1]);
	map_check(&game);
	game.mlx = mlx_init();
	game.win = mlx_new_window(game.mlx, 64 * game.map_y, 64 * game.map_x,
			"so_long");
	ft_draw_map(&game);
	mlx_hook(game.win, 2, 1L << 0, move_game, &game);
	mlx_hook(game.win, 17, 1L << 17, ft_exit, &game);
	mlx_loop_hook(game.mlx, update_and_draw, &game);
	mlx_loop(game.mlx);
	return (0);
}
