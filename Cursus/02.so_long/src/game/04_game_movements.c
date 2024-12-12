/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   04_game_movements.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pperez-a <pperez-a@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 15:57:14 by pperez-a          #+#    #+#             */
/*   Updated: 2024/12/12 17:25:37 by pperez-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../exit_codes.h"
#include "../../so_long.h"

void	move_up(t_game *game, t_map *map, t_player *player)
{
	int	next_tile;

	next_tile = map->map[game->pc.tile_y - 1][game->pc.tile_x];
	if (next_tile != '1')
	{
		if (next_tile == 'C' || next_tile == 'P' || next_tile == '0')
		{
			mlx_put_image_to_window(game->mlx, game->window, game->pc.img,
				game->pc.tile_x * TILE_SIZE, (game->pc.tile_y - 1) * TILE_SIZE);
			mlx_put_image_to_window(game->mlx, game->window, game->floor.img,
				game->pc.tile_x * TILE_SIZE, game->pc.tile_y * TILE_SIZE);
			map->map[game->pc.tile_y][game->pc.tile_x] = '0';
			if (next_tile == 'C')
				player->collects++;
			player->player_y--;
			game->pc.tile_y--;
		}
		if (next_tile == 'E' && (player->collects == map->collects))
			victory(game, map);
	}
}

void	move_down(t_game *game, t_map *map, t_player *player)
{
	int	next_tile;

	next_tile = map->map[game->pc.tile_y + 1][game->pc.tile_x];
	if (next_tile != '1')
	{
		if (next_tile == 'C' || next_tile == 'P' || next_tile == '0')
		{
			mlx_put_image_to_window(game->mlx, game->window, game->pc.img,
				game->pc.tile_x * TILE_SIZE, (game->pc.tile_y + 1) * TILE_SIZE);
			mlx_put_image_to_window(game->mlx, game->window, game->floor.img,
				game->pc.tile_x * TILE_SIZE, game->pc.tile_y * TILE_SIZE);
			map->map[game->pc.tile_y][game->pc.tile_x] = '0';
			if (next_tile == 'C')
				player->collects++;
			player->player_y++;
			game->pc.tile_y++;
		}
		if (next_tile == 'E' && (player->collects == map->collects))
			victory(game, map);
	}
}

void	move_left(t_game *game, t_map *map, t_player *player)
{
	int	next_tile;

	next_tile = map->map[game->pc.tile_y][game->pc.tile_x - 1];
	if (next_tile != '1')
	{
		if (next_tile == 'C' || next_tile == 'P' || next_tile == '0')
		{
			mlx_put_image_to_window(game->mlx, game->window, game->pc.img,
				(game->pc.tile_x - 1) * TILE_SIZE, game->pc.tile_y * TILE_SIZE);
			mlx_put_image_to_window(game->mlx, game->window, game->floor.img,
				game->pc.tile_x * TILE_SIZE, game->pc.tile_y * TILE_SIZE);
			map->map[game->pc.tile_y][game->pc.tile_x] = '0';
			if (next_tile == 'C')
				player->collects++;
			player->player_x--;
			game->pc.tile_x--;
		}
		if (next_tile == 'E' && (player->collects == map->collects))
			victory(game, map);
	}
}

void	move_right(t_game *game, t_map *map, t_player *player)
{
	int	next_tile;

	next_tile = map->map[game->pc.tile_y][game->pc.tile_x + 1];
	if (next_tile != '1')
	{
		if (next_tile == 'C' || next_tile == 'P' || next_tile == '0')
		{
			mlx_put_image_to_window(game->mlx, game->window, game->pc.img,
				(game->pc.tile_x + 1) * TILE_SIZE, game->pc.tile_y * TILE_SIZE);
			mlx_put_image_to_window(game->mlx, game->window, game->floor.img,
				game->pc.tile_x * TILE_SIZE, game->pc.tile_y * TILE_SIZE);
			map->map[game->pc.tile_y][game->pc.tile_x] = '0';
			if (next_tile == 'C')
				player->collects++;
			player->player_x++;
			game->pc.tile_x++;
		}
		if (next_tile == 'E' && (player->collects == map->collects))
			victory(game, map);
	}
}

int	key_input(int keycode, t_game *game, t_map *map, t_player *player)
{
	if (keycode == K_ESC)
		close_game(game, map);
	else if (keycode == K_W)
		move_up(game, map, player);
	else if (keycode == K_A)
		move_left(game, map, player);
	else if (keycode == K_S)
		move_down(game, map, player);
	else if (keycode == K_D)
		move_right(game, map, player);
	return (0);
}
