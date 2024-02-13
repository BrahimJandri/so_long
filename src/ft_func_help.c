/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_func_help.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjandri <bjandri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 11:30:35 by bjandri           #+#    #+#             */
/*   Updated: 2024/02/13 17:51:22 by bjandri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	error_msg(char *msg)
{
	ft_printf("%s\n", msg);
	exit(EXIT_FAILURE);
}

int	check_path(const char *filename)
{
	size_t	len;

	len = ft_strlen(filename);
	if (len >= 4 && ft_strncmp(filename + len - 4, ".ber", 4) == 0)
		return (1);
	else
		return (0);
}

void	free_all(t_game *game)
{
	int	i;

	i = 0;
	while (game->map[i])
	{
		free(game->map[i]);
		i++;
	}
	i = 0;
	while (game->visited[i])
	{
		free(game->visited[i]);
		i++;
	}
	free(game->map);
	free(game);
	free(game->visited);
}

int	ft_exit(void)
{
	exit(1);
	return (0);
}
