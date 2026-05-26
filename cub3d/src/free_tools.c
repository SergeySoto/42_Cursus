/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_tools.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlermo-j <mlermo-j@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/05 12:54:20 by mlermo-j          #+#    #+#             */
/*   Updated: 2026/05/05 12:54:21 by mlermo-j         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/**
 * @brief Frees a double pointer (array of strings) by iterating through the
 * array and freeing each individual string, followed by freeing the array 
 * itself.
 * @param str The double pointer to free.
 */
void	free_double_p(char **str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
}

/**
 * @brief Frees all dynamically allocated resources associated with the map
 * data.
 * @param game Pointer to the game structure containing the game information,
 * including the map data to free.
 */
void	free_map_data(t_game *game)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		if (game->map.textures[i])
			mlx_delete_texture(game->map.textures[i]);
		i++;
	}
	if (game->map.grid)
		free_double_p(game->map.grid);
}

/**
 * @brief Prints an error message to the standard error output, frees all
 * allocated resources, and terminates the program. This function is used to
 * handle fatal errors that require cleanup before exiting.
 * @param game Pointer to the game structure containing the game information,
 * which will be used to free resources before exiting.
 * @param error_msg The error message to print.
 */
void	fperror(t_game *game, char *error_msg)
{
	ft_printf(2, "%sError: %s%s\n", RED, error_msg, RESET);
	free_map_data(game);
	if (game->mlx)
		mlx_terminate(game->mlx);
	exit(1);
}
