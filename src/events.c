/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjandri <bjandri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 11:14:50 by bjandri           #+#    #+#             */
/*   Updated: 2024/02/03 14:54:05 by bjandri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// int move_player(t_game *game, int keycode)
// {
//     int new_x = game->player.x;
//     int new_y = game->player.y;

//     if (keycode == UP || keycode == W)
//     {
//         new_y--;
//     }
//     else if(keycode == ESC)
//     {
//         mlx_destroy_window(game->mlx, game->win);
//     }
//     if (is_valid_move(game, new_x, new_y))
//     {
//         game->player.x = new_x;
//         game->player.y = new_y;
//     }
//     return (0);
// }

// int is_valid_move(t_game *game, int x, int y)
// {
//     if (x > 0 && x < game->map.x && y >= 0 && y < game->map.y)
//     {
//         if (game->map.all_map[x][y] != WALL)
//         {
//             return 1;
//         }
//     }
//     return 0;
// }


int	ft_close(int keycode, t_game *game)
{
    if(keycode == ESC)
    {
	    mlx_destroy_window(game->mlx, game->win);
    }
	return (0);
}