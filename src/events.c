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

static void update_player_position(t_game *game, int new_x, int new_y)
{
    if (is_valid_move(game, new_x, new_y))
    {
        game->player.x = new_x;
        game->player.y = new_y;
    }
}

static void handle_movement(t_game *game, int keycode, int *new_x, int *new_y)
{
    if (keycode == UP || keycode == W)
    {
        *new_y = game->player.y - 1;
    }
    else if (keycode == DOWN || keycode == S)
    {
        *new_y = game->player.y + 1;
    }
    else if (keycode == LEFT || keycode == A)
    {
        *new_x = game->player.x - 1;
    }
    else if (keycode == RIGHT || keycode == D)
    {
        *new_x = game->player.x + 1;
    }
}

int is_valid_move(t_game *game, int x, int y)
{
    if (x > 0 && x < game->map.x && y >= 0 && y < game->map.y)
    {
        if (game->map.all_map[x][y] != WALL)
        {
            return 1;
        }
    }
    return 0;
}

int move_player(t_game *game, int keycode)
{
    int new_x = game->player.x;
    int new_y = game->player.y;

    handle_movement(game, keycode, &new_x, &new_y);

    if (keycode == ESC)
    {
        mlx_destroy_window(game->mlx, game->win);
    }
    update_player_position(game, new_x, new_y);

    return (0);
}