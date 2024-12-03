/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   02_check_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pperez-a <pperez-a@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 19:09:11 by pperez-a          #+#    #+#             */
/*   Updated: 2024/12/03 17:01:59 by pperez-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_game	*map_init(char *map, t_game *game)
{
	read_map(map, game);
	if (game->map.lenline >= 3 && game->map.lencol >= 3)
	{
		game->map.map = malloc((game->map.lenline + 1) * (game->map.lencol + 1)
				+ 1);
		if (!game->map.map)
			return (0);
		game->map.map = fill_map(map, game, game->map.map);
	}
	else
		return (0);
	return (game);
}

int	check_map(char *map, t_game *game)
{
	if (!check_ber(map))
		return (error("Wrong file format, need .ber"));
	if (!map_init(map, game))
		return (free(game), error("No map specified"));
	if (!is_rectangle(game))
		return (error("Map is not rectangular!"));
	if (!has_chars(game))
		return (error("Map is missing elements!"));
	if (!is_enclosed(game))
		return (error("Map is not enclosed!"));
	return (ft_printf("Map is okay!"), 1);
}
