/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlermo-j <mlermo-j@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/05 12:54:05 by mlermo-j          #+#    #+#             */
/*   Updated: 2026/05/05 12:54:06 by mlermo-j         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/**
 * @brief Checks if the given filename has the correct ".cub" extension.
 * @param filename The name of the file to check.
 * @return 0 if the extension is correct, non-zero otherwise.
 * @note The function looks for the last occurrence of '.' in the filename and
 * compares the substring starting from that point with the expected extension.
 */
int	check_extension(char *filename)
{
	while (*filename && *filename != '.')
		filename++;
	return (ft_strncmp(filename, ".cub", 4));
}

/**
 * @brief Prints the contents of a string to the standard output.
 * @param str The string to print.
 */
void	print_file(char *str)
{
	while (*str)
		ft_printf(2, "%c", *str++);
}

/**
 * @brief Skips leading spaces in a string.
 * @param str The string to process.
 * @return A pointer to the first non-space character in the string.
 */
char	*skip_spaces(char *str)
{
	while (*str == ' ')
		str++;
	return (str);
}

/**
 * @brief Formats and prints an error message with the expected format.
 * @param msg The error message to print.
 * @param found The found value to include in the error message.
 */
void	format_helper(char *msg, char *found)
{
	if (found)
		ft_printf(2, "%s%s %s%s\n", RED, msg, found, RESET);
	else
		ft_printf(2, "%s%s%s\n", RED, msg, RESET);
	ft_printf(2, "Expected format:\n");
	ft_printf(2, "NO path.png\nSO path.png\nWE path.png\nEA path.png\n");
	ft_printf(2, "F R,G,B\nC R,G,B\n");
	ft_printf(2, "\nMap data\n");
}
