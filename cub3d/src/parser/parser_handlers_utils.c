/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_handlers_utils.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlermo-j <mlermo-j@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/05 12:53:53 by mlermo-j          #+#    #+#             */
/*   Updated: 2026/05/05 12:53:54 by mlermo-j         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/**
 * @brief Converts a string representing RGB color values (in the format 
 * "R,G,B"). into a single 32-bit hexadecimal color value.
 * @param str The string containing the RGB color values.
 * @return A 32-bit unsigned integer representing the color in hexadecimal 
 * format, or 0 if the input string is invalid.
 */
uint32_t	rgb_to_hex(char *str)
{
	char		**decimals;
	int			rgb[3];
	uint32_t	color;

	decimals = ft_split(str, ',');
	if (!decimals || !decimals[0] || !decimals[1] || !decimals[2])
	{
		if (decimals)
			free_double_p(decimals);
		return (0);
	}
	rgb[0] = ft_atoi(decimals[0]);
	rgb[1] = ft_atoi(decimals[1]);
	rgb[2] = ft_atoi(decimals[2]);
	color = (rgb[0] << 24) | (rgb[1] << 16) | (rgb[2] << 8) | 255;
	free_double_p(decimals);
	return (color);
}

/**
 * @brief Loads a texture from the specified file path, checking for errors
 * such as missing path, file not found, or invalid format. The function uses
 * the MLX library to load PNG textures and returns a pointer to the loaded
 * texture, or NULL if an error occurs.
 * @param path The file path of the texture to load.
 * @return A pointer to the loaded texture, or NULL if an error occurs.
 */
mlx_texture_t	*load_texture(char *path)
{
	int				fd;
	mlx_texture_t	*texture;

	if (!path || *path == '\0')
	{
		assign_error(path, NO_PATH);
		return (NULL);
	}
	fd = open(path, O_RDONLY);
	if (fd < 0)
	{
		assign_error(path, INVALID_PATH);
		return (NULL);
	}
	close(fd);
	texture = mlx_load_png(path);
	if (!texture)
		assign_error(path, INVALID_FORMAT);
	return (texture);
}
