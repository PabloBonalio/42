/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pperez-a <pperez-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 17:21:13 by pperez-a          #+#    #+#             */
/*   Updated: 2024/10/09 18:21:56 by pperez-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char	aux_char;

	aux_char = (char)c;
	while (*s)
	{
		if (*s == aux_char)
			return ((char *)s);
		s++;
	}
	if (aux_char == 0)
		return ((char *)s);
	return (NULL);
}
