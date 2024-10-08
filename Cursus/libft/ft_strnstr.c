/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pperez-a <pperez-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 20:30:42 by pperez-a          #+#    #+#             */
/*   Updated: 2024/10/08 17:53:32 by pperez-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (!little || little[0] == 0)
		return ((char *)big);
	while (big[i] != 0 && i < len)
	{
		j = 0;
		if (big[i] == little[j])
		{
			while ((big[i + j] == little[j]) && (i + j) < len)
			{
				if (little[j + 1] == 0)
					return ((char *)(big + i));
				j++;
			}
		}
		i++;
	}
	return (NULL);
}
