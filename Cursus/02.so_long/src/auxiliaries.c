/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   auxiliaries.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pperez-a <pperez-a@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 15:23:16 by pperez-a          #+#    #+#             */
/*   Updated: 2024/12/16 17:42:06 by pperez-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../exit_codes.h"
#include "../so_long.h"

void	error(char *message, t_map *map, int exit_code)
{
	ft_printf(2, "\033[31mError: %s\033[30m\n", message);
	if (map)
		free_map(map);
	exit(exit_code);
}

void	img_destroyer(t_game *game)
{
	if (game->pc.img)
		mlx_destroy_image(game->mlx, game->pc.img);
	if (game->item.img)
		mlx_destroy_image(game->mlx, game->item.img);
	if (game->exit.img)
		mlx_destroy_image(game->mlx, game->exit.img);
	if (game->floor.img)
		mlx_destroy_image(game->mlx, game->floor.img);
	if (game->wall.img)
		mlx_destroy_image(game->mlx, game->wall.img);
}

void	reset_elements(t_map *map)
{
	map->player = 0;
	map->collects = 0;
	map->exit = 0;
}

void	victory(t_game *game)
{
	ft_printf(1, "VICTORY!\n");
	close_game(game);
}

void	check_ber(char *file)
{
	int	len;

	len = ft_strlen(file);
	if (len < 4 || file[len - 1] != 'r' || file[len - 2] != 'e' || file[len
		- 3] != 'b' || file[len - 4] != '.')
		error("Wrong file format, need .ber\n", 0, 2);
}
