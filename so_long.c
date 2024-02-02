/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjandri <bjandri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/13 17:55:23 by bjandri           #+#    #+#             */
/*   Updated: 2024/02/02 11:25:37 by bjandri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	t_game game;

	if (argc != 2)
		error_msg("Error\nInvalid number of arguments", &game);
	game.mlx = mlx_init();
	read_map(&game, argv[1]);
	return (0);
}