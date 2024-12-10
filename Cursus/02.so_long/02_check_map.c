/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   02_check_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pperez-a <pperez-a@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 19:09:11 by pperez-a          #+#    #+#             */
/*   Updated: 2024/12/10 20:24:04 by pperez-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exit_codes.h"
#include "so_long.h"

void	is_enclosed(t_map *map)
{
	int	i;

	i = 0;
	while (i < map->cols - 1)
		if (map->map[0][i] != '1' || map->map[map->rows - 1][i++] != '1')
			error("Map is not enclosed!", 0, 1);
	i = 0;
	while (i < map->rows - 1)
		if (map->map[i][0] != '1' || map->map[i++][map->cols - 1] != '1')
			error("Map is not enclosed!", 0, 1);
	return ;
}

void	count_elements(t_map *map, t_player *player)
{
	int	i;
	int	j;

	i = 0;
	while (i < map->rows - 1)
	{
		j = 0;
		while (j < map->cols - 1)
		{
			if (map->map[i][j] == 'P')
			{
				map->player++;
				player->start_x = j;
				player->start_y = i;
			}
			if (map->map[i][j] == 'C')
				map->collects++;
			if (map->map[i][j++] == 'E')
				map->exit++;
		}
		i++;
	}
	ft_printf(1, "\033[33mPlayer coordinates: [%d, %d]\033[30m\n",
		player->start_x, player->start_y);
}

void	is_rectangle(t_map *map)
{
	int	i;

	i = 0;
	while (i < map->rows)
		if (map->map[i++][map->cols] != '\n')
			error("Map is not rectangular!", 0, 1);
}

void	get_dimensions(char *file, t_map *map)
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
	ft_printf(1, "\033[33mRows: %d\nColumns: %d\033[30m\n", map->rows,
		map->cols);
}

void	fill_map(char *file, t_map *map)
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
