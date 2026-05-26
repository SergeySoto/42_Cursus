/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debugger.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlermo-j <mlermo-j@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/05 12:54:44 by mlermo-j          #+#    #+#             */
/*   Updated: 2026/05/05 12:54:45 by mlermo-j         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/**
 * @brief Prints a single cell of the map grid with color coding for debugging
 * purposes. The function uses ANSI escape codes to color the output based on
 * the cell value and whether it has been marked as flooded during the flood
 * fill algorithm.
 * @param val The character value of the cell to print.
 * @param flood The character indicating whether the cell has been flooded ('F')
 * or not.
 */
void	print_cell(char val, char flood)
{
	if (flood == 'F' && (val == '0' || val == ' '))
	{
		if (val == ' ')
			ft_printf(2, RED "~" RESET);
		else
			ft_printf(2, RED "%c" RESET, val);
	}
	else if (val == '1')
		ft_printf(2, GREEN "%c" RESET, val);
	else if (val == 'N' || val == 'S' || val == 'E' || val == 'W')
		ft_printf(2, RED "%c" RESET, val);
	else
		ft_printf(2, "%c", val);
}

/**
 * @brief Draws the map grid to the standard output with color coding for
 * debugging purposes. The function iterates through the map grid and prints
 * each cell using the print_cell function, which applies color coding based on
 * the cell value and flood fill status.
 * @param game Pointer to the game structure containing the game information.
 * @param map_copy A copy of the map grid that contains flood fill markings, or
 * NULL if no flood fill markings are available.
 */
void	draw_colored_grid(t_game *game, char **map_copy)
{
	int	j;
	int	i;

	i = 0;
	ft_printf(1, "\n=============== MAP GRID  =================\n");
	while (i < game->map.height)
	{
		j = 0;
		if (game->map.grid[i])
		{
			ft_printf(2, "[%2d]: ", i);
			while (game->map.grid[i][j])
			{
				if (map_copy != NULL)
					print_cell(game->map.grid[i][j], map_copy[i][j]);
				else
					print_cell(game->map.grid[i][j], 0);
				j++;
			}
			ft_printf(2, "\n");
		}
		i++;
	}
	ft_printf(2, "===========================================\n\n");
}

/**
 * @brief Prints the parsed configuration data, including map dimensions, floor
 * and ceiling colors, texture loading status, and player position.
 * @param game Pointer to the game structure containing the game information.
 */
void	debug_print_parsed_data(t_game *game)
{
	int	i;

	ft_printf(2, "\n=============== CUB3D DEBUG ===============\n");
	ft_printf(2, "Dimensions : W: %d, H: %d\n", game->map.width,
		game->map.height);
	ft_printf(2, "Floor      : 0x%08X\n", game->map.floor_color);
	ft_printf(2, "Ceiling    : 0x%08X\n", game->map.ceiling_color);
	i = 0;
	while (i < 4)
	{
		if (game->map.textures[i])
			ft_printf(2, "Tex [%d]    : OK\n", i);
		else
			ft_printf(2, "Tex [%d]    : NULL\n", i);
		i++;
	}
	ft_printf(2, "Player Pos : x = %.1f, y = %.1f\n",
		game->player.pos.x, game->player.pos.y);
	draw_colored_grid(game, NULL);
}
