/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   choose_player.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pperez-a <pperez-a@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 17:14:35 by pperez-a          #+#    #+#             */
/*   Updated: 2024/12/19 19:52:40 by pperez-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../exit_codes.h"
#include "../../so_long.h"

#define KEY_UP 126
#define KEY_DOWN 125
#define KEY_ENTER 36
#define KEY_ESC 53

void	display_names(t_select_player *player)
{
	int	y;
	int	i;

	i = 0;
	y = 50;
	while (i < player->count)
	{
		mlx_string_put(player->mlx, player->window, 100, y, 0xFFFFFF,
			player->names[i]);
		y += 30;
		i++;
	}
}

int	key_hook(int keycode, t_select_player *player)
{
	if (keycode == KEY_ESC)
		exit(0);
	if (keycode == KEY_UP)
	{
		player->selected = (player->selected - 1 + player->count)
			% player->count;
	}
	else if (keycode == KEY_DOWN)
	{
		player->selected = (player->selected + 1) % player->count;
	}
	else if (keycode == KEY_ENTER)
	{
		printf("Selected: %s\n", player->names[player->selected]);
		// Process selection here
		return (0);
	}
	mlx_clear_window(player->mlx, player->window);
	display_names(player);
	return (0);
}

void	available_players(t_select_player *players)
{
	struct dirent	*entry;
	DIR				*dir;

	players->count = 0;
	players->names = malloc(sizeof(char **));
	dir = opendir("./assets/textures/players");
	if (!dir)
		error("Unable to open folder", 0, 0, 1);
	while ((entry = readdir(dir)) != NULL)
		if (entry->d_name[0] != '.')
			players->names[players->count++] = entry->d_name;
	closedir(dir);
}

void	choose_player(t_game *game)
{
	t_select_player	*players;

	players = ft_calloc(1, sizeof(t_select_player));
	ft_printf(1, "Count: %i\n", players->count);
	available_players(players);
	players->mlx = mlx_init();
	players->window = mlx_new_window(players->mlx, TILE_SIZE * 5, TILE_SIZE * 5,
			"Select Player");
	display_names(players);
	mlx_key_hook(game->window, key_hook, players);
	mlx_loop(players->mlx);
}
