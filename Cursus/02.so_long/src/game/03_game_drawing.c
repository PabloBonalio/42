/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   03_game_drawing.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pperez-a <pperez-a@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 18:47:14 by pperez-a          #+#    #+#             */
/*   Updated: 2024/12/12 17:36:13 by pperez-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../exit_codes.h"
#include "../../so_long.h"

void	img_destroyer(t_game *game)
{
	if (game->pc.img)
		mlx_destroy_image(game->mlx, game->pc.img);
	if (game->item.img)
		mlx_destroy_image(game->mlx, game->item.img);
	if (game->exit.img)
		mlx_destroy_image(game->mlx, game->exit.img);
	if (game->floor.img)
		mlx_destroy_image(game->mlx, game->floor.img);
	if (game->wall.img)
		mlx_destroy_image(game->mlx, game->wall.img);
}

int	get_xmp_address(t_game *game)
{
	game->pc.addr = mlx_get_data_addr(game->pc.img, &game->pc.bits,
			&game->pc.size_line, &game->pc.endian);
	game->item.addr = mlx_get_data_addr(game->item.img, &game->item.bits,
			&game->item.size_line, &game->item.endian);
	game->exit.addr = mlx_get_data_addr(game->exit.img, &game->exit.bits,
			&game->exit.size_line, &game->exit.endian);
	game->floor.addr = mlx_get_data_addr(game->floor.img, &game->floor.bits,
			&game->floor.size_line, &game->floor.endian);
	game->wall.addr = mlx_get_data_addr(game->wall.img, &game->wall.bits,
			&game->wall.size_line, &game->wall.endian);
	return (1);
}

t_game	*get_xmp_image(t_game *game)
{
	game->pc.img = mlx_xpm_file_to_image(game->mlx, "textures/P_player.xpm",
			&game->pc.bits, &game->pc.size_line);
	game->item.img = mlx_xpm_file_to_image(game->mlx, "textures/C_item.xpm",
			&game->item.bits, &game->item.size_line);
	game->exit.img = mlx_xpm_file_to_image(game->mlx,
			"textures/E_exit_closed.xpm", &game->exit.bits,
			&game->exit.size_line);
	game->floor.img = mlx_xpm_file_to_image(game->mlx, "textures/0_floor.xpm",
			&game->floor.bits, &game->floor.size_line);
	game->wall.img = mlx_xpm_file_to_image(game->mlx, "textures/1_wall.xpm",
			&game->wall.bits, &game->wall.size_line);
	if (!xpm_check(game))
		return (0);
	if (!get_xmp_address(game))
	{
		error("No se encontró la dirección de .xmp", game, 1);
		return (0);
	}
	return (game);
}

int	xpm_check(t_game *game)
{
	if (!game->pc.img || !game->item.img || !game->exit.img || !game->floor.img
		|| !game->wall.img)
	{
		img_destroyer(game);
		mlx_destroy_window(game->mlx, game->window);
		mlx_destroy_display(game->mlx);
		free(game->mlx);
		error("No se pudo cargar los archivo .xmp", game, 1);
		return (0);
	}
	return (1);
}

void	get_tiles(t_game *game, char **map, int x, int y)
{
	if (map[y][x] == '1')
		mlx_put_image_to_window(game->mlx, game->window, game->wall.img, x
			* TILE_SIZE, y * TILE_SIZE);
	else if (map[y][x] == '0')
		mlx_put_image_to_window(game->mlx, game->window, game->floor.img, x
			* TILE_SIZE, y * TILE_SIZE);
	else if (map[y][x] == 'E')
		mlx_put_image_to_window(game->mlx, game->window, game->exit.img, x
			* TILE_SIZE, y * TILE_SIZE);
	else if (map[y][x] == 'C')
		mlx_put_image_to_window(game->mlx, game->window, game->item.img, x
			* TILE_SIZE, y * TILE_SIZE);
	else if (map[y][x] == 'P')
	{
		mlx_put_image_to_window(game->mlx, game->window, game->pc.img, x
			* TILE_SIZE, y * TILE_SIZE);
		map[y][x] = '0';
	}
}
void	draw_map(t_map *map, t_game *game)
{
	int	x;
	int	y;

	x = -1;
	get_xmp_image(game);
	while (x++ < map->cols)
	{
		y = -1;
		while (y++ < map->rows)
			get_tiles(game, map->map, x, y);
	}
}
