/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjandri <bjandri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 11:14:50 by bjandri           #+#    #+#             */
/*   Updated: 2024/02/04 12:48:20 by bjandri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int move_game(int keycode, t_game *game)
{
    if (keycode == ESC)
    {
        mlx_destroy_window(game->mlx, game->win);
        exit(0);
    }
    int new_x  =  game->player_x;
    int new_y =  game->player_y;
    if(keycode == RIGHT || keycode == D)
    {
        game->player_y += 1;
        game->moves++;
        ft_printf("Moves = %d\n", game->moves);
        mlx_put_image_to_window(game->mlx, game->win, game->floor, new_y * 64, new_x * 64);
        mlx_put_image_to_window(game->mlx, game->win, game->player, game->player_y  * 64, game->player_x * 64);
    }
    if(keycode == LEFT || keycode == A)
    {
        game->player_y -= 1;
        game->moves++;
        ft_printf("Moves = %d\n", game->moves);
        mlx_put_image_to_window(game->mlx, game->win, game->floor, new_y * 64, new_x * 64);
        mlx_put_image_to_window(game->mlx, game->win, game->player, game->player_y  * 64, game->player_x * 64);
    }    
    if(keycode == DOWN || keycode == S)
    {
        game->player_x += 1;
        game->moves++;
        ft_printf("Moves = %d\n", game->moves);
        mlx_put_image_to_window(game->mlx, game->win, game->floor, new_y * 64, new_x * 64);
        mlx_put_image_to_window(game->mlx, game->win, game->player, game->player_y  * 64, game->player_x * 64);
    }    
    if(keycode == UP || keycode == W)
    {
        game->player_x -= 1;
        game->moves++;
        ft_printf("Moves = %d\n", game->moves);
        mlx_put_image_to_window(game->mlx, game->win, game->floor, new_y * 64, new_x * 64);
        mlx_put_image_to_window(game->mlx, game->win, game->player, game->player_y  * 64, game->player_x * 64);
    }
    return 0;
    
    return  0;
}
