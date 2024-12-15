/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_compose.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pperez-a <pperez-a@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/15 18:08:57 by pperez-a          #+#    #+#             */
/*   Updated: 2024/12/15 18:08:57 by pperez-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../exit_codes.h"
#include "../../so_long.h"

void	map_init(t_map *map, char *file)
{
	get_dimensions(file, map);
	map->map = malloc(sizeof(char *) * (map->rows));
	if (!map->map)
		error("Error: Memory allocation for map failed", map, 3);
	fill_map(file, map);
	count_elements(map);
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

void	free_map(t_map *map)
{
	int	i;

	i = 0;
	while (i < map->rows)
		free(map->map[i++]);
	free(map->map);
	free(map);
}

void	check_map(char *file)
{
	t_map	*map;

	map = ft_calloc(1, sizeof(t_map));
	map_init(map, file);
	if (map->player != 1 || map->collects < 1 || map->exit != 1)
		error("Wrong number of items", map, 1);
	is_rectangle(map);
	is_enclosed(map);
	flood_fill(map, map->x, map->y);
	reset_elements(map);
	count_elements(map);
	if (map->player != 0 || map->collects != 0 || map->exit != 0)
		error("Looks like map doesn't have a solution...\n", map, 1);
	free_map(map);
}