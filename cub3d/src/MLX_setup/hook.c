/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssoto-su <ssoto-su@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/02 21:17:26 by ssoto-su          #+#    #+#             */
/*   Updated: 2026/05/02 21:17:26 by ssoto-su         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/**
 * @brief Handles keyboard input events.
 * @param keydata The keyboard event data.
 * @param param Pointer to the game structure.
 */
void	key_handler(mlx_key_data_t keydata, void *param)
{
	t_game	*game;

	game = (t_game *)param;
	if (keydata.action == MLX_PRESS && keydata.key == MLX_KEY_ESCAPE)
		mlx_close_window(game->mlx);
}

/**
 * @brief Handles frame update events.
 * @param param Pointer to the game structure.
 * @note It is defined as void *param to match the expected function signature 
 * for mlx_loop_hook, and is cast to t_game * within the function to access 
 * game data.
 */
void	frame_handler(void *param)
{
	t_game	*game;
	t_ray	ray;
	int		x;

	game = (t_game *)param;
	x = 0;
	player_translations(game);
	player_rotation(game);
	clear_background(game);
	while (x < S_WIDTH)
	{
		init_ray(game, &ray, x);
		calculate_step(game, &ray);
		perform_dda(game, &ray);
		calculate_wall_height(&ray);
		draw_vertical_line(game, &ray, x);
		x++;
	}
}

/**
 * @brief Initializes the event hooks for the game.
 * @param game Pointer to the game structure containing the game information.
 */
void	init_hook(t_game *game)
{
	mlx_key_hook(game->mlx, &key_handler, game);
	mlx_loop_hook(game->mlx, &frame_handler, game);
}
