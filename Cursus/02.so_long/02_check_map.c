/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   02_check_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pperez-a <pperez-a@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 19:09:11 by pperez-a          #+#    #+#             */
/*   Updated: 2024/12/10 13:34:58 by pperez-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	get_dimensions(char *file, t_map *map)
{
	char	*temp;
	int		fd;

	fd = open(file, O_RDONLY);
	if (fd < 0)
		error("Failed to open the map", 0, 1);
	temp = get_next_line(fd);
	map->cols = ft_strlen(temp) - 1;
	while (temp != NULL)
	{
		map->rows++;
		free(temp);
		temp = get_next_line(fd);
	}
	free(temp);
	close(fd);
	ft_printf(1, "\033[33mcols: %d and rows: %d\033[30m\n", map->cols,
		map->rows);
}

static void	fill_map(char *file, t_map *map)
{
	int	i;
	int	fd;

	i = 0;
	fd = open(file, O_RDONLY);
	if (fd < 0)
		error("Failed to open the map", 0, 1);
	while (i < map->rows)
		map->map[i++] = get_next_line(fd);
	close(fd);
}

void	map_init(char *file, t_map *map)
{
	get_dimensions(file, map);
	if (map->rows < 3 && map->cols < 3)
		error("Error: Map dimensions are too small", 0, 1);
	map->map = malloc(sizeof(char *) * (map->rows));
	if (!map->map)
		error("Error: Memory allocation for map failed", map->map, 3);
	fill_map(file, map);
}

/*void	map_init(char *file, t_map *map)
{
	int		fd;
	char	*temp;
	int		i;

	i = 0;
	map->rows = 0;
	fd = open(file, O_RDONLY);
	if (fd < 0)
		error("Failed to open the map", 0, 1);
	temp = get_next_line(fd);
	while (temp != NULL)
	{
		map->cols = ft_strlen(temp) - 1;
		map->rows++;
		temp = get_next_line(fd);
	}
	if (map->rows <= 3 && map->cols <= 3)
		error("Error: Map dimensions are too small", 0, 1);
	close(fd);
	map->map = malloc((map->rows + 1) * (map->cols + 1) + 1);
	if (!map->map)
		error("Error: Memory allocation for map failed", map->map, 3);
	fd = open(file, O_RDONLY);
	if (fd < 0)
		error("Failed to open the map", 0, 1);
	while (i < map->rows)
		map->map[i++] = get_next_line(fd);
	close(fd);
}*/
