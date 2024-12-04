/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   01_so_long.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pperez-a <pperez-a@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 17:16:33 by pperez-a          #+#    #+#             */
/*   Updated: 2024/12/04 19:57:46 by pperez-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exit_codes.h"
#include "so_long.h"

int	main(int argc, char **argv)
{
	t_game	*game;

	if (argc != 2)
		error("Wrong number of arguments!", 0, 1);
	game = malloc(sizeof(t_game));
	if (!game)
		error("Failed to allocate memory for game", game, 3);
	ft_bzero(game, sizeof(t_game));
	check_map(argv[1], game);
	return (ft_printf(1, "So far so long so good!\n"), 0);
}
