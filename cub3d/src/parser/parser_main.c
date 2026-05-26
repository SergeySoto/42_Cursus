/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_main.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlermo-j <mlermo-j@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/05 12:53:59 by mlermo-j          #+#    #+#             */
/*   Updated: 2026/05/05 12:54:00 by mlermo-j         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/**
 * @brief Processes a single line from the configuration file, determining
 * whether it is a configuration line (e.g., texture or color definition) or
 * part of the map data. The function uses the provided handlers to parse
 * configuration lines and validates the format of the configuration data.
 * @param str The line from the configuration file to process.
 * @param game Pointer to the game structure containing the game information.
 * @param handlers An array of configuration handlers to use for parsing.
 * @return 1 if the line was successfully processed, -1 if an error occurred,
 * or 0 if the line is empty or does not match any handler.
 */
int	process_file(char *str, t_game *game, t_config_handler handlers[7])
{
	int		status;
	char	*trimmed_str;

	trimmed_str = skip_spaces(str);
	if (trimmed_str[0] == '\0' || trimmed_str[0] == '\n')
		return (0);
	status = search_handler(trimmed_str, game, handlers);
	if (status == 1)
	{
		game->map.counter++;
		return (1);
	}
	if (status == -1)
		return (-1);
	if (game->map.counter < 6)
	{
		format_helper("Error: Invalid configuration format", NULL);
		return (-1);
	}
	recon_map(str, game);
	return (1);
}

/**
 * @brief Opens the specified file for reading and returns the file descriptor.
 * @param filename The name of the file to open.
 * @return The file descriptor if the file was successfully opened, or -1 if an
 * error occurred.
 */
int	open_file(char *filename)
{
	int	fd;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
	{
		perror("Error: Could not open file");
		return (-1);
	}
	return (fd);
}

void	clear_gnl(int fd)
{
	char	*line;

	line = get_next_line(fd);
	while (line)
	{
		free(line);
		line = get_next_line(fd);
	}
}

/**
 * @brief Reads the configuration file line by line, processing each line using
 * the process_file function. The function handles errors appropriately,
 * ensuring that resources are freed and the file is closed in case of an error.
 * @param filename The name of the file to read.
 * @param game Pointer to the game structure containing the game information.
 * @return 0 if the file was successfully read and processed, or 1 if an error
 * occurred.
 */
int	read_file(char *filename, t_game *game)
{
	int					fd;
	char				*res;
	t_config_handler	handlers[7];

	init_texture_handler(handlers);
	fd = open_file(filename);
	if (fd < 0)
		return (1);
	res = get_next_line(fd);
	while (res)
	{
		if (process_file(res, game, handlers) == -1)
		{
			free(res);
			clear_gnl(fd);
			close(fd);
			free_map_data(game);
			return (1);
		}
		free(res);
		res = get_next_line(fd);
	}
	close(fd);
	return (0);
}
