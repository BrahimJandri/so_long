/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy_game.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjandri <bjandri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 09:30:53 by bjandri           #+#    #+#             */
/*   Updated: 2024/02/10 15:12:21 by bjandri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	destroy_game(t_game *game)
{
	mlx_destroy_image(game->mlx, game->coin);
	mlx_destroy_image(game->mlx, game->p_back);
	mlx_destroy_image(game->mlx, game->p_front);
	mlx_destroy_image(game->mlx, game->p_left);
	mlx_destroy_image(game->mlx, game->p_right);
	mlx_destroy_image(game->mlx, game->wall);
	mlx_destroy_image(game->mlx, game->floor);
	mlx_destroy_image(game->mlx, game->exit);
	mlx_destroy_window(game->mlx, game->win);
}
