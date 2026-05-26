/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_structs.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlermo-j <mlermo-j@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/05 13:06:20 by mlermo-j          #+#    #+#             */
/*   Updated: 2026/05/05 13:07:58 by mlermo-j         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

typedef enum e_coord
{
	NORTH,
	SOUTH,
	EAST,
	WEST,
	FLOOR,
	CEIL,
}	t_coord;

typedef enum e_error
{
	NO_PATH,
	INVALID_PATH,
	INVALID_FORMAT,
}	t_error;

typedef struct s_vector
{
	double	x;
	double	y;
}	t_vector;

typedef struct s_player
{
	t_vector	pos;
	t_vector	dir;
	t_vector	plane;
	double		move_speed;
	double		rot_speed;
}	t_player;

typedef struct s_map
{
	char			*filepath;
	int				counter;
	uint32_t		floor_color;
	uint32_t		ceiling_color;
	mlx_texture_t	*textures[4];
	char			**grid;
	int				width;
	int				height;
}	t_map;

typedef struct s_game
{
	mlx_t		*mlx;
	mlx_image_t	*img;
	t_map		map;
	t_player	player;
	int			player_count;
}	t_game;

typedef struct s_draw
{
	double	perp_wall_dist;
	int		line_height;
	int		start;
	int		end;
}	t_draw;

typedef struct s_ray
{
	t_vector	dir;
	t_vector	side_dist;
	t_vector	delta_dist;
	int			map_x;
	int			map_y;
	int			step_x;
	int			step_y;
	int			hit;
	int			side;
	t_draw		draw;
}	t_ray;

typedef struct s_config_handler
{
	char	*key;
	int		(*func)(char *line, char *key, t_game *game);
}	t_config_handler;

typedef struct s_config_dir
{
	char	key;
	double	dir_x;
	double	dir_y;
	double	plane_x;
	double	plane_y;
}	t_config_dir;
