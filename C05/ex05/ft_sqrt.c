/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pperez-a <pperez-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 19:35:52 by pperez-a          #+#    #+#             */
/*   Updated: 2024/06/12 21:09:11 by pperez-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_sqrt(int nb)
{
	int	i;
	int	j;

	i = 1;
	j = 0;
	while (nb > 0)
	{
		nb = nb - i;
		i += 2;
		j++;
	}
	if (nb == 0)
		return (j);
	else
		return (0);
}
/*
int	main(int argc, char **argv)
{
	int	nb;

	nb = 144;
	printf("raiz cuadrada de %d es %d", nb, ft_sqrt(nb));
	return (0);
}
*/
