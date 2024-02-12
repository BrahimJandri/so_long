/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_img.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjandri <bjandri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/11 11:29:50 by bjandri           #+#    #+#             */
/*   Updated: 2024/02/12 12:14:33 by bjandri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_put_img_down(int i, int j, t_game *game)
{
	game->floor = mlx_xpm_file_to_image(game->mlx, FLOOR_SPRITE, &game->height,
			&game->width);
	mlx_put_image_to_window(game->mlx, game->win, game->floor, i * 64, j * 64);
	mlx_put_image_to_window(game->mlx, game->win, game->p_front, game->player_y
		* 64, game->player_x * 64);
}

void	ft_put_img_up(int i, int j, t_game *game)
{
	game->p_back = mlx_xpm_file_to_image(game->mlx, P_BACK, &game->height,
			&game->width);
	mlx_put_image_to_window(game->mlx, game->win, game->floor, i * 64, j * 64);
	mlx_put_image_to_window(game->mlx, game->win, game->p_back, game->player_y
		* 64, game->player_x * 64);
}

void	ft_put_img_left(int i, int j, t_game *game)
{
	game->p_left = mlx_xpm_file_to_image(game->mlx, P_LEFT, &game->height,
			&game->width);
	mlx_put_image_to_window(game->mlx, game->win, game->floor, i * 64, j * 64);
	mlx_put_image_to_window(game->mlx, game->win, game->p_left, game->player_y
		* 64, game->player_x * 64);
}

void	ft_put_img_right(int i, int j, t_game *game)
{
	game->p_right = mlx_xpm_file_to_image(game->mlx, P_RIGHT, &game->height,
			&game->width);
	mlx_put_image_to_window(game->mlx, game->win, game->floor, i * 64, j * 64);
	mlx_put_image_to_window(game->mlx, game->win, game->p_right, game->player_y
		* 64, game->player_x * 64);
}
