/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_height.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssoto-su <ssoto-su@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/02 21:22:10 by ssoto-su          #+#    #+#             */
/*   Updated: 2026/05/12 16:22:55 by ssoto-su         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/**
 * @brief Calculates the height of the wall slice to draw based on the ray's
 * distance to the wall.
 * @param ray Pointer to the ray structure containing the ray's information.
 */
void	calculate_wall_height(t_ray *ray)
{
	if (ray->side == 0)
		ray->draw.perp_wall_dist = (ray->side_dist.x - ray->delta_dist.x);
	else
		ray->draw.perp_wall_dist = (ray->side_dist.y - ray->delta_dist.y);
	ray->draw.line_height = (int)(S_HEIGHT / ray->draw.perp_wall_dist);
	ray->draw.start = -ray->draw.line_height / 2 + S_HEIGHT / 2;
	if (ray->draw.start < 0)
		ray->draw.start = 0;
	ray->draw.end = ray->draw.line_height / 2 + S_HEIGHT / 2;
	if (ray->draw.end >= S_HEIGHT)
		ray->draw.end = S_HEIGHT - 1;
}

/**
 * @brief Draws a vertical line on the screen corresponding to the wall slice
 * hit by the ray, using the appropriate texture.
 * @param game Pointer to the game structure containing the game information.
 * @param ray Pointer to the ray structure containing the ray's information.
 */
static mlx_texture_t	*get_wall_texture(t_game *game, t_ray *ray)
{
	if (ray->side == 0)
	{
		if (ray->dir.x > 0)
			return (game->map.textures[EAST]);
		return (game->map.textures[WEST]);
	}
	else
	{
		if (ray->dir.y > 0)
			return (game->map.textures[SOUTH]);
		return (game->map.textures[NORTH]);
	}
}

/**
 * @brief Calculates the X coordinate on the texture to sample from based on 
 * where the ray hits the wall.
 * @param game Pointer to the game structure containing the game information.
 * @param r Pointer to the ray structure containing the ray's information.
 * @param tex Pointer to the texture structure containing the texture info.
 * @return The X coordinate on the texture to sample from.
 */
static int	get_tex_x(t_game *game, t_ray *r, mlx_texture_t *tex)
{
	double	wall_x;
	int		t_x;

	if (r->side == 0)
		wall_x = game->player.pos.y + r->draw.perp_wall_dist * r->dir.y;
	else
		wall_x = game->player.pos.x + r->draw.perp_wall_dist * r->dir.x;
	wall_x -= floor(wall_x);
	t_x = (int)(wall_x * (double)tex->width);
	if ((r->side == 0 && r->dir.x < 0) || (r->side == 1 && r->dir.y > 0))
		t_x = tex->width - t_x - 1;
	if (t_x < 0)
		t_x = 0;
	else if (t_x >= (int)tex->width)
		t_x = tex->width - 1;
	return (t_x);
}

/**
 * @brief Draws a vertical line on the screen corresponding to the wall slice
 * hit by the ray, using the appropriate texture.
 * @param game Pointer to the game structure containing the game information.
 * @param ray Pointer to the ray structure containing the ray's information.
 * @param x The X coordinate on the screen where the vertical line should be 
 * drawn.
 * @note x_tx[0] = x (screen), x_tx[1] = tex_x (texture)
 */
static void	draw_tex_col(t_game *g, t_ray *r, mlx_texture_t *tex, int *x_tx)
{
	double	step;
	double	t_pos;
	int		t_y;
	int		y;
	uint8_t	*px;

	step = 1.0 * tex->height / r->draw.line_height;
	t_pos = (r->draw.start - S_HEIGHT / 2.0
			+ r->draw.line_height / 2.0) * step;
	y = r->draw.start;
	while (y <= r->draw.end)
	{
		t_y = (int)t_pos;
		if (t_y < 0)
			t_y = 0;
		else if (t_y >= (int)tex->height)
			t_y = tex->height - 1;
		t_pos += step;
		px = &tex->pixels[(t_y * tex->width + x_tx[1]) * tex->bytes_per_pixel];
		mlx_put_pixel(g->img, x_tx[0], y++,
			(px[0] << 24) | (px[1] << 16) | (px[2] << 8) | px[3]);
	}
}

/**
 * @brief Draws a vertical line on the screen corresponding to the wall slice
 * hit by the ray, using the appropriate texture.
 * @param game Pointer to the game structure containing the game information.
 * @param ray Pointer to the ray structure containing the ray's information.
 * @param x The X coordinate on the screen where the vertical line should be 
 * drawn.
 */
void	draw_vertical_line(t_game *game, t_ray *ray, int x)
{
	mlx_texture_t	*tex;
	int				x_tx[2];

	tex = get_wall_texture(game, ray);
	x_tx[0] = x;
	x_tx[1] = get_tex_x(game, ray, tex);
	draw_tex_col(game, ray, tex, x_tx);
}
