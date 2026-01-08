/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carmoliv <carmoliv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/08 19:46:57 by carmoliv          #+#    #+#             */
/*   Updated: 2026/01/08 19:50:52 by carmoliv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>
# include <string.h>
# include "mlx_linux/mlx.h"
# include "GNL/get_next_line.h"
# include "ft_printf/ft_printf.h"

# define TILE_SIZE 32

typedef struct s_game
{
	char	**map;
	int		width;
	int		height;
	int		player_count;
	int		exit_count;
	int		collect_count;
}	t_game;

typedef struct s_img
{
	void	*wall;
	void	*floor;
	void	*player;
	void	*collect;
	void	*exit;
}	t_img;

typedef struct s_game_mlx
{
	t_game	*game;
	void	*mlx;
	void	*win;
	t_img	img;
	int		player_x;
	int		player_y;
	int		moves;
}	t_game_mlx;

// map
char	**read_map(const char *file, t_game *game);
void	free_map(char **map);
int		so_strlen(char *str);

// validation
int		validate_map(t_game *game);
void	init_counts(t_game *game);

// mlx
void	draw_map(t_game_mlx *mlx_data);
int		key_hook(int keycode, t_game_mlx *mlx_data);
void	move_player(t_game_mlx *mlx_data, int dx, int dy);
int		load_images(t_game_mlx *mlx_data);
void	draw_tile(t_game_mlx *mlx_data, char c, int x, int y);
int		can_move(t_game_mlx *mlx_data, char next);
void	update_player(t_game_mlx *mlx_data, int new_x, int new_y, char next);
void	check_win(t_game_mlx *mlx_data, char next);
int		close_game(t_game_mlx *mlx);
void	destroy_images(t_game_mlx *mlx);

#endif
