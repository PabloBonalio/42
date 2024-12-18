/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pperez-a <pperez-a@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 18:10:55 by pperez-a          #+#    #+#             */
/*   Updated: 2024/12/18 19:11:46 by pperez-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "libft/libft.h"
# include "minilibx-linux/mlx.h"
# include "minilibx-linux/mlx_int.h"
# include <dirent.h>
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

# ifndef OFFSET
#  define OFFSET (3 * TILE_SIZE)
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

typedef struct s_map
{
	char			**map;
	int				rows;
	int				cols;
	int				x;
	int				y;
	int				collects;
	int				exit;
	int				player;
}					t_map;

typedef struct s_game
{
	struct s_map	map;
	struct s_tile	pc;
	struct s_tile	item;
	struct s_tile	exit;
	struct s_tile	floor;
	struct s_tile	wall;
	void			*mlx;
	void			*window;
	int				moves;
}					t_game;

void				check_ber(char *file);
void				check_map(char *file);
void				map_init(t_map *map, char *file);
void				error(char *message, t_map *map, int exit_code);
void				get_dimensions(char *file, t_map *map);
void				fill_map(char *file, t_map *map);
void				is_rectangle(t_map *map);
void				count_elements(t_map *map);
void				is_enclosed(t_map *map);
void				flood_fill(t_map *map, int x, int y);
void				reset_elements(t_map *map);
void				reset_map(t_map *map, char *file);
void				draw_map(t_game *game);
void				xpm_check(t_game *game);
int					key_input(int key, t_game *game);
void				img_destroyer(t_game *game);
int					update_counter(t_game *game);
void				victory(t_game *game);
void				game(char *file);
int					close_game(t_game *game);
void				free_map(t_map *map);

#endif
