/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pperez-a <pperez-a@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 19:09:11 by pperez-a          #+#    #+#             */
/*   Updated: 2024/12/02 20:40:37 by pperez-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	is_enclosed(char **map)
{
	int	i;
	int	j;
	int	len;

	len = 0;
	while (map[0][len])
		len++;
	i = 0;
	while (map[i])
	{
		if (map[i][0] != '1' || map[i][len - 1] != '1')
			return (0);
		j = 0;
		while ((i == 0 || !map[i + 1]) && map[i][j]) // Check top or bottom row
		{
			if (map[i][j] != '1')
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

static int	has_chars(char **map)
{
	int	i;
	int	p;
	int	c;
	int	e;

	i = 0;
	p = 0;
	c = 0;
	e = 0;
	while (map[i])
	{
		if (ft_strchr(map[i], 'P'))
			p++;
		if (ft_strchr(map[i], 'C'))
			c++;
		if (ft_strchr(map[i], 'E'))
			e++;
		i++;
	}
	if (p != 1 || c < 1 || e != 1)
		return (ft_printf("player: %i\ncollect: %i\nexit: %i\n", p, c, e), 0);
	return (ft_printf("player: %i\ncollect: %i\nexit: %i\n", p, c, e), 1);
}

static int	is_rectangle(char **map)
{
	int		i;
	size_t	length;

	length = 0;
	i = 0;
	length = ft_strlen(map[i]);
	i++;
	while (map[i])
	{
		if (length != ft_strlen(map[i]))
			return (0);
		i++;
	}
	return (1);
}

int	check_map(char **map)
{
	if (!is_rectangle(map))
		return (ft_printf("Map is not rectangular!\n"), 0);
	if (!has_chars(map))
		return (ft_printf("Map is missing elements!\n"), 0);
	if (!is_enclosed(map))
		return (ft_printf("Map is not enclosed!\n"), 0);
	return (ft_printf("Map is okay!\n"), 1);
}
