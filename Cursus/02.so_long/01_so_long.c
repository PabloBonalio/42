/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   01_so_long.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pperez-a <pperez-a@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 17:16:33 by pperez-a          #+#    #+#             */
/*   Updated: 2024/12/03 16:45:53 by pperez-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	t_game	*game;

	game = malloc(sizeof(t_game));
	if (!game)
		return (free(game), 0);
	ft_bzero(game, sizeof(t_game));
	if (argc != 2)
		return (main_error("Wrong number of arguments!"));
	if (!check_map(argv[1]))
		return (main_error("Invalid map"));
	return (ft_printf("So far so long so good!\n"), 0);
}
