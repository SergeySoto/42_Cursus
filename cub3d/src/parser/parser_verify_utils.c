/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_verify_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlermo-j <mlermo-j@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/05 12:54:08 by mlermo-j          #+#    #+#             */
/*   Updated: 2026/05/05 12:59:47 by mlermo-j         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/**
 * @brief Calculates the width and height of the map grid based on the current
 * map data. The function iterates through the map grid to determine the maximum
 * width of any row and counts the total number of rows to set the height.
 * @param game Pointer to the game structure containing the game information.
 */
void	calculate_width_and_height(t_game *game)
{
	int	i;
	int	len;

	i = 0;
	while (game->map.grid && game->map.grid[i])
	{
		len = ft_strlen(game->map.grid[i]);
		if (len > 0 && game->map.grid[i][len - 1] == '\n')
			len--;
		if (len > game->map.width)
			game->map.width = len;
		i++;
	}
	game->map.height = i;
}

/**
 * @brief Checks if the map grid is rectangular by ensuring that all rows have
 * the same width. The function iterates through the map grid and compares the
 * length of each row to the expected width, returning 0 if any row does not
 * match the expected width.
 * @param game Pointer to the game structure containing the game information.
 * @return 1 if the grid is rectangular, 0 otherwise.
 */
int	rectangular_grid(t_game *game)
{
	int		i;
	char	**new_grid;
	size_t	old_len;

	calculate_width_and_height(game);
	new_grid = ft_calloc(game->map.height + 1, sizeof(char *));
	if (!new_grid)
		return (0);
	i = -1;
	while (game->map.grid && game->map.grid[++i])
	{
		new_grid[i] = malloc(sizeof(char) * (game->map.width + 1));
		if (!new_grid[i])
			return (0);
		ft_memset(new_grid[i], ' ', game->map.width);
		new_grid[i][game->map.width] = '\0';
		old_len = ft_strlen(game->map.grid[i]);
		if (old_len > 0 && game->map.grid[i][old_len - 1] == '\n')
			old_len--;
		ft_memcpy(new_grid[i], game->map.grid[i], old_len);
	}
	free_double_p(game->map.grid);
	game->map.grid = new_grid;
	return (1);
}

/**
 * @brief Iterates through each cell in the map grid and applies the provided
 * function to each cell. This is a utility function that allows for easy
 * application of a specific operation to every cell in the grid, such as 
 * validation or modification.
 * @param game Pointer to the game structure containing the game information.
 * @param func A pointer to a function that takes a game pointer and two
 * integers (row and column indices) as parameters. 
 * This function will be called for each cell in the grid.
 */
void	itermap(t_game *game, void (*func)(t_game *, int, int))
{
	int	i;
	int	j;

	i = 0;
	while (game->map.grid && game->map.grid[i])
	{
		j = 0;
		while (game->map.grid[i][j])
		{
			func(game, i, j);
			j++;
		}
		i++;
	}
}

/**
 * @brief Sets the player's initial direction and camera plane based on the
 * starting orientation specified in the map (N, S, E, W).
 * @param game Pointer to the game structure containing the game information.
 * @param cell The character representing the player's starting 
 * orientation ('N', 'S', 'E', 'W').
 */
void	set_player_orientation(t_game *game, char cell)
{
	int							i;
	static const t_config_dir	cfg[] = {
	{'N', 0.0, -1.0, 0.66, 0.0},
	{'S', 0.0, 1.0, -0.66, 0.0},
	{'E', 1.0, 0.0, 0.0, 0.66},
	{'W', -1.0, 0.0, 0.0, -0.66}
	};

	i = 0;
	while (i < 4)
	{
		if (cfg[i].key == cell)
		{
			game->player.dir.x = cfg[i].dir_x;
			game->player.dir.y = cfg[i].dir_y;
			game->player.plane.x = cfg[i].plane_x;
			game->player.plane.y = cfg[i].plane_y;
			return ;
		}
		i++;
	}
}

/**
 * @brief Checks if the current cell in the map grid contains a player starting
 * position (N, S, E, W).
 * @param game Pointer to the game structure containing the game information.
 * @param cell The character representing the current cell in the map grid.
 * @param row The row index of the current cell.
 * @param col The column index of the current cell.
 */
void	check_player(t_game *game, char cell, int row, int col)
{
	if (cell == 'N' || cell == 'S' || cell == 'E' || cell == 'W')
	{
		game->player_count++;
		if (game->player_count > 1)
			fperror(game, "Multiple player starting positions");
		game->player.pos.x = (double)col + 0.5;
		game->player.pos.y = (double)row + 0.5;
		set_player_orientation(game, cell);
		game->map.grid[row][col] = '0';
	}
}
