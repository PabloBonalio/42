/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursive_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pperez-a <pperez-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 17:20:53 by pperez-a          #+#    #+#             */
/*   Updated: 2024/06/10 18:11:39 by pperez-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_recursive_power(int nb, int power)
{
	if (power > 1)
		nb *= ft_recursive_power(nb, power - 1);
	return (nb);
}
/*
int	main(void)
{
	int	nb;
	int	power;

	nb = 2;
	power = 8;
	printf("%d elevado a %d es %d", nb, power, ft_recursive_power(nb, power));
	return (0);
}
*/
