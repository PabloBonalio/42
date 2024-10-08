/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pperez-a <pperez-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 22:08:37 by pperez-a          #+#    #+#             */
/*   Updated: 2024/06/12 22:51:55 by pperez-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_range(int min, int max)
{
	int	range;
	int	*str;
	int	i;
	int	j;

	i = min;
	range = max - min;
	if (min >= max)
		return (NULL);
	str = (int *)malloc(sizeof(int *) * (range));
	if (!str)
		return (NULL);
	while (i < max)
	{
		str[j] = i;
		i++;
		j++;
	}
	return (str);
}
