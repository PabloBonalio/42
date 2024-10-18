/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pperez-a <pperez-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 18:27:41 by pperez-a          #+#    #+#             */
/*   Updated: 2024/10/10 15:29:25 by pperez-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const unsigned char	*aux_str1;
	const unsigned char	*aux_str2;

	aux_str1 = (const unsigned char *)s1;
	aux_str2 = (const unsigned char *)s2;
	while (n > 0)
	{
		if (*aux_str1 != *aux_str2)
			return (*aux_str1 - *aux_str2);
		aux_str1++;
		aux_str2++;
		n--;
	}
	return (0);
}
