/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   03_check_map_aux.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pperez-a <pperez-a@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 16:56:02 by pperez-a          #+#    #+#             */
/*   Updated: 2024/12/10 16:07:19 by pperez-a         ###   ########.fr       */
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
