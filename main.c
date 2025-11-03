#include "so_long.h"

int main(int argc, char **argv)
{
    t_game game;
    t_game_mlx mlx_data;
    int i;

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

    ft_printf("Mapa válido! %dx%d\n", game.width, game.height);
    for (i = 0; game.map[i]; i++)
        ft_printf("%s\n", game.map[i]);

    // Inicializa MLX
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

    // Carrega imagens com checagem
    int w;
    int h;
    
    mlx_data.img.wall    = mlx_xpm_file_to_image(mlx_data.mlx, "images/wall.xpm", &w, &h);
    mlx_data.img.floor   = mlx_xpm_file_to_image(mlx_data.mlx, "images/floor.xpm", &w, &h);
    mlx_data.img.player  = mlx_xpm_file_to_image(mlx_data.mlx, "images/player.xpm", &w, &h);
    mlx_data.img.collect = mlx_xpm_file_to_image(mlx_data.mlx, "images/collect.xpm", &w, &h);
    mlx_data.img.exit    = mlx_xpm_file_to_image(mlx_data.mlx, "images/exit.xpm", &w, &h);

    if (!mlx_data.img.wall || !mlx_data.img.floor || !mlx_data.img.player ||
        !mlx_data.img.collect || !mlx_data.img.exit)
    {
        write(2, "Error: Failed to load one or more images\n", 42);
        free_map(game.map);
        return (1);
    }

    // Desenha o mapa
    draw_map(&mlx_data);
    mlx_do_sync(mlx_data.mlx);  // força atualização no X server WSL

    // Hook teclado
    mlx_hook(mlx_data.win, 2, 1L<<0, key_hook, &mlx_data);

    // Loop principal
    mlx_loop(mlx_data.mlx);

    free_map(game.map);
    return (0);
}
