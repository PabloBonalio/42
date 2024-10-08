/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pperez-a <pperez-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 14:44:51 by pperez-a          #+#    #+#             */
/*   Updated: 2024/10/08 16:44:44 by pperez-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t		i;
	char		*aux_dest;
	const char	*aux_src;

	aux_dest = (char *)dest;
	aux_src = (const char *)src;
	if (aux_dest < aux_src)
	{
		i = 0;
		while (i < n)
		{
			aux_dest[i] = aux_src[i];
			i++;
		}
	}
	else
	{
		i = n;
		while (i > 0)
		{
			i--;
			aux_dest[i] = aux_src[i];
		}
	}
	return (dest);
}
