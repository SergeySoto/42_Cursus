/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debugger_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlermo-j <mlermo-j@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/05 12:54:40 by mlermo-j          #+#    #+#             */
/*   Updated: 2026/05/05 12:54:41 by mlermo-j         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/**
 * @brief Prints the map grid to the standard output for debugging purposes.
 * @param game Pointer to the game structure containing the game information.
 */
void	debug_print_map(t_game *game)
{
	int	i;

	i = 0;
	ft_printf(1, "Map grid:\n");
	while (game->map.grid && game->map.grid[i])
	{
		ft_printf(1, "%s", game->map.grid[i]);
		i++;
	}
	ft_printf(1, "\n");
}

void	print_rgb_color(uint32_t color, char *label)
{
	uint8_t	r;
	uint8_t	g;
	uint8_t	b;

	r = (color >> 24) & 0xFF;
	g = (color >> 16) & 0xFF;
	b = (color >> 8) & 0xFF;
	ft_printf(1, "%s Color: %d, %d, %d\n", label, r, g, b);
}

/**
 * @brief Prints the floor and ceiling colors in hexadecimal format along with a
 * colored block representing the color for visual verification. The function
 * extracts the RGB components from the hexadecimal color value and uses ANSI
 * escape codes to print a colored block in the terminal.
 * @param game Pointer to the game structure containing the game information.
 */
void	debug_print_colors(t_game *game)
{
	print_rgb_color(game->map.floor_color, "Floor");
	print_rgb_color(game->map.ceiling_color, "Ceiling");
}
