/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pperez-a <pperez-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 11:53:58 by pperez-a          #+#    #+#             */
/*   Updated: 2024/10/08 11:53:59 by pperez-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char *ft_substr(char const *s, unsigned int start, size_t len)
{
	char *aux_str;
	size_t	aux_int;

	if (start >= ft_strlen(s))
	{
		aux_str = malloc(1);
		if (!aux_str)
			return (NULL);
		aux_str[0] = 0;
		return (aux_str);
	}

	aux_str = malloc(len + 1);
	if(!aux_str)
		return (NULL);

	aux_int = 0;
	while(aux_int < len && s[start] != '\0')
	{
		aux_str[aux_int] = s[start];
		aux_int++;
		start++;
	}
	aux_str[aux_int] = '\0';
	return (aux_str);
}
