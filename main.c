/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carmoliv <carmoliv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/06 22:45:31 by carmoliv          #+#    #+#             */
/*   Updated: 2026/01/08 20:06:23 by carmoliv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	init_game(t_game *game, char *map_path)
{
	game->map = read_map(map_path, game);
	if (!game->map)
		return (write(2, "Error: Failed to load map\n", 27), 0);
	if (!validate_map(game))
		return (free_map(game->map), 0);
	return (1);
}

static int	init_mlx(t_game_mlx *mlx_data, t_game *game)
{
	mlx_data->game = game;
	mlx_data->moves = 0;
	mlx_data->mlx = mlx_init();
	if (!mlx_data->mlx)
		return (write(2, "Error: Failed to initialize MLX\n", 32), 0);
	return (1);
}

static int	create_window(t_game_mlx *mlx_data)
{
	mlx_data->win = mlx_new_window(
			mlx_data->mlx,
			mlx_data->game->width * TILE_SIZE,
			mlx_data->game->height * TILE_SIZE,
			"so_long");
	if (!mlx_data->win)
		return (write(2, "Error: Failed to create window\n", 31), 0);
	return (1);
}

static int	loading_images(t_game_mlx *mlx_data)
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
	if (!mlx_data->img.wall || !mlx_data->img.floor
		|| !mlx_data->img.player || !mlx_data->img.collect
		|| !mlx_data->img.exit)
		return (write(2,
				"Error: Failed to load one or more images\n", 42), 0);
	return (1);
}

int	main(int argc, char **argv)
{
	t_game		game;
	t_game_mlx	mlx_data;

	if (argc != 2)
		return (write(2, "Usage: ./so_long <map.ber>\n", 27), 1);
	if (!init_game(&game, argv[1]))
		return (1);
	if (!init_mlx(&mlx_data, &game))
		return (free_map(game.map), 1);
	if (!create_window(&mlx_data))
		return (free_map(game.map), 1);
	if (!loading_images(&mlx_data))
		return (free_map(game.map), 1);
	draw_map(&mlx_data);
	mlx_hook(mlx_data.win, 2, 1L << 0, key_hook, &mlx_data);
	mlx_hook(mlx_data.win, 17, 0, close_game, &mlx_data);
	mlx_loop(mlx_data.mlx);
	free_map(game.map);
	return (0);
}


/*int	main(int argc, char **argv)
{
	t_game		game;
	t_game_mlx	mlx_data;
	int			w;
	int			h;

	if (argc != 2)
	{
		write(2, "Usage: ./so_long <map.ber>\n", 27);
		return (1);
	}
	game.map = read_map(argv[1], &game);
	if (!game.map)
	{
		write(2, "Error: Failed to load map\n", 27);
		return (1);
	}
	if (!validate_map(&game))
	{
		free_map(game.map);
		return (1);
	}
	mlx_data.game = &game;
	mlx_data.moves = 0;
	mlx_data.mlx = mlx_init();
	if (!mlx_data.mlx)
	{
		write(2, "Error: Failed to initialize MLX\n", 32);
		free_map(game.map);
		return (1);
	}
	mlx_data.win = mlx_new_window(mlx_data.mlx,
			game.width * TILE_SIZE,
			game.height * TILE_SIZE,
			"so_long");
	if (!mlx_data.win)
	{
		write(2, "Error: Failed to create window\n", 31);
		free_map(game.map);
		return (1);
	}
	mlx_data.img.wall = mlx_xpm_file_to_image(mlx_data.mlx,
			"images/wall.xpm", &w, &h);
	mlx_data.img.floor = mlx_xpm_file_to_image(mlx_data.mlx,
			"images/floor.xpm", &w, &h);
	mlx_data.img.player = mlx_xpm_file_to_image(mlx_data.mlx,
			"images/player.xpm", &w, &h);
	mlx_data.img.collect = mlx_xpm_file_to_image(mlx_data.mlx,
			"images/collect.xpm", &w, &h);
	mlx_data.img.exit = mlx_xpm_file_to_image(mlx_data.mlx,
			"images/exit.xpm", &w, &h);
	if (!mlx_data.img.wall || !mlx_data.img.floor || !mlx_data.img.player
		|| !mlx_data.img.collect || !mlx_data.img.exit)
	{
		write(2, "Error: Failed to load one or more images\n", 42);
		free_map(game.map);
		return (1);
	}
	draw_map(&mlx_data);
	mlx_do_sync(mlx_data.mlx);
	mlx_hook(mlx_data.win, 2, 1L << 0, key_hook, &mlx_data);
	mlx_hook(mlx_data.win, 17, 0, close_game, &mlx_data);
	mlx_loop(mlx_data.mlx);
	free_map(game.map);
	return (0);
}*/
