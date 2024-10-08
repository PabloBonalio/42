/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pperez-a <pperez-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 11:53:55 by pperez-a          #+#    #+#             */
/*   Updated: 2024/10/08 11:53:56 by pperez-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*aux_str;
	int		start;
	int		end;
	int		i;

	start = 0;
	while (s1[start] && ft_strchr(set, s1[start]))
		start++;
	end = ft_strlen(s1) - 1;
	while (end > start && ft_strchr(set, s1[end]))
		end--;
	aux_str = malloc(end - start + 2);
	if (!aux_str)
		return (NULL);
	i = 0;
	while (start <= end)
		aux_str[i++] = s1[start++];
	aux_str[i] = 0;
	return (aux_str);
}
