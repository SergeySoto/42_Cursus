/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlermo-j <mlermo-j@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/05 12:53:45 by mlermo-j          #+#    #+#             */
/*   Updated: 2026/05/05 12:58:03 by mlermo-j         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	init_and_parse(int argc, char **argv, t_game *game)
{
	if (argc != 2)
	{
		ft_printf(2, "Error: Invalid number of arguments\n");
		ft_printf(2, "Usage: ./cub3d <map_file.cub>\n");
		return (1);
	}
	if (check_extension(argv[1]))
	{
		ft_printf(2, "Error: Invalid file extension (expected .cub)\n");
		return (1);
	}
	init_game(game);
	if (read_file(argv[1], game) == 1)
		return (1);
	validate_map(game);
	debug_print_parsed_data(game);
	return (0);
}

int	main(int argc, char **argv)
{
	t_game	*game;

	game = malloc(sizeof(t_game));
	if (!game)
		return (1);
	ft_bzero(game, sizeof(t_game));
	if (init_and_parse(argc, argv, game))
	{
		free(game);
		return (1);
	}
	game = init_engine(game);
	if (!game)
		return (1);
	init_hook(game);
	mlx_loop(game->mlx);
	mlx_terminate(game->mlx);
	free_map_data(game);
	free(game);
	return (0);
}
