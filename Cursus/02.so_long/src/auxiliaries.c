/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   auxiliaries.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pperez-a <pperez-a@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 15:23:16 by pperez-a          #+#    #+#             */
/*   Updated: 2024/12/12 17:24:35 by pperez-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../exit_codes.h"
#include "../so_long.h"

void	error(char *message, void *to_free, int exit_code)
{
	ft_printf(2, "\033[31mError: %s\033[30m\n", message);
	if (to_free)
		free(to_free);
	exit(exit_code);
}

void	reset_elements(t_map *map)
{
	map->player = 0;
	map->collects = 0;
	map->exit = 0;
}

void	free_map(t_map *map)
{
	int	i;

	i = 0;
	while (i < map->rows)
		free(map->map[i++]);
	free(map->map);
	free(map);
}

void	flood_fill(t_map *map, int x, int y)
{
	if (x < 0 || x > map->cols || y < 0 || y > map->rows
		|| map->map[y][x] == '1' || map->map[y][x] == 'F')
		return ;
	map->map[y][x] = 'F';
	flood_fill(map, x + 1, y);
	flood_fill(map, x - 1, y);
	flood_fill(map, x, y + 1);
	flood_fill(map, x, y - 1);
}

void	victory(t_game *game, t_map *map)
{
	ft_printf(1, "VICTORY!\n");
	close_game(game, map);
}

int	close_game(t_game *game, t_map *map)
{
	img_destroyer(game);
	mlx_destroy_window(game->mlx, game->window);
	mlx_destroy_display(game->mlx);
	free(game->mlx);
	free_map(map);
	free(game);
	exit(EXIT_SUCCESS);
}
