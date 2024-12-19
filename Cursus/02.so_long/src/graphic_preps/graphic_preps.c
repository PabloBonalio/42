/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphic_preps.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pperez-a <pperez-a@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 16:36:56 by pperez-a          #+#    #+#             */
/*   Updated: 2024/12/19 17:17:08 by pperez-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../exit_codes.h"
#include "../../so_long.h"

void	graphic_preps(t_game *game)
{
	choose_player(game);
	draw_map(game);
	mlx_set_font(game->mlx, game->window,
		"-misc-fixed-bold-r-normal--20-200-75-75-c-100-iso8859-1");
	set_counter(game);
}
