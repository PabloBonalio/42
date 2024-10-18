/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pperez-a <pperez-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 14:44:51 by pperez-a          #+#    #+#             */
/*   Updated: 2024/10/09 17:06:53 by pperez-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	char		*aux_dest;
	const char	*aux_src;

	aux_dest = (char *)dest;
	aux_src = (const char *)src;
	if (aux_dest == aux_src)
		return (dest);
	else if (dest > src)
	{
		aux_dest += n;
		aux_src += n;
		while (n)
		{
			aux_dest--;
			aux_src--;
			*aux_dest = *aux_src;
			n--;
		}
	}
	else
	{
		return (ft_memcpy(dest, src, n));
	}
	return (dest);
}
