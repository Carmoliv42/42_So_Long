/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carmoliv <carmoliv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/06 22:45:26 by carmoliv          #+#    #+#             */
/*   Updated: 2026/01/06 22:45:29 by carmoliv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int check_rectangle(t_game *game)
{
    int i;

    i = 0;
    while (i < game->height)
    {
        if (so_strlen(game->map[i]) != game->width)
            return 0;
        i++;
    }
    return 1;
}

static int check_walls(t_game *game)
{
    int i;
    int j;

    i = 0;
    j = 0;
    while(j < game->width)
    {
        if (game->map[0][j] != '1' || game->map[game->height - 1][j] != '1')
            return (0);
        j++;
    }
    while(i < game->height)
    {
        if (game->map[i][0] != '1' || game->map[i][game->width - 1] != '1')
            return (0);
        i++;
    }
    return 1;
}

static int	check_char(t_game *game, char c)
{
	if (c == 'P')
		game->player_count++;
	else if (c == 'E')
		game->exit_count++;
	else if (c == 'C')
		game->collect_count++;
	else if (c != '0' && c != '1')
		return (0);
	return (1);
}

static int	check_chars(t_game *game)
{
	int		i;
	int		j;
	char	c;

	i = 0;
	init_counts(game);
	while (i < game->height)
	{
		j = 0;
		while (j < game->width)
		{
			c = game->map[i][j];
			if (!check_char(game, c))
				return (0);
			j++;
		}
		i++;
	}
	if (game->player_count != 1 || game->exit_count != 1
		|| game->collect_count < 1)
		return (0);
	return (1);
}

int validate_map(t_game *game)
{
    if (!check_rectangle(game))
    {
        write(2, "Error\nMap is not rectangular\n", 29);
        free_map(game->map);
        exit(1);
    }
    if (!check_walls(game))
    {
        write(2, "Error\nMap is not surrounded by walls\n", 37);
        free_map(game->map);
        exit(1);
    }
    if (!check_chars(game))
    {
        write(2, "Error\nInvalid characters or wrong counts\n", 41);
        free_map(game->map);
        exit(1);
    }
    return 1;
}
