/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_verify.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlermo-j <mlermo-j@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/05 12:54:10 by mlermo-j          #+#    #+#             */
/*   Updated: 2026/05/05 12:54:11 by mlermo-j         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/**
 * @brief Validates a single cell in the map grid, checking for valid characters
 * and ensuring that the player's starting position is correctly defined.
 * @param game Pointer to the game structure containing the game information.
 * @param row The row index of the cell to validate.
 * @param col The column index of the cell to validate.
 */
void	validate_map_cell(t_game *game, int row, int col)
{
	char	cell;

	cell = game->map.grid[row][col];
	if (cell == '\n' || cell == '\r' || cell == '\0')
		return ;
	if (cell == '\t')
		fperror(game, "Tabs are not allowed in the map, use spaces.");
	if (cell == ' ' || cell == '1')
		return ;
	if (cell == '0' || cell == 'N' || cell == 'S'
		|| cell == 'E' || cell == 'W')
	{
		check_player(game, cell, row, col);
	}
	else
		fperror(game, "Invalid character in map");
}

/**
 * @brief Performs a flood fill algorithm to check if the map is properly
 * enclosed.
 * @param map_copy A copy of the map grid to perform the flood fill on.
 * @param game Pointer to the game structure containing the game information.
 * @param row The current row index for the flood fill.
 * @param col The current column index for the flood fill.
 * @return 1 if the flood fill reaches an invalid area (indicating the map is
 * not enclosed), or 0 if the flood fill successfully fills the area without
 * reaching an invalid area.
 */
int	fill(char **map_copy, t_game *game, int row, int col)
{
	if (row < 0 || col < 0 || row >= game->map.height
		|| col >= game->map.width)
		return (1);
	if (map_copy[row][col] == ' ')
		return (1);
	if (map_copy[row][col] == '1' || map_copy[row][col] == 'F')
		return (0);
	map_copy[row][col] = 'F';
	if (fill(map_copy, game, row - 1, col))
		return (1);
	if (fill(map_copy, game, row + 1, col))
		return (1);
	if (fill(map_copy, game, row, col - 1))
		return (1);
	if (fill(map_copy, game, row, col + 1))
		return (1);
	return (0);
}

/**
 * @brief Performs a flood fill check on the map to ensure that it is properly
 * enclosed.
 * @param game Pointer to the game structure containing the game information.
 * @param map_copy A copy of the map grid to perform the flood fill on.
 */
void	flood_fill_check(t_game *game, char **map_copy)
{
	int	start_x;
	int	start_y;

	start_x = (int)game->player.pos.x;
	start_y = (int)game->player.pos.y;
	if (fill(map_copy, game, start_y, start_x))
	{
		draw_colored_grid(game, map_copy);
		free_double_p(map_copy);
		fperror(game, "Flood fill error: Map is not perfectly closed");
	}
	else
		ft_printf(2, "Map completely closed!\n");
}

/**
 * @brief Creates a copy of the map grid, which can be used for operations like
 * flood fill without modifying the original map data.
 * @param game Pointer to the game structure containing the game information.
 * @return A newly allocated copy of the map grid, or NULL if a memory
 * allocation error occurs.
 */
char	**copy_map(t_game *game)
{
	char	**copy;
	int		i;

	copy = malloc(sizeof(char *) * (game->map.height + 1));
	if (!copy)
		return (NULL);
	i = 0;
	while (i < game->map.height)
	{
		copy[i] = ft_strdup(game->map.grid[i]);
		if (!copy[i])
		{
			free_double_p(copy);
			return (NULL);
		}
		i++;
	}
	copy[i] = NULL;
	return (copy);
}

/**
 * @brief Validates the entire map by checking for rectangular shape, valid
 * characters, and ensuring that the map is properly enclosed. The function 
 * also checks for the presence of a single player starting position and sets 
 * the player's initial direction and camera plane based on the map data.
 * @param game Pointer to the game structure containing the game information.
 */
void	validate_map(t_game *game)
{
	char	**map_copy;

	if (!rectangular_grid(game))
		fperror(game, "Failed to create rectangular grid / Malloc error");
	game->player_count = 0;
	itermap(game, validate_map_cell);
	if (game->player_count == 0)
		fperror(game, "Missing player starting position");
	map_copy = copy_map(game);
	if (!map_copy)
		fperror(game, "Malloc falló en la copia del mapa");
	flood_fill_check(game, map_copy);
	free_double_p(map_copy);
}
