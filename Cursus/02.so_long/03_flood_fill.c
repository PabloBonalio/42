/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   03_flood_fill.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pperez-a <pperez-a@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 18:47:14 by pperez-a          #+#    #+#             */
/*   Updated: 2024/12/10 20:20:14 by pperez-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exit_codes.h"
#include "so_long.h"

void	flood_fill(t_map *map, int x, int y)
{
	if (x < 0 || x >= map->cols - 1 || y < 0 || y >= map->rows - 1
		|| map->map[x][y] == '1')
		return ;
	map->map[x][y] = 'F';
	flood_fill(map, x + 1, y);
	flood_fill(map, x - 1, y);
	flood_fill(map, x, y + 1);
	flood_fill(map, x, y - 1);
}
