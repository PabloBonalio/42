/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_drawing.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pperez-a <pperez-a@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 18:47:14 by pperez-a          #+#    #+#             */
/*   Updated: 2024/12/19 16:20:20 by pperez-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../exit_codes.h"
#include "../../so_long.h"

void	get_tiles(t_game *game, int x, int y)
{
	if (game->map.map[y][x] == '1')
		mlx_put_image_to_window(game->mlx, game->window, game->wall.img, x
			* TILE_SIZE, y * TILE_SIZE + OFFSET);
	else if (game->map.map[y][x] == '0')
		mlx_put_image_to_window(game->mlx, game->window, game->floor.img, x
			* TILE_SIZE, y * TILE_SIZE + OFFSET);
	else if (game->map.map[y][x] == 'E')
		mlx_put_image_to_window(game->mlx, game->window, game->exit.img, x
			* TILE_SIZE, y * TILE_SIZE + OFFSET);
	else if (game->map.map[y][x] == 'C')
		mlx_put_image_to_window(game->mlx, game->window, game->item.img, x
			* TILE_SIZE, y * TILE_SIZE + OFFSET);
	else if (game->map.map[y][x] == 'P')
		mlx_put_image_to_window(game->mlx, game->window, game->pc.img, x
			* TILE_SIZE, y * TILE_SIZE + OFFSET);
}

void	xpm_check(t_game *game)
{
	if (!game->pc.img || !game->item.img || !game->exit.img || !game->floor.img
		|| !game->wall.img)
	{
		img_destroyer(game);
		mlx_destroy_window(game->mlx, game->window);
		mlx_destroy_display(game->mlx);
		free(game->mlx);
		error("Could not load .xmp file", &game->map, 0, 1);
	}
}
static void	get_xpm_image(t_game *game)
{
	game->pc.img = mlx_xpm_file_to_image(game->mlx,
			"assets/textures/cat/cat_0.xpm", &game->pc.bits,
			&game->pc.size_line);
	game->item.img = mlx_xpm_file_to_image(game->mlx,
			"assets/textures/collects/mouse_0.xpm", &game->item.bits,
			&game->item.size_line);
	game->exit.img = mlx_xpm_file_to_image(game->mlx,
			"assets/textures/exit/exit_0.xpm", &game->exit.bits,
			&game->exit.size_line);
	game->floor.img = mlx_xpm_file_to_image(game->mlx,
			"assets/textures/floor/floor_0.xpm", &game->floor.bits,
			&game->floor.size_line);
	game->wall.img = mlx_xpm_file_to_image(game->mlx,
			"assets/textures/wall/wall_0.xpm", &game->wall.bits,
			&game->wall.size_line);
}

void	draw_map(t_game *game)
{
	int	x;
	int	y;

	x = -1;
	get_xpm_image(game);
	xpm_check(game);
	while (x++ < game->map.cols - 1)
	{
		y = -1;
		while (y++ < game->map.rows - 1)
			get_tiles(game, x, y);
	}
}
