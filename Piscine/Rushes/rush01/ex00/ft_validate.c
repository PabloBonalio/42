/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_validate.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pperez-a <pperez-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/01 17:35:19 by pperez-a          #+#    #+#             */
/*   Updated: 2024/06/02 22:08:30 by pperez-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_validate(int *clues)
{
	int	i;
	int	sum;

	i = 0;
	while (i < 12)
	{
		if ((clues[i] + clues[i + 4] < 3) || (clues[i] + clues[i + 4] > 5))
		{
			write(1, "4error\n", 6);
			sum = clues[i] + clues[i + 4];
			write (1, &sum, 1);
			return ;
		}
		i++;
	}
}
