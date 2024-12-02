/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pperez-a <pperez-a@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 17:16:33 by pperez-a          #+#    #+#             */
/*   Updated: 2024/12/02 19:27:00 by pperez-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	free_map(char **map)
{
	int	i;

	i = 0;
	if (!map)
		return ;
	while (map[i])
		free(map[i++]);
	free(map);
}

int	main(int argc, char **argv)
{
	int		fd;
	int		i;
	char	**map;
	char	*line;

	i = 0;
	if (argc < 2)
		return (ft_printf("Error: Missing arguments!\n"), 1);
	if (argc > 3)
		return (ft_printf("Error: Too many arguments!\n"), 1);
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
		return (ft_printf("Cannot open map\n"), 1);
	map = (char **)malloc(1024);
	if (!map)
		return (close(fd), ft_printf("Error: Memory allocation failed\n"), 1);
	while ((line = get_next_line(fd)))
		map[i++] = line;
	map[i] = NULL;
	close(fd);
	if (!check_map(map))
		return (ft_printf("Error: Invalid map\n"), free_map(map), 1);
	return (ft_printf("So far so long so good!\n"), 0);
}
