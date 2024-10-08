/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pperez-a <pperez-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 15:21:12 by pperez-a          #+#    #+#             */
/*   Updated: 2024/06/13 15:29:33 by pperez-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_iterative_factorial(int nb)
{
	int	i;

	i = nb;
	if (nb < 0)
		return (0);
	if (nb == 0)
		return (1);
	while (i > 1)
	{
		nb *= (i - 1);
		i--;
	}
	return (nb);
}
/*
int	main(void)
{
	int	n;

	n = 42;
	printf("resultado es %d", ft_iterative_factorial(n));
	return (0);
}
*/
