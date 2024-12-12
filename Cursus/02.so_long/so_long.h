/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pperez-a <pperez-a@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 18:10:55 by pperez-a          #+#    #+#             */
/*   Updated: 2024/12/12 17:17:33 by pperez-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "libft/libft.h"
# include "minilibx-linux/mlx.h"
# include "minilibx-linux/mlx_int.h"
# include <errno.h>
# include <fcntl.h>
# include <stdlib.h>
# include <string.h>
# include <sys/stat.h>
# include <sys/types.h>
# include <unistd.h>

# ifndef WIN_HEIGHT
#  define WIN_HEIGHT 2048
# endif

# ifndef WIN_WIDTH
#  define WIN_WIDTH 2048
# endif

# ifndef TILE_SIZE
#  define TILE_SIZE 64
# endif

# define K_ESC 65307
# define K_A 97
# define K_D 100
# define K_S 115
# define K_W 119

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
	int				player_x;
	int				player_y;
	int				count_moves;
	int				collects;
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
	struct s_tile	pc;
	struct s_tile	item;
	struct s_tile	exit;
	struct s_tile	wall;
	struct s_tile	floor;
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
void				reset_elements(t_map *map);
void				reset_map(t_map *map, char *file, t_player *player);
void				draw_map(t_map *map, t_game *game);
int					key_input(int keycode, t_game *game, t_map *map,
						t_player *player);
void				img_destroyer(t_game *game);
void				victory(t_game *game, t_map *map);
int					close_game(t_game *game, t_map *map);
void				free_map(t_map *map);

#endif
