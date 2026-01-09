/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func_cap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carmoliv <carmoliv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/06 22:45:34 by carmoliv          #+#    #+#             */
/*   Updated: 2026/01/08 20:07:49 by carmoliv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	move_player(t_game_mlx *mlx_data, int dx, int dy)
{
	int		x;
	int		y;
	int		new_x;
	int		new_y;
	char	next;

	x = mlx_data->player_x;
	y = mlx_data->player_y;
	new_x = x + dx;
	new_y = y + dy;
	next = mlx_data->game->map[new_y][new_x];
	if (!can_move(mlx_data, next))
		return ;
	update_player(mlx_data, new_x, new_y, next);
	check_win(mlx_data, next);
}

int	key_hook(int keycode, t_game_mlx *mlx_data)
{
	if (keycode == 65307)
		close_game(mlx_data);
	else if (keycode == 119)
		move_player(mlx_data, 0, -1);
	else if (keycode == 115)
		move_player(mlx_data, 0, 1);
	else if (keycode == 97)
		move_player(mlx_data, -1, 0);
	else if (keycode == 100)
		move_player(mlx_data, 1, 0);
	return (0);
}

/*int	load_images(t_game_mlx *mlx_data)
{
	int	w;
	int	h;

	mlx_data->img.wall = mlx_xpm_file_to_image(mlx_data->mlx,
			"images/wall.xpm", &w, &h);
	mlx_data->img.floor = mlx_xpm_file_to_image(mlx_data->mlx,
			"images/floor.xpm", &w, &h);
	mlx_data->img.player = mlx_xpm_file_to_image(mlx_data->mlx,
			"images/player.xpm", &w, &h);
	mlx_data->img.collect = mlx_xpm_file_to_image(mlx_data->mlx,
			"images/collect.xpm", &w, &h);
	mlx_data->img.exit = mlx_xpm_file_to_image(mlx_data->mlx,
			"images/exit.xpm", &w, &h);
	if (!mlx_data->img.wall || !mlx_data->img.floor || !mlx_data->img.player
		|| !mlx_data->img.collect || !mlx_data->img.exit)
		return (0);
	return (1);
}*/
