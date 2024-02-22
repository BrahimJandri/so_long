/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjandri <bjandri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/13 17:55:23 by bjandri           #+#    #+#             */
/*   Updated: 2024/02/20 18:52:05 by bjandri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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
	mlx_loop(game.mlx);
	return (0);
}
