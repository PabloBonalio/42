/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   03_check_map_aux.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pperez-a <pperez-a@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 16:56:02 by pperez-a          #+#    #+#             */
/*   Updated: 2024/12/03 16:56:43 by pperez-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	is_enclosed(char *map)
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
			return (0);
		j = 0;
		while ((i == 0 || j == 0 || j == len - 1) && map[i][j] != '\n')
			if (map[i][j++] != '1')
				return (0);
		i++;
	}
	while (len--)
		if (map[i][len] != '1')
			return (0);
	return (1);
}

static int	has_chars(char *map)
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
		return (0);
	return (1);
}

static int	is_rectangle(char *map)
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

static int	check_ber(char *map)
{
	char	*name_end;
	char	*ext;

	ext = ".ber";
	name_end = ft_substr(map, (ft_strlen(map) - 4), 4);
	if (ft_strncmp(name_end, ext, 4) != 0)
	{
		free(name_end);
		return (0);
	}
	free(name_end);
	return (1);
}
