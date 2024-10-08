/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pperez-a <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/26 20:34:48 by pperez-a          #+#    #+#             */
/*   Updated: 2024/05/26 20:34:52 by pperez-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write (1, &c, 1);
}

void	ft_print_line(int x, char start, char middle, char end)
{
	if (x > 0)
	{	
		ft_putchar(start);
		x--;
	}
	while (x > 1)
	{
		ft_putchar(middle);
		x--;
	}
	if (x > 0)
	{
		ft_putchar(end);
	}
	ft_putchar('\n');
}
