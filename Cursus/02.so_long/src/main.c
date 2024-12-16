/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pperez-a <pperez-a@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 17:16:33 by pperez-a          #+#    #+#             */
/*   Updated: 2024/12/15 22:41:38 by pperez-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../exit_codes.h"
#include "../so_long.h"

void	update_counter(t_game *game)
{
	// Clear the counter area by redrawing the background
	mlx_put_image_to_window(game->mlx, game->window, game->floor.img, 0, 0);
	mlx_put_image_to_window(game->mlx, game->window, game->floor.img, TILE_SIZE, 0);
	mlx_put_image_to_window(game->mlx, game->window, game->floor.img, 2 * TILE_SIZE, 0);

	// Display the updated movement count
	char *moves_str;

	moves_str = ft_itoa(game->moves); // Convert moves to string
	mlx_string_put(game->mlx, game->window, TILE_SIZE / 2, TILE_SIZE / 2, 0xFFFFFF, moves_str);
	free(moves_str); // Free the allocated string after use
}

static void	check_ber(char *file)
{
	int len;

	len = ft_strlen(file);
	if (len < 4 || file[len - 1] != 'r' || file[len - 2] != 'e' || file[len - 3] != 'b' || file[len - 4] != '.')
		error("Wrong file format, need .ber\n", 0, 2);
}

void	game(char *file)
{
	t_game		*game;
	t_map		*map;

	game = ft_calloc(1, sizeof(t_game));
	map = ft_calloc(1, sizeof(t_map));
	map_init(map, file);
	game->map  = *map;
	game->mlx = mlx_init();
	game->img = mlx_new_image(game->mlx, map->cols * TILE_SIZE, map->rows
			* TILE_SIZE);
	game->window = mlx_new_window(game->mlx, map->cols * TILE_SIZE, (map->rows + 3)
			* TILE_SIZE, "So_long by Bonalio");
	draw_map(map, game);
	mlx_key_hook(game->window, key_input, game);
	mlx_hook(game->window, ClientMessage, LeaveWindowMask, close_game, game);
	mlx_loop(game->mlx);
}

int	main(int argc, char **argv)
{
	if (argc < 2)
		error("We are going to need a map mate!", 0, 1);
	check_ber(argv[1]);
	check_map(argv[1]);
	ft_printf(1, "\033[32;1;4mSo far so long so good!\033[0m\n");
	game(argv[1]);
}
