/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjandri <bjandri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/13 17:55:23 by bjandri           #+#    #+#             */
/*   Updated: 2024/02/05 17:22:32 by bjandri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_path(const char *filename)
{
	size_t	len;

	len = ft_strlen(filename);
	if (len >= 4 && ft_strncmp(filename + len - 4, ".ber", 4) == 0)
		return (1);
	else
		return (0);
}

int	main(int argc, char **argv)
{
	t_game	game;

	if (argc != 2)
		error_msg("Error\nInvalid number of arguments");
	else if (!check_path(argv[1]))
		error_msg("Error\nInvalid Extension of map Should be .ber");
	game.map_exit = 0;
	game.map_floor = 0;
	game.map_coins = 0;
	game.map_player = 0;
	game.moves = 0;
	game.height = 64;
	game.width = 64;
	game.coins_reach = 0;
	game.exit_reach = 0;
	game.count_coins = 0;
	game.mlx = mlx_init();
	read_map(&game, argv[1]);
	return (0);
}
