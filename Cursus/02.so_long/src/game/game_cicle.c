/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_cicle.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pperez-a <pperez-a@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 17:41:09 by pperez-a          #+#    #+#             */
/*   Updated: 2024/12/16 19:16:04 by pperez-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../exit_codes.h"
#include "../../so_long.h"

int	update_counter(t_game *game)
{
	char	*moves_str;
	int		i;
	int		j;

	i = -1;
	while (i++ < 2)
	{
		j = -1;
		while (j++ < 2)
			mlx_put_image_to_window(game->mlx, game->window, game->floor.img,
				TILE_SIZE * i, TILE_SIZE * j);
	}
	moves_str = ft_itoa(game->moves);
	mlx_string_put(game->mlx, game->window, TILE_SIZE, TILE_SIZE, 0xFFF0FF,
		moves_str);
	return (free(moves_str), 0);
}

void	my_hooks(t_game *game)
{
	mlx_key_hook(game->window, key_input, game);
	// mlx_hook(game->window, KeyPress, KeyPressMask, update_counter, game);
	mlx_hook(game->window, ClientMessage, LeaveWindowMask, close_game, game);
}

int	close_game(t_game *game)
{
	img_destroyer(game);
	if (game->window)
		mlx_destroy_window(game->mlx, game->window);
	if (game->mlx)
		mlx_destroy_display(game->mlx);
	free(game->mlx);
	free_map(&game->map);
	exit(EXIT_SUCCESS);
}

void	game(char *file)
{
	t_game	*game;

	game = ft_calloc(1, sizeof(t_game));
	map_init(&game->map, file);
	game->mlx = mlx_init();
	game->window = mlx_new_window(game->mlx, game->map.cols * TILE_SIZE,
			(game->map.rows + 3) * TILE_SIZE, "So_long by Bonalio");
	draw_map(game);
	update_counter(game);
	my_hooks(game);
	mlx_loop(game->mlx);
}
