/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   01_so_long.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pperez-a <pperez-a@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 17:16:33 by pperez-a          #+#    #+#             */
/*   Updated: 2024/12/10 13:25:08 by pperez-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exit_codes.h"
#include "so_long.h"

void	check_map(char *file, t_game *game)
{
	check_ber(file);
	map_init(file, &game->map);
	is_rectangle(&game->map);
	has_chars(&game->map);
	is_enclosed(&game->map);
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
	check_map(argv[1], game);
	ft_printf(1, "\033[32;1;4mSo far so long so good!\033[0m\n");
	exit(0);
}
