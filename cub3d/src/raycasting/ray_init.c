/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssoto-su <ssoto-su@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/02 21:27:09 by ssoto-su          #+#    #+#             */
/*   Updated: 2026/05/02 21:27:09 by ssoto-su         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/**
 * @brief Initializes the ray structure for a given screen column (x) by
 * calculating the ray's direction, initial map position, and the distances to
 * the next grid lines in both X and Y directions.
 * @param game Pointer to the game structure containing the game information.
 * @param ray Pointer to the ray structure to initialize.
 * @param x The X coordinate of the screen column for which to initialize the
 * ray.
 */
void	init_ray(t_game *game, t_ray *ray, int x)
{
	double	camera_x;

	camera_x = 2 * x / (double)S_WIDTH - 1;
	ray->dir.x = game->player.dir.x + game->player.plane.x * camera_x;
	ray->dir.y = game->player.dir.y + game->player.plane.y * camera_x;
	ray->map_x = (int)game->player.pos.x;
	ray->map_y = (int)game->player.pos.y;
	if (ray->dir.x == 0)
		ray->delta_dist.x = 1e30;
	else
		ray->delta_dist.x = fabs(1 / ray->dir.x);
	if (ray->dir.y == 0)
		ray->delta_dist.y = 1e30;
	else
		ray->delta_dist.y = fabs(1 / ray->dir.y);
	ray->hit = 0;
}

/**
 * @brief Calculates the step direction and initial side distances for the ray
 * based on the ray's direction.
 * @param game Pointer to the game structure containing the game information.
 * @param ray Pointer to the ray structure containing the ray's information.
 */
void	calculate_step(t_game *game, t_ray *ray)
{
	if (ray->dir.x < 0)
	{
		ray->step_x = -1;
		ray->side_dist.x = (game->player.pos.x - ray->map_x)
			* ray->delta_dist.x;
	}
	else
	{
		ray->step_x = 1;
		ray->side_dist.x = (ray->map_x + 1.0 - game->player.pos.x)
			* ray->delta_dist.x;
	}
	if (ray->dir.y < 0)
	{
		ray->step_y = -1;
		ray->side_dist.y = (game->player.pos.y - ray->map_y)
			* ray->delta_dist.y;
	}
	else
	{
		ray->step_y = 1;
		ray->side_dist.y = (ray->map_y + 1.0 - game->player.pos.y)
			* ray->delta_dist.y;
	}
}

/**
 * @brief Clears the background of the image by filling the ceiling and floor
 * with their respective colors.
 * @param game Pointer to the game structure containing the game information.
 */
void	clear_background(t_game *game)
{
	uint32_t	ceiling_color;
	uint32_t	floor_color;
	int			x;
	int			y;

	ceiling_color = game->map.ceiling_color;
	floor_color = game->map.floor_color;
	y = 0;
	while (y < S_HEIGHT)
	{
		x = 0;
		while (x < S_WIDTH)
		{
			if (y < S_HEIGHT / 2)
				mlx_put_pixel(game->img, x, y, ceiling_color);
			else
				mlx_put_pixel(game->img, x, y, floor_color);
			x++;
		}
		y++;
	}
}
