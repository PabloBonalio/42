/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   02_check_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pperez-a <pperez-a@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 19:09:11 by pperez-a          #+#    #+#             */
/*   Updated: 2024/12/05 20:17:33 by pperez-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	get_dimensions(char *file, t_map *map)
{
	char	*temp;
	int		i;
	int		j;
	int		fd;

	i = 0;
	j = 0;
	fd = open(file, O_RDONLY);
	if (fd < 0)
		error("Failed to open the map", 0, 1);
	temp = get_next_line(fd);
	while (temp != NULL)
	{
		if (!i)
			i = ft_strlen(temp);
		j++;
		free(temp);
		temp = get_next_line(fd);
	}
	map->cols = i - 1;
	map->rows = j;
	close(fd);
}

static void	fill_map(char *file, t_map *map)
{
	int		i;
	int		fd;

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
	map->map = malloc((map->rows + 1) * (map->cols + 1) + 1);
	if (!map->map)
		error("Error: Memory allocation for map failed", map->map, 3);
	fill_map(file, map);
	return ;
}

void	check_map(char *file, t_game *game)
{
	check_ber(file);
	map_init(file, &game->map);
	is_rectangle(&game->map);
	has_chars(&game->map);
	is_enclosed(&game->map);
	ft_printf(1, "\033[32mMap is okay!\033[30m\n", 1);
}
