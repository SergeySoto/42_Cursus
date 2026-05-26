/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlermo-j <mlermo-j@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/05 12:54:02 by mlermo-j          #+#    #+#             */
/*   Updated: 2026/05/05 12:54:03 by mlermo-j         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/**
 * @brief Reconstructs the map grid by adding a new line to the existing grid.
 * @param str The new line to add to the map grid.
 * @param game Pointer to the game structure containing the game information.
 * @note malloc uses i + 2 because we need space for the new line and the NULL.
 */
void	recon_map(char *str, t_game *game)
{
	int		i;
	int		j;
	char	**new_grid;

	i = 0;
	while (game->map.grid && game->map.grid[i])
		i++;
	new_grid = malloc(sizeof(char *) * (i + 2));
	if (!new_grid)
		return ;
	j = 0;
	while (j < i)
	{
		new_grid[j] = game->map.grid[j];
		j++;
	}
	new_grid[i] = ft_strdup(str);
	new_grid[i + 1] = NULL;
	if (game->map.grid)
		free(game->map.grid);
	game->map.grid = new_grid;
}
