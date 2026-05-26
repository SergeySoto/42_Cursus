/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_dispatch.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlermo-j <mlermo-j@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/05 12:53:50 by mlermo-j          #+#    #+#             */
/*   Updated: 2026/05/05 12:53:51 by mlermo-j         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/**
 * @brief Initializes the texture handler with the corresponding keys and
 * functions.This allows for a clean and modular way to process different
 * configuration lines.
 */
void	init_texture_handler(t_config_handler *handlers)
{
	handlers[0].key = "NO";
	handlers[0].func = parse_texture;
	handlers[1].key = "SO";
	handlers[1].func = parse_texture;
	handlers[2].key = "WE";
	handlers[2].func = parse_texture;
	handlers[3].key = "EA";
	handlers[3].func = parse_texture;
	handlers[4].key = "F";
	handlers[4].func = parse_color;
	handlers[5].key = "C";
	handlers[5].func = parse_color;
	handlers[6].key = NULL;
	handlers[6].func = NULL;
}

/**
 * @brief Searches for the appropriate handler function based on the key found
 * at the beginning of the line. This function iterates through the handlers
 * and calls the corresponding function if a match is found.
 * @param line The line from the configuration file to process.
 * @param game Pointer to the game structure containing the game information.
 * @param handlers An array of configuration handlers to search through.
 * @return The result of the handler function if a match is found, or 0 if
 * no match is found.
 */
int	search_handler(char *line, t_game *game, t_config_handler handlers[7])
{
	int	i;

	i = 0;
	while (handlers[i].key)
	{
		if (ft_strncmp(line, handlers[i].key, ft_strlen(handlers[i].key)) == 0)
		{
			return (handlers[i].func(line, handlers[i].key, game));
		}
		i++;
	}
	return (0);
}
