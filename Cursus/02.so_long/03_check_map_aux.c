/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   03_check_map_aux.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pperez-a <pperez-a@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 16:56:02 by pperez-a          #+#    #+#             */
/*   Updated: 2024/12/04 20:01:44 by pperez-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exit_codes.h"
#include "so_long.h"

void	is_enclosed(char **map)
{
	int	i;
	int	j;
	int	len;

	len = 0;
	while (map[0][len] && map[0][len] != '\n')
		len++;
	i = 0;
	while (map[i + 1])
	{
		if (map[i][0] != '1' || map[i][len - 1] != '1')
			error("Map is not enclosed!", 0, 1);
		j = 0;
		while ((i == 0 || j == 0 || j == len - 1) && map[i][j] != '\n')
			if (map[i][j++] != '1')
				error("Map is not enclosed!", 0, 1);
		i++;
	}
	while (len--)
		if (map[i][len] != '1')
			error("Map is not enclosed!", 0, 1);
	return ;
}

void	has_chars(t_map map)
{
	int	i;
	int	j;

	i = 0;
	while (map.map[i])
	{
		j = 0;
		while (map.map[i][j])
		{
			if (map.map[i][j] == 'P')
				map.player++;
			if (map.map[i][j] == 'C')
				map.collects++;
			if (map.map[i][j] == 'E')
				map.exit++;
			j++;
		}
		i++;
	}
	if (map.player != 1 || map.collects < 1 || map.exit != 1)
		error("Wrong number of items", 0, 1);
	return ;
}

void	is_rectangle(t_map map)
{
	int	i;

	i = 0;
	i++;
	while (i < map.rows - 1)
	{
		if (map.map[i][map.cols] != '\n')
			error("Map is not rectangular!", 0, 1);
		i++;
	}
	return ;
}

void	check_ber(char *file)
{
	char	*name_end;
	char	*ext;

	ext = ".ber";
	name_end = ft_substr(file, (ft_strlen(file) - 4), 4);
	if (ft_strlen(file) < 4 || ft_strncmp(name_end, ext, 4) != 0)
		error("Wrong file format, need .ber\n", name_end, 2);
	return ;
}
