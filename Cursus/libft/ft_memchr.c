/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pperez-a <pperez-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 18:40:53 by pperez-a          #+#    #+#             */
/*   Updated: 2024/09/26 19:38:56 by pperez-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	aux_char;
	unsigned char	*aux_str;

	aux_char = (unsigned char)c;
	aux_str = (unsigned char *)s;
	i = 0;
	while (i < n)
	{
		if (aux_str[i] == aux_char)
			return (aux_str + i);
		i++;
	}
	return (NULL);
}
