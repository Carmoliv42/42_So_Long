#include "so_long.h"

// Desenha uma célula do mapa
void draw_tile(t_game_mlx *mlx_data, char c, int x, int y)
{
    mlx_put_image_to_window(mlx_data->mlx, mlx_data->win, mlx_data->img.floor, x, y);
    if (c == '1')
        mlx_put_image_to_window(mlx_data->mlx, mlx_data->win, mlx_data->img.wall, x, y);
    else if (c == 'P')
    {
        mlx_put_image_to_window(mlx_data->mlx, mlx_data->win, mlx_data->img.player, x, y);
        mlx_data->player_x = x / TILE_SIZE;
        mlx_data->player_y = y / TILE_SIZE;
    }
    else if (c == 'C')
        mlx_put_image_to_window(mlx_data->mlx, mlx_data->win, mlx_data->img.collect, x, y);
    else if (c == 'E')
        mlx_put_image_to_window(mlx_data->mlx, mlx_data->win, mlx_data->img.exit, x, y);
}

// Desenha o mapa completo
void draw_map(t_game_mlx *mlx_data)
{
    int i;
    int j;

    i = 0;
    while (i < mlx_data->game->height)
    {
        j = 0;
        while (j < mlx_data->game->width)
        {
            draw_tile(mlx_data, mlx_data->game->map[i][j], j * TILE_SIZE, i * TILE_SIZE);
            j++;
        }
        i++;
    }
}

// Função que move o jogador
int	can_move(t_game_mlx *mlx_data, char next)
{
	if (next == '1')
		return (0);
	if (next == 'E' && mlx_data->game->collect_count > 0)
		return (0);
	return (1);
}

void	update_player(t_game_mlx *mlx_data, int new_x, int new_y, char next)
{
	int	x;
	int	y;

	x = mlx_data->player_x;
	y = mlx_data->player_y;
	if (next == 'C')
		mlx_data->game->collect_count--;
	mlx_data->game->map[y][x] = '0';
	mlx_data->game->map[new_y][new_x] = 'P';
	mlx_data->player_x = new_x;
	mlx_data->player_y = new_y;
	mlx_data->moves++;
	ft_printf("Movimentos: %d\n", mlx_data->moves);
	draw_map(mlx_data);
}

void	check_win(t_game_mlx *mlx_data, char next)
{
	if (next == 'E' && mlx_data->game->collect_count == 0)
	{
		ft_printf("Parabéns! Você venceu!\n");
		mlx_destroy_window(mlx_data->mlx, mlx_data->win);
		exit(0);
	}
}