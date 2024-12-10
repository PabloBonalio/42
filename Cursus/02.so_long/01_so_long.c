/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   01_so_long.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pperez-a <pperez-a@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 17:16:33 by pperez-a          #+#    #+#             */
/*   Updated: 2024/12/10 16:05:45 by pperez-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exit_codes.h"
#include "so_long.h"

static void	check_ber(char *file)
{
	char	*name_end;
	char	*ext;

	ext = ".ber";
	name_end = ft_substr(file, (ft_strlen(file) - 4), 4);
	if (ft_strlen(file) < 4 || ft_strncmp(name_end, ext, 4) != 0)
		error("Wrong file format, need .ber\n", name_end, 2);
	free(name_end);
}

static void	check_map(char *file, t_map *map, t_player *player)
{
	check_ber(file);
	map_init(file, map);
	is_rectangle(map);
	count_elements(map, player);
	if (map->player != 1 || map->collects < 1 || map->exit != 1)
		error("Wrong number of items", 0, 1);
	is_enclosed(map);
	ft_printf(1, "\033[32mMap is okay!\033[30m\n");
}

int	main(int argc, char **argv)
{
	t_game	*game;

	if (argc < 2)
		error("We are going to need a map mate!", 0, 1);
	game = malloc(sizeof(t_game));
	if (!game)
		error("Failed to allocate memory for the game", game, 3);
	ft_bzero(game, sizeof(t_game));
	check_map(argv[1], &game->map, &game->player);
	ft_printf(1, "\033[32;1;4mSo far so long so good!\033[0m\n");
	exit(0);
}
