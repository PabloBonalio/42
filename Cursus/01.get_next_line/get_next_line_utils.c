/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pperez-a <pperez-a@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 16:00:41 by pperez-a          #+#    #+#             */
/*   Updated: 2024/10/28 16:37:23 by pperez-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	*ft_calloc(size_t count, size_t size)
{
	void			*res;
	unsigned char	*position;
	size_t			total;

	if (size != 0 && count > SIZE_MAX / size)
		return (NULL);
	total = count * size;
	res = malloc(total);
	if (!res)
		return (NULL);
	position = (unsigned char *)res;
	while (total != 0)
	{
		*position = 0;
		position++;
		total--;
	}
	return (res);
}

char	*ft_strdup(const char *s1)
{
	char	*new_str;
	int		len;
	int		index;

	if (!s1)
		return (ft_strdup(""));
	len = 0;
	while (s1[len])
		len++;
	new_str = ft_calloc(len + 1, sizeof *new_str);
	if (!new_str)
		return (0);
	index = 0;
	while (s1[index])
	{
		new_str[index] = s1[index];
		index++;
	}
	return (new_str);
}

char	*ft_strjoin(const char *s1, const char *s2)
{
	char *s;
	int len;
	int i;

	len = 0;
	if (!s1 && !s2)
		return (0);
	while (s1 && s1[len])
		len++;
	i = 0;
	while (s2 && s2[i])
		i++;
	s = ft_calloc(len + i + 1, sizeof *s);
	if (!s)
		return (0);
	len = -1;
	while (s1 && s1[++len])
		s[len] = s1[len];
	i = -1;
	while (s2 && s2[++i])
		s[len + i] = s2[i];
	return (s);
}
