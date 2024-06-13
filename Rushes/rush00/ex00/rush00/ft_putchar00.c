/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pperez-a <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/26 19:47:25 by pperez-a          #+#    #+#             */
/*   Updated: 2024/05/26 19:47:38 by pperez-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write (1, &c, 1);
}

/*Function defines characters to use on each instance,
depending on the position we are in the matrix (x, y)*/
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
