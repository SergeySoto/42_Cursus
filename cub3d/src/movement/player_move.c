/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_move.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssoto-su <ssoto-su@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/02 21:20:54 by ssoto-su          #+#    #+#             */
/*   Updated: 2026/05/02 21:20:54 by ssoto-su         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/**
 * @brief Moves the player in the game world based on the provided movement
 * vector (move_x, move_y). The function checks for collisions with walls in
 * the map grid before updating the player's position to ensure that the player
 * does not move through walls.
 * @param game Pointer to the game structure containing the game information.
 * @param move_x The movement vector in the X direction, calculated based on
 * the player's direction and movement speed.
 * @param move_y The movement vector in the Y direction, calculated based on
 * the player's direction and movement speed.
 */
static void	move_player(t_game *game, double move_x, double move_y)
{
	double	new_x;
	double	new_y;

	new_x = game->player.pos.x + move_x;
	new_y = game->player.pos.y + move_y;
	if (game->map.grid[(int)game->player.pos.y][(int)new_x] != '1')
		game->player.pos.x = new_x;
	if (game->map.grid[(int)new_y][(int)game->player.pos.x] != '1')
		game->player.pos.y = new_y;
}

/**
 * @brief Handles the translation movements of the player based on keyboard
 * input.
 * @param game Pointer to the game structure containing the game information.
 */
void	player_translations(t_game *game)
{
	if (mlx_is_key_down(game->mlx, MLX_KEY_W))
		move_player(game,
			game->player.dir.x * game->player.move_speed,
			game->player.dir.y * game->player.move_speed);
	if (mlx_is_key_down(game->mlx, MLX_KEY_S))
		move_player(game,
			-game->player.dir.x * game->player.move_speed,
			-game->player.dir.y * game->player.move_speed);
	if (mlx_is_key_down(game->mlx, MLX_KEY_A))
		move_player(game,
			-game->player.plane.x * game->player.move_speed,
			-game->player.plane.y * game->player.move_speed);
	if (mlx_is_key_down(game->mlx, MLX_KEY_D))
		move_player(game,
			game->player.plane.x * game->player.move_speed,
			game->player.plane.y * game->player.move_speed);
}

/**
 * @brief Rotates the player in the game world based on the provided rotation
 * values.
 * @param p Pointer to the player structure containing the player's information.
 * @param cos_r The cosine of the rotation angle.
 * @param sin_r The sine of the rotation angle.
 */
static void	rotate_player(t_player *p, double cos_r, double sin_r)
{
	double	old_dir_x;
	double	old_plane_x;

	old_dir_x = p->dir.x;
	old_plane_x = p->plane.x;
	p->dir.x = p->dir.x * cos_r - p->dir.y * sin_r;
	p->dir.y = old_dir_x * sin_r + p->dir.y * cos_r;
	p->plane.x = p->plane.x * cos_r - p->plane.y * sin_r;
	p->plane.y = old_plane_x * sin_r + p->plane.y * cos_r;
}

/**
 * @brief Handles the rotation movements of the player based on keyboard input.
 * @param game Pointer to the game structure containing the game information.
 */
void	player_rotation(t_game *game)
{
	double	cos_r;
	double	sin_r;

	cos_r = cos(game->player.rot_speed);
	sin_r = sin(game->player.rot_speed);
	if (mlx_is_key_down(game->mlx, MLX_KEY_LEFT))
		rotate_player(&game->player, cos_r, -sin_r);
	if (mlx_is_key_down(game->mlx, MLX_KEY_RIGHT))
		rotate_player(&game->player, cos_r, sin_r);
}
