/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pperez-a <pperez-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 14:45:58 by pperez-a          #+#    #+#             */
/*   Updated: 2024/10/09 15:46:38 by pperez-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	char		*aux_dest;
	const char	*aux_src;

	aux_dest = (char *)dest;
	aux_src = (const char *)src;
	if (!aux_src && !aux_dest)
		return (NULL);
	while (n--)
		*aux_dest++ = *aux_src++;
	return (dest);
}
