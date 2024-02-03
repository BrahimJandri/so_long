/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjandri <bjandri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/13 17:55:23 by bjandri           #+#    #+#             */
/*   Updated: 2024/02/03 14:55:04 by bjandri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	t_game	game;
	
	if (argc != 2)
		error_msg("Error\nInvalid number of arguments", &game);
	game.map.exit = 0;
	game.map.floor = 0;
	game.map.coins = 0;
	game.map.players = 0;
	game.mlx = mlx_init();
	read_map(&game, argv[1]);
	mlx_hook(game.win, 2, 1L<<0, close, &game);
	return (0);
}
