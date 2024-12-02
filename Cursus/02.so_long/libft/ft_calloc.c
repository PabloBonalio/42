/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pperez-a <pperez-a@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 21:28:54 by pperez-a          #+#    #+#             */
/*   Updated: 2024/10/30 15:44:30 by pperez-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*mem;

	if (nmemb == 0 || size == 0 || nmemb > SIZE_MAX / size)
		return (NULL);
	mem = (void *)malloc(nmemb * size);
	if (!mem)
		return (NULL);
	ft_bzero(mem, size * nmemb);
	return (mem);
}
