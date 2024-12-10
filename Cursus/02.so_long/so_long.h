/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pperez-a <pperez-a@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 18:10:55 by pperez-a          #+#    #+#             */
/*   Updated: 2024/12/10 19:49:25 by pperez-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "libft/libft.h"
# include "minilibx-linux/mlx.h"

typedef struct s_tile
{
	int				tile_x;
	int				tile_y;
	char			*img;
	char			*addr;
	int				bits;
	int				size_line;
	int				endian;
}					t_tile;

typedef struct s_player
{
	char			*player;
	int				start_x;
	int				start_y;
	int				cont_moves;
	int				items;
}					t_player;

typedef struct s_map
{
	char			**map;
	int				rows;
	int				cols;
	int				map_x;
	int				map_y;
	int				collects;
	int				exit;
	int				player;
}					t_map;

typedef struct s_game
{
	struct s_player	player;
	struct s_tile	pc;
	struct s_tile	item;
	struct s_tile	exit;
	struct s_tile	wall;
	struct s_tile	floor;
	struct s_map	map;
	void			*mlx;
	void			*window;
	void			*img;
	char			*addr;
	int				window_x;
	int				window_y;
	int				bits;
	int				len;
	int				endian;
}					t_game;

void				error(char *message, void *to_free, int exit_code);
void				get_dimensions(char *file, t_map *map);
void				fill_map(char *file, t_map *map);
void				is_rectangle(t_map *map);
void				count_elements(t_map *map, t_player *player);
void				is_enclosed(t_map *map);
void				flood_fill(t_map *map, int x, int y);

#endif
