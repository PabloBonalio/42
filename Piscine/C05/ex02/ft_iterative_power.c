/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pperez-a <pperez-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 16:38:24 by pperez-a          #+#    #+#             */
/*   Updated: 2024/06/10 16:50:07 by pperez-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_iterative_power(int nb, int power)
{
	int	i;

	i = nb;
	while (power > 0)
	{
		nb *= i;
		power--;
	}
	return (nb);
}
/*
int	main(void)
{
	int	nb;
	int	power;

	nb = 2;
	power = 4;
	printf("%d elevado a %d es %d", nb, power, ft_iterative_power(nb, power));
	return (0);
}
*/
