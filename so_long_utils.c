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