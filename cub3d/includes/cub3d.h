/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlermo-j <mlermo-j@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/05 13:01:06 by mlermo-j          #+#    #+#             */
/*   Updated: 2026/05/05 13:16:14 by mlermo-j         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H
# include "cub3d_libs.h"

// src/free_tools.c N: 3/3
void			free_double_p(char **str);
void			free_map_data(t_game *game);
void			fperror(t_game *game, char *error_msg);

// src/initializer.c N: 3/3
t_map			init_map(void);
t_player		init_player(void);
t_game			init_game(t_game *game);

// src/main.c N: 1/2
// static int	init_and_parse(int argc, char **argv, t_game *game);
int				main(int argc, char **argv);

// src/debugger/debugger.c N: 3/3
void			print_cell(char val, char flood);
void			draw_colored_grid(t_game *game, char **map_copy);
void			debug_print_parsed_data(t_game *game);

// src/debugger/debugger_utils.c N: 3/3
void			debug_print_map(t_game *game);
void			print_rgb_color(uint32_t color, char *label);
void			debug_print_colors(t_game *game);

// src/parser/parser_dispatch.c N: 2/2
void			init_texture_handler(t_config_handler *handlers);
int				search_handler(char *line, t_game *game,
					t_config_handler handlers[7]);

// src/parser/parser_handlers.c N: 5/5
void			assign_error(char *path, int type);
int				recon_texture(char *key);
int				clean_texture(t_game *game, int coord,\
				char *clean_path, mlx_texture_t *tex);
int				parse_texture(char *line, char *key, t_game *game);
int				parse_color(char *line, char *key, t_game *game);

// src/parser/parser_handlers_utils.c N: 2/2
uint32_t		rgb_to_hex(char *str);
mlx_texture_t	*load_texture(char *path);

// src/parser/parser_main.c N: 4/4
int				process_file(char *str, t_game *game,
					t_config_handler handlers[7]);
int				open_file(char *filename);
void			clear_gnl(int fd);
int				read_file(char *filename, t_game *game);

// src/parser/parser_map.c N: 1/1
void			recon_map(char *str, t_game *game);

// src/parser/parser_utils.c N: 4/4
int				check_extension(char *filename);
void			print_file(char *str);
char			*skip_spaces(char *str);
void			format_helper(char *msg, char *found);

// src/parser/parser_verify.c N: 5/5
void			validate_map_cell(t_game *game, int row, int col);
int				fill(char **map_copy, t_game *game, int row, int col);
void			flood_fill_check(t_game *game, char **map_copy);
char			**copy_map(t_game *game);
void			validate_map(t_game *game);

// src/parser/parser_verify_utils.c N: 5/5
void			calculate_width_and_height(t_game *game);
int				rectangular_grid(t_game *game);
void			itermap(t_game *game, void (*func)(t_game *, int, int));
void			set_player_orientation(t_game *game, char cell);
void			check_player(t_game *game, char cell, int row, int col);

// src/MLX_setup/engine.c N: 1/1
t_game			*init_engine(t_game *game);

// src/MLX_setup/hook.c N: 3/3
void			key_handler(mlx_key_data_t keydata, void *param);
void			frame_handler(void *param);
void			init_hook(t_game *game);

// src/movement/player_move.c N: 2/4
// static void	move_player(t_game *game, double move_x, double move_y);
void			player_translations(t_game *game);
// static void	rotate_player(t_player *p, double cos_r, double sin_r);
void			player_rotation(t_game *game);

// src/raycasting/ray_dda.c N: 1/1
void			perform_dda(t_game *game, t_ray *ray);

// src/raycasting/ray_height.c N: 2/5
void			calculate_wall_height(t_ray *ray);
// static mlx_texture_t	*get_wall_texture(t_game *game, t_ray *ray);
// static int	get_tex_x(t_game *game, t_ray *r, mlx_texture_t *tex);
// static void	draw_tex_col(t_game *g, t_ray *r, mlx_texture_t *tex,
//					int *x_tx);
void			draw_vertical_line(t_game *game, t_ray *ray, int x);

// src/raycasting/ray_init.c N: 3/3
void			init_ray(t_game *game, t_ray *ray, int x);
void			calculate_step(t_game *game, t_ray *ray);
void			clear_background(t_game *game);

#endif
