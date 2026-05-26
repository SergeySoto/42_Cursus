/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initializer.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlermo-j <mlermo-j@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/05 12:54:23 by mlermo-j          #+#    #+#             */
/*   Updated: 2026/05/05 12:54:24 by mlermo-j         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/**
 * @brief Initializes the map structure with default values, including setting
 * the file path to NULL, counter to 0, floor and ceiling colors to 0, and
 * initializing the textures array and grid pointer to NULL.
 * @return A fully initialized map structure with default values.
 */
t_map	init_map(void)
{
	t_map	map;

	map.filepath = NULL;
	map.counter = 0;
	map.floor_color = 0;
	map.ceiling_color = 0;
	ft_bzero(map.textures, sizeof(mlx_texture_t *) * 4);
	map.grid = NULL;
	map.width = 0;
	map.height = 0;
	return (map);
}

/**
 * @brief Initializes the player structure with default values, including
 * setting the position, direction, and camera plane vectors to (0, 0), and
 * setting the movement and rotation speeds to predefined values.
 * @return A fully initialized player structure with default values.
 */
t_player	init_player(void)
{
	t_player	player;

	player.pos.x = 0;
	player.pos.y = 0;
	player.dir.x = 0;
	player.dir.y = 0;
	player.plane.x = 0;
	player.plane.y = 0;
	player.move_speed = 0.03;
	player.rot_speed = 0.04;
	return (player);
}

/**
 * @brief Initializes the game structure by setting the MLX instance and image
 * pointers to NULL, initializing the map and player structures with their
 * respective initialization functions, and setting the player count to 0.
 * @param game Pointer to the game structure to initialize.
 * @return The initialized game structure with default values.
 */
t_game	init_game(t_game *game)
{
	game->mlx = NULL;
	game->img = NULL;
	game->map = init_map();
	game->player = init_player();
	game->player_count = 0;
	return (*game);
}
