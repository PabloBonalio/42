/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pperez-a <pperez-a@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 17:16:33 by pperez-a          #+#    #+#             */
/*   Updated: 2024/12/12 17:29:17 by pperez-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../exit_codes.h"
#include "../so_long.h"

static void	map_init(t_map *map, char *file)
{
	get_dimensions(file, map);
	map->map = malloc(sizeof(char *) * (map->rows));
	if (!map->map)
		error("Error: Memory allocation for map failed", map, 3);
	fill_map(file, map);
}

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

static void	check_map(t_player *player, char *file)
{
	t_map	*map;

	map = ft_calloc(1, sizeof(t_map));
	map_init(map, file);
	is_rectangle(map);
	ft_printf(1, "\n");
	count_elements(map, player);
	if (map->player != 1 || map->collects < 1 || map->exit != 1)
		error("Wrong number of items", 0, 1);
	is_enclosed(map);
	flood_fill(map, player->player_x, player->player_y);
	reset_elements(map);
	count_elements(map, player);
	if (map->player != 0 || map->collects != 0 || map->exit != 0)
		error("Looks like map doesn't have a solution...\n", 0, 1);
	free_map(map);
}

void	game(t_map *map)
{
	t_game	*game;

	game = ft_calloc(1, sizeof(t_game));
	game->mlx = mlx_init();
	game->img = mlx_new_image(game->mlx, map->cols * TILE_SIZE, map->rows
			* TILE_SIZE);
	game->window = mlx_new_window(game->mlx, map->cols * TILE_SIZE, map->rows
			* TILE_SIZE, "So_long by Bonalio");
	draw_map(map, game);
	// mlx_key_hook(game->window, key_input, game);
	mlx_hook(game->window, ClientMessage, LeaveWindowMask, close_game, game);
	mlx_loop(game->mlx);
}

int	main(int argc, char **argv)
{
	t_map		*map;
	t_player	*player;

	map = ft_calloc(1, sizeof(t_map));
	player = ft_calloc(1, sizeof(t_player));
	if (argc < 2)
		error("We are going to need a map mate!", 0, 1);
	check_ber(argv[1]);
	check_map(player, argv[1]);
	map_init(map, argv[1]);
	ft_printf(1, "\033[32;1;4mSo far so long so good!\033[0m\n");
	game(map);
	free_map(map);
	free(player);
	exit(0);
}
