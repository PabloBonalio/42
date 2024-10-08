/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pperez-a <pperez-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 18:10:03 by pperez-a          #+#    #+#             */
/*   Updated: 2024/10/08 15:30:02 by pperez-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	len;
	size_t	counter;

	len = ft_strlen(src);
	counter = 0;
	if (size != 0)
	{
		while (src[counter] && counter < size - 1)
		{
			dst[counter] = src[counter];
			counter++;
		}
		dst[counter] = 0;
	}
	return (len);
}
