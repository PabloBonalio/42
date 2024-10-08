/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fibonacci.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pperez-a <pperez-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 18:12:18 by pperez-a          #+#    #+#             */
/*   Updated: 2024/06/10 19:35:34 by pperez-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_fibonacci(int index)
{
	if (index < 0)
		return (-1);
	if (index > 1)
		index = ft_fibonacci(index - 2) + ft_fibonacci(index - 1);
	return (index);
}
/*
int	main(void)
{
	printf("result is %d", ft_fibonacci(8));
	return (0);
}
*/
