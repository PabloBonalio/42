/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush03.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rocihern <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/25 18:34:46 by rocihern          #+#    #+#             */
/*   Updated: 2024/05/26 18:48:28 by rocihern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

void	rush(int x, int y)
{
	int	r;
	int	c;

	r = 0;
	while (r < y)
	{
		c = 0;
		while (c < x)
		{
			if ((r == 0 && c == 0) || (r == y - 1 && c == 0))
				ft_putchar('A');
			else if ((r == 0 && c == x - 1) || (r == y - 1 && c == x - 1))
				ft_putchar('C');
			else if ((r == 0 || r == y - 1 || c == 0 || c == x - 1))
				ft_putchar('B');
			else
				ft_putchar(' ');
			c++;
		}
		ft_putchar('\n');
		r++;
	}
}
