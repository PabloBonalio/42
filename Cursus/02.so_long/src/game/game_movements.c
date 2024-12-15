/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_movements.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pperez-a <pperez-a@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 15:57:14 by pperez-a          #+#    #+#             */
/*   Updated: 2024/12/15 19:54:20 by pperez-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../exit_codes.h"
#include "../../so_long.h"

void	move_up(t_game *game)
{
	int	next_tile;

	next_tile = game->map.map[game->map.y - 1][game->map.x];
	if (next_tile != '1')
	{
		if (next_tile == 'C' || next_tile == 'P' || next_tile == '0')
		{
			mlx_put_image_to_window(game->mlx, game->window, game->pc.img,
				game->map.x * TILE_SIZE, (game->map.y - 1) * TILE_SIZE);
			mlx_put_image_to_window(game->mlx, game->window, game->floor.img,
				game->map.x * TILE_SIZE, game->map.y * TILE_SIZE);
			game->map.map[game->map.y][game->map.x] = '0';
			if (next_tile == 'C')
				game->map.collects--;
			game->map.y--;
		}
		if (next_tile == 'E' && (!game->map.collects))
			victory(game);
	}
}

void	move_down(t_game *game)
{
	int	next_tile;

	next_tile = game->map.map[game->map.y + 1][game->map.x];
	if (next_tile != '1')
	{
		if (next_tile == 'C' || next_tile == 'P' || next_tile == '0')
		{
			mlx_put_image_to_window(game->mlx, game->window, game->pc.img,
				game->map.x * TILE_SIZE, (game->map.y + 1) * TILE_SIZE);
			mlx_put_image_to_window(game->mlx, game->window, game->floor.img,
				game->map.x * TILE_SIZE, game->map.y * TILE_SIZE);
			game->map.map[game->map.y][game->map.x] = '0';
			if (next_tile == 'C')
				game->map.collects--;
			game->map.y++;
		}
		if (next_tile == 'E' && (!game->map.collects))
			victory(game);
	}
}

void	move_left(t_game *game)
{
	int	next_tile;

	next_tile = game->map.map[game->map.y][game->map.x - 1];
	if (next_tile != '1')
	{
		if (next_tile == 'C' || next_tile == 'P' || next_tile == '0')
		{
			mlx_put_image_to_window(game->mlx, game->window, game->pc.img,
				(game->map.x - 1) * TILE_SIZE, (game->map.y) * TILE_SIZE);
			mlx_put_image_to_window(game->mlx, game->window, game->floor.img,
				game->map.x * TILE_SIZE, game->map.y * TILE_SIZE);
			game->map.map[game->map.y][game->map.x] = '0';
			if (next_tile == 'C')
				game->map.collects--;
			game->map.x--;
		}
		if (next_tile == 'E' && (!game->map.collects))
			victory(game);
	}
}

void	move_right(t_game *game)
{
	int	next_tile;

	next_tile = game->map.map[game->map.y][game->map.x + 1];
	if (next_tile != '1')
	{
		if (next_tile == 'C' || next_tile == 'P' || next_tile == '0')
		{
			mlx_put_image_to_window(game->mlx, game->window, game->pc.img,
				(game->map.x + 1)* TILE_SIZE, game->map.y * TILE_SIZE);
			mlx_put_image_to_window(game->mlx, game->window, game->floor.img,
				game->map.x * TILE_SIZE, game->map.y * TILE_SIZE);
			game->map.map[game->map.y][game->map.x] = '0';
			if (next_tile == 'C')
				game->map.collects--;
			game->map.x++;
		}
		if (next_tile == 'E' && (!game->map.collects))
			victory(game);
	}
}

int	key_input(int key, t_game *game)
{
	if (key == K_W || key == K_A || key == K_S || key == K_D)
		ft_printf(1, "Movements: %d\n", ++game->moves);
	if (key == K_ESC)
		close_game(game);
	else if (key == K_W)
		move_up(game);
	else if (key == K_A)
		move_left(game);
	else if (key == K_S)
		move_down(game);
	else if (key == K_D)
		move_right(game);
	ft_printf(1, "Position: [%d, %d]\n", game->map.y, game->map.x);
	return (0);
}
