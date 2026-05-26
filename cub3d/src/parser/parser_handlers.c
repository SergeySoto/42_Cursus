/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_handlers.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlermo-j <mlermo-j@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/05 12:53:56 by mlermo-j          #+#    #+#             */
/*   Updated: 2026/05/05 12:53:57 by mlermo-j         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/**
 * @brief Return error message based on the type of error encountered during 
 * texture parsing.
 * @param path The path that caused the error, if applicable.
 * @param type The type of error (e.g., NO_PATH, INVALID_PATH, INVALID_FORMAT).
 */
void	assign_error(char *path, int type)
{
	if (type == NO_PATH)
		format_helper("Error: Invalid texture path:", path);
	else if (type == INVALID_PATH)
		format_helper("Error: Texture file not found:", path);
	else if (type == INVALID_FORMAT)
		format_helper("Error: Failed to load PNG:", path);
	else
		perror("Error");
}

/**
 * @brief Maps the texture key (e.g., "NO", "SO", "WE", "EA") to a corresponding
 * integer code that can be used to index the texture array in the game
 * structure.
 * @param key The texture key to recognize.
 * @return An integer code corresponding to the texture key, or -1 if the key
 * is not recognized.
 */
int	recon_texture(char *key)
{
	if (ft_strncmp(key, "NO", 2) == 0)
		return (NORTH);
	if (ft_strncmp(key, "SO", 2) == 0)
		return (SOUTH);
	if (ft_strncmp(key, "WE", 2) == 0)
		return (WEST);
	if (ft_strncmp(key, "EA", 2) == 0)
		return (EAST);
	return (-1);
}

/**
 * @brief Helper function to assign a loaded texture to the game structure and
 * free the cleaned path string. This function is called after successfully 
 * loading a texture to update the game state.
 * @param game Pointer to the game structure containing the game information.
 * @param coord The coordinate index corresponding to the texture (e.g., NORTH,
 * SOUTH, WEST, EAST).
 * @param clean_path The cleaned path string that was used to load the texture.
 * @return 1 to indicate successful assignment of the texture.
 */
int	clean_texture(t_game *game, int coord, char *clean_path,
	mlx_texture_t *texture)
{
	game->map.textures[coord] = texture;
	free(clean_path);
	return (1);
}

/**
 * @brief Parses a texture configuration line from the configuration file,
 * extracting the texture path and loading the texture. The function checks for
 * duplicate definitions and handles errors appropriately.
 * @param line The line from the configuration file to parse.
 * @param key The expected key at the beginning of the line (e.g., "NO", "SO").
 * @param game Pointer to the game structure containing the game information.
 * @return 1 if the texture was successfully parsed and loaded, -1 if an error
 * occurred, or 0 if the line does not match the expected key.
 */
int	parse_texture(char *line, char *key, t_game *game)
{
	char			*clean_path;
	mlx_texture_t	*texture;
	int				coord;

	coord = recon_texture(key);
	if (coord == -1)
		return (-1);
	if (ft_strncmp(line, key, 2) == 0)
	{
		if (game->map.textures[coord] != NULL)
		{
			format_helper("Error: Duplicated texture definition:", line);
			return (-1);
		}
		line += 2;
		clean_path = ft_strtrim(line, " \n");
		texture = load_texture(clean_path);
		if (texture)
			return (clean_texture(game, coord, clean_path, texture));
		free(clean_path);
		return (-1);
	}
	return (0);
}

/**
 * @brief Parses a color configuration line from the configuration file,
 * extracting the RGB color values and converting them to a hexadecimal color
 * value. The function checks for duplicate definitions and handles errors
 * appropriately.
 * @param line The line from the configuration file to parse.
 * @param key The expected key at the beginning of the line (e.g., "F", "C").
 * @param game Pointer to the game structure containing the game information.
 * @return 1 if the color was successfully parsed and converted, -1 if an error
 * occurred, or 0 if the line does not match the expected key.
 */
int	parse_color(char *line, char *key, t_game *game)
{
	if (ft_strncmp(line, key, 1) == 0)
	{
		line += 1;
		if (ft_strncmp(key, "F", 1) == 0)
		{
			if (game->map.floor_color != 0)
			{
				format_helper("Error: Duplicated F color definition:", line);
				return (-1);
			}
			game->map.floor_color = rgb_to_hex(line);
		}
		else if (ft_strncmp(key, "C", 1) == 0)
		{
			if (game->map.ceiling_color != 0)
			{
				format_helper("Error: Duplicated C color definition:", line);
				return (-1);
			}
			game->map.ceiling_color = rgb_to_hex(line);
		}
		return (1);
	}
	return (0);
}
