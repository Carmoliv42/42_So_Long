/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carmoliv <carmoliv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/06 22:45:26 by carmoliv          #+#    #+#             */
/*   Updated: 2026/01/11 15:25:50 by carmoliv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static	int	check_rectangle(t_game *game)
{
	int	i;

	i = 0;
	while (i < game->height)
	{
		if (so_strlen(game->map[i]) != game->width)
			return (0);
		i++;
	}
	return (1);
}

static	int	check_walls(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (j < game->width)
	{
		if (game->map[0][j] != '1' || game->map[game->height - 1][j] != '1')
			return (0);
		j++;
	}
	while (i < game->height)
	{
		if (game->map[i][0] != '1' || game->map[i][game->width - 1] != '1')
			return (0);
		i++;
	}
	return (1);
}

static	int	count_chars(t_game *game)
{
	int	i;
	int	j;

	i = -1;
	while (++i < game->height)
	{
		j = -1;
		while (++j < game->width)
		{
			if (game->map[i][j] == 'P')
				game->player_count++;
			else if (game->map[i][j] == 'E')
				game->exit_count++;
			else if (game->map[i][j] == 'C')
				game->collect_count++;
			else if (game->map[i][j] != '0' && game->map[i][j] != '1')
				return (1);
		}
	}
	return (0);
}

static	int	check_chars(t_game *game)
{
	init_counts(game);
	if (count_chars(game) != 0)
		return (1);
	if (game->player_count != 1)
		return (2);
	if (game->exit_count != 1)
		return (3);
	if (game->collect_count < 1)
		return (4);
	return (0);
}

int	validate_map(t_game *game)
{
	const char	*errors[] = {
		"Error\nMap is not rectangular\n",
		"Error\nMap is not surrounded by walls\n",
		"Error\nInvalid character in map\n",
		"Error\nMap must have exactly 1 player (P)\n",
		"Error\nMap must have exactly 1 exit (E)\n",
		"Error\nMap must have at least 1 collectible (C)\n"
	};
	const int	sizes[] = {29, 37, 31, 41, 39, 47};
	int			error;

	if (!check_rectangle(game))
		error = 0;
	else if (!check_walls(game))
		error = 1;
	else
	{
		error = check_chars(game);
		if (error == 0)
			return (1);
		error += 1;
	}
	write(2, errors[error], sizes[error]);
	free_map(game->map);
	exit(1);
}
