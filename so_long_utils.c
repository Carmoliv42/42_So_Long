/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carmoliv <carmoliv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/06 22:45:10 by carmoliv          #+#    #+#             */
/*   Updated: 2026/01/06 22:45:17 by carmoliv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int so_strlen(char *str)
{
    int i;

    i = 0;
    while (str[i])
        i++;
    return i;
}

void free_map(char **map)
{
    int i;

    i = 0;
    if (!map)
        return;
    while (map[i])
        free(map[i++]);
    free(map);
}

void	init_counts(t_game *game)
{
	game->player_count = 0;
	game->exit_count = 0;
	game->collect_count = 0;
}

void destroy_images(t_game_mlx *mlx)
{
    mlx_destroy_image(mlx->mlx, mlx->img.wall);
    mlx_destroy_image(mlx->mlx, mlx->img.floor);
    mlx_destroy_image(mlx->mlx, mlx->img.player);
    mlx_destroy_image(mlx->mlx, mlx->img.collect);
    mlx_destroy_image(mlx->mlx, mlx->img.exit);
}

int close_game(t_game_mlx *mlx)
{
    destroy_images(mlx);
    mlx_destroy_window(mlx->mlx, mlx->win);
    mlx_destroy_display(mlx->mlx);
    free(mlx->mlx);
    free_map(mlx->game->map);
    exit(0);
}