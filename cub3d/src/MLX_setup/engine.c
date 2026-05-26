/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   engine.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssoto-su <ssoto-su@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/02 21:17:22 by ssoto-su          #+#    #+#             */
/*   Updated: 2026/05/02 21:17:22 by ssoto-su         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/**
 * @brief Initializes the game engine and sets up the necessary components.
 * @param game Pointer to the game structure containing the game information.
 * @return Pointer to the initialized game structure, or NULL on failure.
 */
t_game	*init_engine(t_game *game)
{
	game->mlx = mlx_init(S_WIDTH, S_HEIGHT, "Telecubbies!!!", false);
	if (!game->mlx)
	{
		ft_putendl_fd((char *)mlx_strerror(mlx_errno), 2);
		return (NULL);
	}
	game->img = mlx_new_image(game->mlx, S_WIDTH, S_HEIGHT);
	if (!game->img)
	{
		mlx_terminate(game->mlx);
		ft_putendl_fd((char *)mlx_strerror(mlx_errno), 2);
		return (NULL);
	}
	if (mlx_image_to_window(game->mlx, game->img, 0, 0) == -1)
	{
		mlx_terminate(game->mlx);
		ft_putendl_fd((char *)mlx_strerror(mlx_errno), 2);
		return (NULL);
	}
	return (game);
}
